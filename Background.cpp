//================================================================
// Background.cpp
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Background Implementation
// Description: Track rendering with animated dashed lane lines
//================================================================

#include "Background.h"

// CONSTRUCTOR
Background::Background() : offset{0} {}

// UPDATE
void Background::update(int playerSpeed) {
    offset -= playerSpeed;
    if(offset <= -BACKGROUND_OFFSET_RESET) {
        offset = 0;
    }
}

// DRAW
void Background::draw(SDL_Plotter& g) {
    // GRASS
    for(int y = 0; y < COL; y++) {
        for(int x = 0; x < ROW; x++) {
            g.plotPixel(x, y, GRASS);
        }
    }

    // ROAD
    for(int y = 0; y < COL; y++) {
        for(int x = ROAD_START; x < ROAD_END; x++) {
            g.plotPixel(x, y, ROAD);
        }
    }

    // CENTER DASHED LINE
    for(int y = 0; y < COL; y++) {
        int adjustedY = (y + offset) % (DASH_LENGTH + GAP_LENGTH);
        if(adjustedY < DASH_LENGTH) {
            for(int i = -LANE_MARKER_WIDTH; i <= LANE_MARKER_WIDTH; i++) {
                g.plotPixel(CENTER_LANE_X + i, y, ROAD_LINE);
            }
        }
    }

    // SIDE LANE MARKERS (DASHED)
    for(int y = 0; y < COL; y++) {
        int adjustedY = (y + offset) % (DASH_LENGTH + GAP_LENGTH);
        if(adjustedY < DASH_LENGTH) {
            for(int i = -1; i <= 1; i++) {
                g.plotPixel(ROAD_START + SIDE_LANE_OFFSET + i, y, WHITE2);
                g.plotPixel(ROAD_END - SIDE_LANE_OFFSET + i, y, WHITE2);
            }
        }
    }

    // ROAD BOUNDARIES
    for(int y = 0; y < COL; y++) {
        for(int i = -LANE_MARKER_WIDTH; i <= LANE_MARKER_WIDTH; i++) {
            g.plotPixel(ROAD_START + i, y, WHITE2);
            g.plotPixel(ROAD_END + i, y, WHITE2);
        }
    }
}
