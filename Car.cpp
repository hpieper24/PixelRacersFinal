//=================================================================
// Car.cpp
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Car Classes Implementation
// Description: Implementation of Car, PlayerCar, and AICar classes
//=================================================================

#include "Car.h"
#include "Utils.h"
#include "Obstacle.h"
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>

// BASE CAR CLASS IMPLEMENTATION

Car::Car(int x, int y, color carColor, int speed)
    : _loc{point(x, y)},
      _prvLoc{x, y},
      _color{carColor},
      _size{SIZE},
      _speed{speed}
{}

void Car::draw(SDL_Plotter& g) {
    int wheelSize = _size / 5 + 2;

    // BODY
    drawRect(_loc.x - _size / 2, _loc.y - _size / 2, _size, _size, _color, g);

    // WHEELS
    drawRect(_loc.x - _size / 2, _loc.y - _size / 2, wheelSize, wheelSize, BLACK, g);
    drawRect(_loc.x + _size / 2 - wheelSize, _loc.y - _size / 2, wheelSize, wheelSize, BLACK, g);
    drawRect(_loc.x - _size / 2, _loc.y + _size / 2 - wheelSize, wheelSize, wheelSize, BLACK, g);
    drawRect(_loc.x + _size / 2 - wheelSize, _loc.y + _size / 2 - wheelSize, wheelSize, wheelSize, BLACK, g);
}

bool Car::isOffScreen() const {
    return _loc.y > COL + _size;
}

point Car::getLoc() const {
    return _loc;
}

point Car::getPrvLoc() const {
    return _prvLoc;
}

int Car::getSize() const {
    return _size;
}

int Car::getSpeed() const {
    return _speed;
}

// PLAYER CAR CLASS IMPLEMENTATION

PlayerCar::PlayerCar(int x, int y, color carColor)
    : Car(x, y, carColor, CAR_START_SPEED),
      _lastDirection('U')
{}

void PlayerCar::move(char direction) {
    // STORE PREVIOUS LOCATION
    _prvLoc.x = _loc.x;
    _prvLoc.y = _loc.y;

    switch(direction) {
        case RIGHT_ARROW:
            if(_loc.x < ROAD_END - _size / 2 - ROAD_BOUNDARY_OFFSET) {
                _loc.x += _speed;
            }
            break;

        case LEFT_ARROW:
            if(_loc.x > ROAD_START + _size / 2 + ROAD_BOUNDARY_OFFSET) {
                _loc.x -= _speed;
            }
            break;

        case UP_ARROW:
            _speed = std::min(_speed + 1, MAX_SPEED);
            break;

        case DOWN_ARROW:
            _speed = std::max(_speed - 1, MIN_SPEED);
            break;

        default:
            break;
    }
}

void PlayerCar::update(int bgOffset) {
    (void)bgOffset; // no continuous movement; input handled in main loop
}

void PlayerCar::respawn() {
    _loc.x = PLAYER_START_X;
    _loc.y = PLAYER_START_Y;
    _prvLoc = _loc;
    _speed = CAR_START_SPEED;
}

void PlayerCar::setSpeed(int speed) {
    _speed = std::min(std::max(speed, MIN_SPEED), MAX_SPEED);
}

// AI CAR CLASS IMPLEMENTATION

AICar::AICar(int startX, int startY, color carColor, int speed)
    : Car(startX, startY, carColor, speed),
      _targetLane{0},
      _laneChangeTimer{0},
      _laneChangeDelay{AI_LANE_CHANGE_DELAY},
      _changingLane{false}
{
    initializeLanes();
    _targetLane = static_cast<int>(selectRandomLane());
    _loc.x = getLanePosition(static_cast<AILane>(_targetLane));
}

void AICar::initializeLanes() {
    _leftLane   = LEFT_LANE_X;
    _centerLane = CENTER_LANE_X;
    _rightLane  = RIGHT_LANE_X;
}

int AICar::getLanePosition(AILane lane) {
    switch(lane) {
        case LEFT_LANE:   return _leftLane;
        case CENTER_LANE: return _centerLane;
        case RIGHT_LANE:  return _rightLane;
        default:          return _centerLane;
    }
}

AILane AICar::selectRandomLane() {
    int random = std::rand() % 3;
    return static_cast<AILane>(random);
}

void AICar::updateLaneChange() {
    int target = getLanePosition(static_cast<AILane>(_targetLane));

    if(_loc.x < target - LANE_CHANGE_THRESHOLD) {
        _loc.x += LANE_CHANGE_STEP;
        _changingLane = true;
    }
    else if(_loc.x > target + LANE_CHANGE_THRESHOLD) {
        _loc.x -= LANE_CHANGE_STEP;
        _changingLane = true;
    }
    else {
        _loc.x = target;
        _changingLane = false;
    }
}

bool AICar::isLaneBlocked(AILane lane, const std::vector<Obstacle>& obstacles) const {
    int laneX = const_cast<AICar*>(this)->getLanePosition(lane);

    for (const auto& obs : obstacles) {
        point oLoc = obs.getLocation();
        int   oSize = obs.getSize();

        // Same lane horizontally?
        if (std::abs(oLoc.x - laneX) <= oSize / 2) {
            // Ahead of AI within danger distance
            if (oLoc.y > _loc.y && oLoc.y - _loc.y < 150) {
                return true;
            }
        }
    }
    return false;
}

void AICar::update(int bgOffset, const std::vector<Obstacle>& obstacles) {
    (void)bgOffset; // not used currently

    _prvLoc.x = _loc.x;
    _prvLoc.y = _loc.y;

    _loc.y += _speed;
    _laneChangeTimer++;

    if(!_changingLane && _laneChangeTimer >= _laneChangeDelay) {
        _laneChangeTimer = 0;

        AILane currentLane = static_cast<AILane>(_targetLane);

        bool currentBlocked = isLaneBlocked(currentLane, obstacles);
        bool leftBlocked    = isLaneBlocked(LEFT_LANE,   obstacles);
        bool centerBlocked  = isLaneBlocked(CENTER_LANE, obstacles);
        bool rightBlocked   = isLaneBlocked(RIGHT_LANE,  obstacles);

        if (currentBlocked) {
            std::vector<AILane> candidates;
            if (!leftBlocked)   candidates.push_back(LEFT_LANE);
            if (!centerBlocked) candidates.push_back(CENTER_LANE);
            if (!rightBlocked)  candidates.push_back(RIGHT_LANE);

            if (!candidates.empty()) {
                AILane newLane = candidates[std::rand() % candidates.size()];
                _targetLane = static_cast<int>(newLane);
            }
        } else {
            int decision = std::rand() % 100;
            if (decision < AI_LANE_CHANGE_THRESHOLD) {
                std::vector<AILane> candidates = { LEFT_LANE, CENTER_LANE, RIGHT_LANE };

                candidates.erase(
                    std::remove_if(candidates.begin(), candidates.end(),
                                   [&](AILane l){
                                       return l == currentLane || isLaneBlocked(l, obstacles);
                                   }),
                    candidates.end()
                );

                if (!candidates.empty()) {
                    AILane newLane = candidates[std::rand() % candidates.size()];
                    _targetLane = static_cast<int>(newLane);
                }
            }
        }
    }

    updateLaneChange();
}

void AICar::respawn() {
    _targetLane = static_cast<int>(selectRandomLane());
    _loc.x = getLanePosition(static_cast<AILane>(_targetLane));
    _loc.y = -_size - (std::rand() % AI_SPAWN_Y_RANDOM_RANGE);
    _prvLoc = _loc;
    _laneChangeTimer = 0;
}
