//===========================================================================
// Const.h
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Game Constants
// Description: Central constants, colors, and enums for Pixel Racers
//===========================================================================

#ifndef Const_h
#define Const_h

#include "SDL_Plotter.h"
#include "Utils.h"
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// SCREEN DIMENSIONS
const int ROW = 600;
const int COL = 600;

// ENTITY SIZES
const int SIZE = 25;
const int OBSTACLE_SIZE = 30;

// GAMEPLAY MECHANICS
const int MAX_LAPS = 3;
const int POINTS_PER_LAP = 500;
const int MAX_SPEED = 15;
const int MIN_SPEED = 2;
const int CAR_START_SPEED = 3;
const int PLAYER_START_X = ROW / 2;
const int PLAYER_START_Y = COL - 50;
const int ROAD_BOUNDARY_OFFSET = 10;

// COLLISION
const int COLLISION_COOLDOWN = 60;
const int COLLISION_SPEED_PENALTY = 3;
const int COLLISION_POINTS_PENALTY = 20;

// POINTS SYSTEM
const double SPEED_MULTIPLIER_BASE = 1.0;
const double SPEED_MULTIPLIER_INCREMENT = 0.1;
const int POINTS_PER_FRAME_BASE = 1;
const double POINTS_PER_FRAME_MULTIPLIER = 0.05;
const int POINTS_CAR_PASS = 10;
const int POINTS_OBSTACLE_AVOIDED = 5;

// AI BEHAVIOR
const int AI_LANE_CHANGE_DELAY = 120;
const int AI_LANE_CHANGE_THRESHOLD = 30;
const int AI_SPAWN_Y_RANDOM_RANGE = 200;

// ROAD CONSTRAINTS
const int ROAD_START = ROW / 4;
const int ROAD_END = ROW * 3 / 4;
const int ROAD_WIDTH = ROAD_END - ROAD_START;

// LANE POSITIONS
const int LEFT_LANE_X = ROAD_START + ROAD_WIDTH / 6;
const int CENTER_LANE_X = ROW / 2;
const int RIGHT_LANE_X = ROAD_END - ROAD_WIDTH / 6;

// LANE CHANGE MOVEMENT
const int LANE_CHANGE_STEP = 2;
const int LANE_CHANGE_THRESHOLD = 2;

// RENDERING
const int DASH_LENGTH = 30;
const int GAP_LENGTH = 20;
const int FPS_TARGET = 30;
const int FRAME_DELAY_MS = 30;

// BACKGROUND
const int BACKGROUND_OFFSET_RESET = 50;
const int LANE_MARKER_WIDTH = 2;
const int SIDE_LANE_OFFSET = 50;

// OBSTACLE
const int OBSTACLE_SPAWN_MIN_X_OFFSET = 50;
const int OBSTACLE_SPAWN_MAX_X_OFFSET = 100;
const int OBSTACLE_SPAWN_Y_RANDOM_RANGE = 300;
const int OBSTACLE_STRIPE_HEIGHT = 5;

// SCREENS
const int SCROLL_RESET_VALUE = 300;
const int TEXT_Y_SPACING = 40;
const int GAME_OVER_Y_SPACING = 35;

// FONT SIZES
const int FONT_LARGE_WIDTH = 30;
const int FONT_SMALL_WIDTH = 15;

// BASIC COLORS
const color WHITE2(255, 255, 255);
const color BLACK(0, 0, 0);
const color RED(255, 0, 0);
const color GREEN(0, 255, 0);
const color BLUE(0, 0, 255);
const color GRAY(128, 128, 128);
const color YELLOW(255, 255, 0);
const color CYAN(0, 255, 255);
const color ORANGE(255, 140, 0);

// ROAD & ENVIRONMENT COLORS
const color GRASS(34, 139, 34);
const color ROAD(60, 60, 60);
const color ROAD_LINE(255, 255, 0);

// CAR COLORS
const color PLAYER_CAR(255, 30, 30);
const color AI_BLUE(0, 100, 255);
const color AI_GREEN(0, 255, 0);
const color AI_YELLOW(255, 255, 0);

// SCREEN BACKGROUND COLORS
const color BG_START(20, 40, 80);
const color BG_INSTRUCTIONS(30, 30, 50);
const color BG_PAUSED(80, 80, 80);
const color BG_GAME_OVER(20, 20, 20);
const color BG_WIN(10, 30, 10);

// GAME STATE ENUM
enum GameState {
    STATE_START,
    STATE_INSTRUCTIONS,
    STATE_PLAYING,
    STATE_PAUSED,
    STATE_GAME_OVER,
    STATE_WIN
};

// AI LANE ENUM
enum AILane {
    LEFT_LANE = 0,
    CENTER_LANE = 1,
    RIGHT_LANE = 2
};

#endif /* Const_h */

