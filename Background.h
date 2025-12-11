//================================================================
// Background.h
// Author: Jody Spikes, Hailey Pieper, Ian Dudley
// Title: Background Class
// Description: Track rendering with animated dashed lane lines
//================================================================

#ifndef Background_h
#define Background_h

#include "Const.h"

class Background {
private:
    int offset;     // Current animation offset for dashed lines

public:
    /*
     * Description: Initialize background with offset at 0
     * Return: None (constructor)
     * Pre-condition: None
     * Post-condition: Background created with offset initialized
     */
    Background();

    /*
     * Description: Update animation offset based on player speed
     * Return: void
     * Pre-condition: playerSpeed is valid integer
     * Post-condition: Offset updated and wrapped to create animation
     */
    void update(int playerSpeed);

    /*
     * Description: Draw grass, road, and animated lane markings
     * Return: void
     * Pre-condition: SDL_Plotter g is initialized
     * Post-condition: Background rendered to screen
     */
    void draw(SDL_Plotter& g);

    /*
     * Description: Get current animation offset
     * Return: int - current offset value
     * Pre-condition: None
     * Post-condition: No state change
     */
    int getOffset() const { return offset; }
};

#endif /* Background_h */
