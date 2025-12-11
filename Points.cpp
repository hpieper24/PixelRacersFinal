//================================================================
// Points.cpp
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Points Manager Implementation
// Description: Score calculation and multiplier management
//================================================================

#include "Points.h"

PointsManager::PointsManager()
    : score{0},
      baseSpeed{0},
      speedMultiplier{SPEED_MULTIPLIER_BASE},
      carsPassed{0},
      obstaclesAvoided{0},
      frameCounter{0}
{}

void PointsManager::reset() {
    score = 0;
    baseSpeed = 0;
    speedMultiplier = SPEED_MULTIPLIER_BASE;
    carsPassed = 0;
    obstaclesAvoided = 0;
    frameCounter = 0;
}

void PointsManager::updateSpeed(int playerSpeed) {
    baseSpeed = playerSpeed;
    speedMultiplier = SPEED_MULTIPLIER_BASE +
                      (playerSpeed * SPEED_MULTIPLIER_INCREMENT);
}

void PointsManager::update() {
    frameCounter++;
    float basePointsPerFrame = POINTS_PER_FRAME_BASE +
                               (speedMultiplier * POINTS_PER_FRAME_MULTIPLIER);
    int timePoints = static_cast<int>(basePointsPerFrame);

    if(timePoints > 0) {
        score += timePoints;
    }
}

void PointsManager::addCarPass() {
    int points = static_cast<int>(POINTS_CAR_PASS * speedMultiplier);
    score += points;
    carsPassed++;
}

void PointsManager::addObstacleAvoided() {
    int points = static_cast<int>(POINTS_OBSTACLE_AVOIDED * speedMultiplier);
    score += points;
    obstaclesAvoided++;
}
