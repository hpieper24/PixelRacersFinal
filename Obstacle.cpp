//================================================================
// Obstacle.cpp
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Obstacle Implementation
// Description: Traffic cone obstacles with collision detection
//================================================================

#include "Obstacle.h"
#include "Car.h"

Obstacle::Obstacle(int x, int y, int size)
    : _loc{point(x, y)},
      _size{size},
      _active{true}
{}

void Obstacle::update(int playerSpeed) {
    if(!_active) return;

    _loc.y += playerSpeed;
}

void Obstacle::draw(SDL_Plotter& g) {
    if(!_active) return;

    // TRAFFIC CONE BASE
    for(int y = 0; y < _size; y++) {
        int width = (y * _size) / _size;
        for(int x = -width / 2; x <= width / 2; x++) {
            int drawX = _loc.x + x;
            int drawY = _loc.y - _size / 2 + y;

            if(drawX >= 0 && drawX < ROW && drawY >= 0 && drawY < COL) {
                // STRIPES
                if(y / OBSTACLE_STRIPE_HEIGHT % 2 == 0) {
                    g.plotPixel(drawX, drawY, ORANGE);
                } else {
                    g.plotPixel(drawX, drawY, WHITE2);
                }
            }
        }
    }
}

bool Obstacle::collidesWith(const Car& car) const {
    if(!_active) return false;

    point carLoc = car.getLoc();
    int carSize = car.getSize();

    // CAR BOUNDS
    int carLeft = carLoc.x - carSize / 2;
    int carRight = carLoc.x + carSize / 2;
    int carTop = carLoc.y - carSize / 2;
    int carBottom = carLoc.y + carSize / 2;

    // OBSTACLE BOUNDS
    int obsLeft = _loc.x - _size / 2;
    int obsRight = _loc.x + _size / 2;
    int obsTop = _loc.y - _size / 2;
    int obsBottom = _loc.y + _size / 2;

    // COLLISION DETECTION
    return (carRight > obsLeft &&
            carLeft < obsRight &&
            carBottom > obsTop &&
            carTop < obsBottom);
}

bool Obstacle::isOffScreen() const {
    return _loc.y > COL + _size;
}

void Obstacle::respawn() {
    _loc.x = ROAD_START + OBSTACLE_SPAWN_MIN_X_OFFSET +
             (rand() % (ROAD_WIDTH - OBSTACLE_SPAWN_MAX_X_OFFSET));
    _loc.y = -_size - (rand() % OBSTACLE_SPAWN_Y_RANDOM_RANGE);
    _active = true;
}

void Obstacle::deactivate() {
    _active = false;
}

bool Obstacle::isActive() const {
    return _active;
}

point Obstacle::getLocation() const {
    return _loc;
}

int Obstacle::getSize() const {
    return _size;
}
