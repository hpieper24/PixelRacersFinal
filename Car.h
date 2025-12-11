//================================================================
// Car.h
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Base Car Class
// Description: Base Car class with PlayerCar and AiCar subclasses
//================================================================

#ifndef SRC_CAR_H_
#define SRC_CAR_H_

#include "SDL_Plotter.h"
#include "Const.h"
#include <vector>

class Obstacle;  // Forward declaration

// BASE CAR CLASS

class Car {
protected:
    point _loc;         // Current position on screen
    point _prvLoc;      // Previous position for movement
    color _color;       // Car color
    int   _size;        // Car size
    int   _speed;       // Movement speed

public:
    /*
     * Description: Initialize car at position w/ color & speed
     * Return: None (constructor)
     * Pre-condition: x, y within valid bounds, speed >= 0
     * Post-condition: Car created with shared properties initialized
     */
    Car(int x, int y, color carColor, int speed);

    /*
     * Description: Virtual destructor for proper inheritance cleanup
     * Return: None (destructor)
     * Pre-condition: None
     * Post-condition: Car resources properly deallocated
     */
    virtual ~Car() {}

    /*
     * Description: Pure virtual update - implemented by subclasses
     * Return: void
     * Pre-condition: bgOffset is valid
     * Post-condition: Car state updated per subclass logic
     */
    virtual void update(int bgOffset) = 0;

    /*
     * Description: Draw car with body and wheels to screen
     * Return: void
     * Pre-condition: SDL_Plotter g is initialized
     * Post-condition: Car body and wheels rendered to screen
     */
    virtual void draw(SDL_Plotter& g);

    /*
     * Description: Check if car moved below visible area
     * Return: bool - true if off screen, false otherwise
     * Pre-condition: None
     * Post-condition: No state change
     */
    virtual bool isOffScreen() const;

    /*
     * Description: Reposition car (implemented by subclasses)
     * Return: void
     * Pre-condition: None
     * Post-condition: Car repositioned according to subclass rules
     */
    virtual void respawn() = 0;

    /*
     * Description: Get car location
     * Return: point - current position
     * Pre-condition: None
     * Post-condition: No state change
     */
    point getLoc() const;

    /*
     * Description: Get car previous location
     * Return: point - previous position
     * Pre-condition: None
     * Post-condition: No state change
     */
    point getPrvLoc() const;

    /*
     * Description: Get car size
     * Return: int - size (width/height in pixels)
     * Pre-condition: None
     * Post-condition: No state change
     */
    int getSize() const;

    /*
     * Description: Get car speed
     * Return: int - movement speed
     * Pre-condition: None
     * Post-condition: No state change
     */
    int getSpeed() const;
};

// PLAYER CAR CLASS - KEYBOARD CONTROLLED

class PlayerCar : public Car {
private:
    char _lastDirection;  // Last direction pressed (not used for continuous move)

public:
    /*
     * Description: Initialize player car at position w/ color
     * Return: None (constructor)
     * Pre-condition: x, y within valid bounds
     * Post-condition: Player car created with default speed
     */
    PlayerCar(int x, int y, color carColor);

    /*
     * Description: Process keyboard input and move car once
     * Return: void
     * Pre-condition: direction is one of arrow constants
     * Post-condition: Car position and/or speed updated
     */
    void move(char direction);

    /*
     * Description: Update car state each frame (no continuous movement)
     * Return: void
     * Pre-condition: bgOffset is valid (currently unused)
     * Post-condition: No position change; input handled externally
     */
    void update(int bgOffset) override;

    /*
     * Description: Reposition player car at starting location
     * Return: void
     * Pre-condition: None
     * Post-condition: Car reset to start position and starting speed
     */
    void respawn() override;

    /*
     * Description: Set car speed directly, clamped to min/max
     * Return: void
     * Pre-condition: speed is integer
     * Post-condition: Car speed set within [MIN_SPEED, MAX_SPEED]
     */
    void setSpeed(int speed);
};

// AI CAR CLASS - AUTONOMOUS LANE CHANGING

class AICar : public Car {
private:
    int  _targetLane;        // Lane index car is moving toward
    int  _laneChangeTimer;   // Counter for lane change decisions
    int  _laneChangeDelay;   // Frames between potential lane changes
    bool _changingLane;      // Whether currently shifting between lanes
    int  _leftLane;          // X position of left lane
    int  _centerLane;        // X position of center lane
    int  _rightLane;         // X position of right lane

    /*
     * Description: Initialize lane x-positions for AI
     * Return: void
     * Pre-condition: Road lane constants are defined
     * Post-condition: Lane x values stored in member variables
     */
    void initializeLanes();

    /*
     * Description: Get x-position of a given lane
     * Return: int - x coordinate for specified lane
     * Pre-condition: lane is valid AILane value
     * Post-condition: No state change
     */
    int getLanePosition(AILane lane);

    /*
     * Description: Smoothly move AI car toward target lane x position
     * Return: void
     * Pre-condition: _targetLane set to desired lane index
     * Post-condition: _loc.x moved toward target, _changingLane updated
     */
    void updateLaneChange();

    /*
     * Description: Select a random lane enum (LEFT, CENTER, RIGHT)
     * Return: AILane - randomly chosen lane
     * Pre-condition: None
     * Post-condition: No state change
     */
    AILane selectRandomLane();

    /*
     * Description: Check if a lane has an obstacle ahead of the AI car
     * Return: bool - true if lane is blocked, false otherwise
     * Pre-condition: obstacles vector is valid
     * Post-condition: No state change
     */
    bool isLaneBlocked(AILane lane, const std::vector<Obstacle>& obstacles) const;

public:
    /*
     * Description: Initialize AI car at position w/ color & speed
     * Return: None (constructor)
     * Pre-condition: startX, startY within valid bounds
     * Post-condition: AI car created w/ random lane selected
     */
    AICar(int startX, int startY, color carColor, int speed = CAR_START_SPEED);

    /*
     * Description: Update AI car position and lane behavior with obstacle awareness
     * Return: void
     * Pre-condition: bgOffset and obstacles are valid
     * Post-condition: Car moved down, lane change logic evaluated and applied
     */
    void update(int bgOffset, const std::vector<Obstacle>& obstacles);

    /*
     * Description: Override base update to satisfy interface (unused)
     * Return: void
     * Pre-condition: bgOffset is valid
     * Post-condition: No state change
     */
    void update(int bgOffset) override { (void)bgOffset; }

    /*
     * Description: Reposition AI car at top of screen w/ new random lane
     * Return: void
     * Pre-condition: None
     * Post-condition: Car repositioned at top with random lane and timer reset
     */
    void respawn() override;
};

#endif /* SRC_CAR_H_ */
