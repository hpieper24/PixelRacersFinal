//================================================================
// Screen.cpp
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Screen Implementation
// Description: Implementation of all game UI screens
//================================================================

#include "Screen.h"
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// START SCREEN
StartScreen::StartScreen() {}

void StartScreen::update() {
    flashTimer++;
}

void StartScreen::draw(SDL_Plotter& g) {
    for(int x = 0; x < ROW; x++) {
        for(int y = 0; y < COL; y++) {
            g.plotPixel(x, y, BG_START);
        }
    }
    FontRenderer::drawLarge(g, 110, COL / 2 - 80, YELLOW, "PIXEL RACERS", 0);
    FontRenderer::drawSmall(g, 100, COL / 2 - 15, WHITE2, "Press I for Instructions", flashTimer);
    FontRenderer::drawSmall(g, 155, COL / 2 + 15, WHITE2, "Press S to START", flashTimer);
    FontRenderer::drawSmall(g, 10, COL - 40, CYAN, "Press M for Infinite Mode", flashTimer);

    if (infiniteMode) {
        FontRenderer::drawSmall(g, 200, 20, color(0, 255, 0), "INFINITE MODE", 0);
    } else {
        FontRenderer::drawSmall(g, 200, 20, color(255, 100, 0), "NORMAL MODE", 0);
    }

}

bool StartScreen::handleInput(char key) {
    return (toupper(key) == 'S');
}

void StartScreen::setInfiniteMode(bool enable) {
    infiniteMode = enable;
}

// INSTRUCTIONS SCREEN
InstructionsScreen::InstructionsScreen() : scrollOffset{0} {}

void InstructionsScreen::update() {
    scrollOffset++;
    if(scrollOffset > SCROLL_RESET_VALUE) {
        scrollOffset = 0;
    }
}

void InstructionsScreen::draw(SDL_Plotter& g) {
    for(int x = 0; x < ROW; x++) {
        for(int y = 0; y < COL; y++) {
            g.plotPixel(x, y, BG_INSTRUCTIONS);
        }
    }
    FontRenderer::drawLarge(g, 30, 40, CYAN, "CONTROLS", 0);
    FontRenderer::drawSmall(g, 30, 90, WHITE2, "UP: Accelerate", 0);
    FontRenderer::drawSmall(g, 30, 130, WHITE2, "DOWN: Brake", 0);
    FontRenderer::drawSmall(g, 30, 170, WHITE2, "LEFT/RIGHT: Steer", 0);
    FontRenderer::drawSmall(g, 30, 210, WHITE2, "Pass cars = 10pts", 0);
    FontRenderer::drawSmall(g, 30, 250, WHITE2, "Obstacles = CRASH", 0);
    FontRenderer::drawSmall(g, 30, 300, WHITE2, "INFINITE MODE:", 0);
    FontRenderer::drawSmall(g, 30, 340, WHITE2, "M at start: Infinite Mode", 0);
    FontRenderer::drawSmall(g, 30, 380, WHITE2, "Q while playing: End Game", 0);
    FontRenderer::drawSmall(g, 30, COL - 90, CYAN, "Press S to START", 0);
    FontRenderer::drawSmall(g, 30, COL - 130, CYAN, "Press B to go BACK", 0);

}

bool InstructionsScreen::handleInput(char key) {
    return (toupper(key) == 'I');
}

// PAUSE SCREEN
PauseScreen::PauseScreen() {}

void PauseScreen::update() {
    flashTimer++;
}

void PauseScreen::draw(SDL_Plotter& g) {
    for(int x = 0; x < ROW; x++) {
        for(int y = 0; y < COL; y++) {
            g.plotPixel(x, y, BG_PAUSED);
        }
    }
    FontRenderer::drawLarge(g, 200, COL / 2 - 30, YELLOW, "PAUSED", 0);
    FontRenderer::drawSmall(g, 150, COL / 2 + 20, YELLOW, "Press P to Resume", flashTimer);
    FontRenderer::drawSmall(g, 140, COL / 2 + 50, CYAN, "Press B to go BACK", flashTimer);
}

bool PauseScreen::handleInput(char key) {
    return (toupper(key) == 'P');
}

// PLAYING SCREEN
PlayingScreen::PlayingScreen(bool infinite) : currentLap{1}, infiniteMode{infinite} {
    maxLaps = infinite ? -1 : 3;
}

void PlayingScreen::update() {
    flashTimer++;
}

void PlayingScreen::update(PointsManager& points) {
    int lapFromScore = points.getScore() / 500 + 1;
    if (lapFromScore > currentLap) {
        if (infiniteMode || lapFromScore <= maxLaps) {
            currentLap = lapFromScore;
        }
    }
    flashTimer++;
}

void PlayingScreen::draw(SDL_Plotter& g) {
    // Base class implementation - empty for playing screen
}

void PlayingScreen::draw(SDL_Plotter& g, PointsManager& points, PlayerCar& playerCar) {
    color hudColor(255, 255, 255);
    string scoreStr = "Score:";
    string scoreStr2 = to_string(points.getScore());
    string speedStr = "Speed:";
    string speedStr2 = to_string(playerCar.getSpeed());

    string lapStr;
    if (infiniteMode) {
        lapStr = "Lap:" + to_string(currentLap);
    } else {
        lapStr = "Lap:" + to_string(currentLap) + "/" + to_string(maxLaps);
    }

    FontRenderer::drawSmall(g, 10, 20, hudColor, scoreStr, 0);
    FontRenderer::drawSmall(g, 10, 50, hudColor, scoreStr2, 0);
    FontRenderer::drawSmall(g, 10, 80, hudColor, speedStr, 0);
    FontRenderer::drawSmall(g, 10, 110, hudColor, speedStr2, 0);
    FontRenderer::drawSmall(g, 10, 140, hudColor, lapStr, 0);

    if (infiniteMode) {
        FontRenderer::drawSmall(g, 10, 170, color(0,255,0), "INFINITE MODE", flashTimer);
    }
}

bool PlayingScreen::handleInput(char key) {
    return (toupper(key) == 'P');
}

void PlayingScreen::setInfiniteMode(bool enable) {
    infiniteMode = enable;
    maxLaps = enable ? -1 : 3;
}

bool PlayingScreen::isWinCondition() const {
    return !infiniteMode && currentLap >= maxLaps;
}

// GAME OVER SCREEN
GameOverScreen::GameOverScreen() : hitAI{false}, hitObstacle{false} {}

void GameOverScreen::setGameOver(int score, bool aiHit, bool obstacleHit) {
    finalScore = score;
    hitAI = aiHit;
    hitObstacle = obstacleHit;
}

void GameOverScreen::update() {
    flashTimer++;
}

void GameOverScreen::draw(SDL_Plotter& g) {
    for(int x = 0; x < ROW; x++) {
        for(int y = 0; y < COL; y++) {
            g.plotPixel(x, y, BG_GAME_OVER);
        }
    }
    FontRenderer::drawLarge(g, 150, COL / 2 - 70, RED, "GAME OVER", 0);
    FontRenderer::drawSmall(g, 160, COL / 2 - 20, WHITE2, "Final Score: ", 0);
    string scoreStr = to_string(finalScore);
    FontRenderer::drawSmall(g, 360, COL / 2 - 20, WHITE2, scoreStr, 0);

    int yPos = COL / 2 + 10;
    if(hitAI) {
        FontRenderer::drawSmall(g, 190, yPos, AI_BLUE, "Hit AI Car!", flashTimer);
        yPos += GAME_OVER_Y_SPACING;
    }
    if(hitObstacle) {
        FontRenderer::drawSmall(g, 180, yPos, ORANGE, "Hit Obstacle!", flashTimer);
    }
    FontRenderer::drawSmall(g, 140, COL - 90, WHITE2, "Press C to Restart", flashTimer);
}

bool GameOverScreen::handleInput(char key) {
    return (toupper(key) == 'C');
}

// WIN SCREEN
WinScreen::WinScreen() {}

void WinScreen::setWin(int score) {
    finalScore = score;
}

void WinScreen::update() {
    flashTimer++;
}

void WinScreen::draw(SDL_Plotter& g) {
    for(int x = 0; x < ROW; x++) {
        for(int y = 0; y < COL; y++) {
            g.plotPixel(x, y, BG_WIN);
        }
    }
    FontRenderer::drawLarge(g, 150, COL / 2 - 70, GREEN, "YOU WIN!", 0);
    FontRenderer::drawSmall(g, 160, COL / 2 - 20, WHITE2, "Final Score: ", 0);
    string scoreStr = to_string(finalScore);
    FontRenderer::drawSmall(g, 360, COL / 2 - 20, WHITE2, scoreStr, 0);
    FontRenderer::drawSmall(g, 140, COL - 90, CYAN, "Press C to Restart", flashTimer);
}

bool WinScreen::handleInput(char key) {
    return (toupper(key) == 'C');
}
