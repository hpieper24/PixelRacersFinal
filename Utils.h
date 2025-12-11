//================================================================
// Utils.h
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Utility Functions
// Description: Shared drawing and helper functions
//================================================================

#ifndef Utils_h
#define Utils_h

#include "SDL_Plotter.h"
#include "Const.h"

/*
 * Description: Draw filled rectangle on SDL_Plotter
 * Return: void
 * Pre-condition: SDL_Plotter g is initialized, coordinates valid
 * Post-condition: Rectangle drawn with bounds checking
 */
inline void drawRect(int x, int y, int width, int height, color c, SDL_Plotter& g) {
    for(int row = y; row < y + height; row++) {
        for(int col = x; col < x + width; col++) {
            if(col >= 0 && col < 600 && row >= 0 && row < 600) {
                g.plotPixel(col, row, c);
            }
        }
    }
}

#endif /* Utils_h */
