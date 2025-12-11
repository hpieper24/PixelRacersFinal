//================================================================
// Points.h
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Points Manager
// Description: Manages player score with speed multipliers
//================================================================

#ifndef Points_h
#define Points_h

#include "Const.h"

class PointsManager {
private:
    int 	score;              // Total player score
    int 	baseSpeed;          // Current player speed
    float 	speedMultiplier;  	// Speed-based score multiplier
    int 	carsPassed;         // Number of AI cars passed
    int 	obstaclesAvoided;   // Number of obstacles avoided
    int 	frameCounter;       // Frame counter for score calculation

public:
    /*
     * Description: Initialize points manager with zero values
     * Return: None (constructor)
     * Pre-condition: None
     * Post-condition: PointsManager created with all values reset
     */
    PointsManager();

    /*
     * Description: Reset all score and counter values to zero
     * Return: void
     * Pre-condition: None
     * Post-condition: All tracking variables reset to initial state
     */
    void reset();

    /*
     * Description: Update speed multiplier based on current player speed
     * Return: void
     * Pre-condition: playerSpeed is valid
     * Post-condition: speedMultiplier updated based on speed
     */
    void updateSpeed(int playerSpeed);

    /*
     * Description: Update score based on elapsed frames
     * Return: void
     * Pre-condition: None
     * Post-condition: Frame counter incremented, score updated
     */
    void update();

    /*
     * Description: Add points for passing an AI car
     * Return: void
     * Pre-condition: None
     * Post-condition: Score and carsPassed counter incremented
     */
    void addCarPass();

    /*
     * Description: Add points for avoiding an obstacle
     * Return: void
     * Pre-condition: None
     * Post-condition: Score and obstaclesAvoided counter incremented
     */
    void addObstacleAvoided();

    /*
     * Description: Get current total score
     * Return: int - current score value
     * Pre-condition: None
     * Post-condition: No state change
     */
    int getScore() const { return score; }

    /*
     * Description: Get number of cars passed
     * Return: int - carsPassed count
     * Pre-condition: None
     * Post-condition: No state change
     */
    int getCarsPassed() const { return carsPassed; }

    /*
     * Description: Get number of obstacles avoided
     * Return: int - obstaclesAvoided count
     * Pre-condition: None
     * Post-condition: No state change
     */
    int getObstaclesAvoided() const { return obstaclesAvoided; }

    /*
     * Description: Get current speed multiplier
     * Return: float - current multiplier value
     * Pre-condition: None
     * Post-condition: No state change
     */
    float getSpeedMultiplier() const { return speedMultiplier; }
};

#endif /* Points_h */
