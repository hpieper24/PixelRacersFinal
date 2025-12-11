//================================================================
// Collision.h
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Collision Detection
// Description: Collision detection system for cars and obstacles
//================================================================

#ifndef Collision_h
#define Collision_h

#include "Car.h"
#include "Obstacle.h"

class Collision {
public:
    /*
     * Description: Check collision between player and AI car
     * Return: bool - true if collision detected, false otherwise
     * Pre-condition: player and AI objects are initialized
     * Post-condition: No state change
     */
    static bool checkCarCollision(const Car& player, const AICar& ai) {
        point playerLoc = player.getLoc();
        point aiLoc = ai.getLoc();
        int playerSize = player.getSize();
        int aiSize = ai.getSize();

        // DISTANCE BETWEEN CETNERS
        int dx = playerLoc.x - aiLoc.x;
        int dy = playerLoc.y - aiLoc.y;
        float distance = sqrt(dx * dx + dy * dy);

        return distance < (playerSize / 2 + aiSize / 2);
    }

    /*
     * Description: Check collision between player and obstacle
     * Return: bool - true if collision detected, false otherwise
     * Pre-condition: player and obstacle objects are initialized
     * Post-condition: No state change
     */
    static bool checkObstacleCollision(const Car& player, const Obstacle& obstacle) {
        return obstacle.collidesWith(player);
    }

    /*
     * Description: Check all collisions in the game
     * Return: void
     * Pre-condition: player, aiCars, and obstacles are initialized
     * Post-condition: hitAI and hitObstacle flags set based on collisions
     */
    static void checkAllCollisions(const Car& player,
                                   vector<AICar>& aiCars,
                                   vector<Obstacle>& obstacles,
                                   bool& hitAI,
                                   bool& hitObstacle) {
        hitAI = false;
        hitObstacle = false;

        // AI CAR COLLISION CHECK
        for(auto& ai : aiCars) {
            if(checkCarCollision(player, ai)) {
                hitAI = true;
                break;
            }
        }

        // OBSTACLE COLLISION CHECK
        for(auto& obs : obstacles) {
            if(checkObstacleCollision(player, obs)) {
                hitObstacle = true;
                break;
            }
        }
    }
};

#endif /* Collision_h */
