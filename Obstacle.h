//================================================================
// Obstacle.h
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Obstacle Class
// Description: Traffic cone obstacles with collision detection
//================================================================

#ifndef Obstacle_h
#define Obstacle_h

#include "Const.h"

class Car;

class Obstacle {
private:
    point _loc;		// Current position on screen
    int _size;		// Obstacle size in pixels
    bool _active;	// Whether obstacle is active and drawn

public:
    /*
     * Description: Initialize obstacle at position with size
     * Return: None (constructor)
     * Pre-condition: x, y within valid bounds
     * Post-condition: Obstacle created at (x, y) with active state
     */
    Obstacle(int x, int y, int size = OBSTACLE_SIZE);

    /*
     * Description: Move obstacle down screen based on player speed
     * Return: void
     * Pre-condition: playerSpeed is valid
     * Post-condition: Obstacle position updated downward
     */
    void update(int playerSpeed);

    /*
     * Description: Draw obstacle as striped traffic cone
     * Return: void
     * Pre-condition: SDL_Plotter g is initialized
     * Post-condition: Obstacle rendered to screen if active
     */
    void draw(SDL_Plotter& g);

    /*
     * Description: Check collision between obstacle and car
     * Return: bool - true if collision detected, false otherwise
     * Pre-condition: Car object is valid
     * Post-condition: No state change
     */
    bool collidesWith(const Car& car) const;

    /*
     * Description: Check if obstacle is below visible screen area
     * Return: bool - true if off screen, false otherwise
     * Pre-condition: None
     * Post-condition: No state change
     */
    bool isOffScreen() const;

    /*
     * Description: Reposition obstacle at top with random X position
     * Return: void
     * Pre-condition: None
     * Post-condition: Obstacle reset to top of screen, active = true
     */
    void respawn();

    /*
     * Description: Deactivate obstacle (prevent drawing and collision)
     * Return: void
     * Pre-condition: None
     * Post-condition: Active state set to false
     */
    void deactivate();

    /*
     * Description: Get active status of obstacle
     * Return: bool - current value of active state
     * Pre-condition: None
     * Post-condition: No state change
     */
    bool isActive() const;

    /*
     * Description: Get obstacle location
     * Return: point - current position
     * Pre-condition: None
     * Post-condition: No state change
     */
    point getLocation() const;

    /*
     * Description: Get obstacle size
     * Return: int - triangle size in pixels
     * Pre-condition: None
     * Post-condition: No state change
     */
    int getSize() const;
};

#endif /* Obstacle_h */
