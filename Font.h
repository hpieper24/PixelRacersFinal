//==================================================
// Font.h
// OWNERSHIP: Jody Spikes, Hailey Pieper, Ian Dudley
// PURPOSE: Pixel Font Rendering
//==================================================

#ifndef FONT_H_
#define FONT_H_

#include "SDL_Plotter.h"
#include <string>

class FontRenderer {
public:
	// LARGE TEXT
    static void drawLarge(SDL_Plotter& g, int x, int y, color c, const string& text, int flashTimer = 0);

    // SMALL TEXT
    static void drawSmall(SDL_Plotter& g, int x, int y, color c, const string& text, int flashTimer = 0);
};

#endif /* FONT_H_ */
