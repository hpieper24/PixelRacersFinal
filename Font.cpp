//==================================================
// Font.cpp
// OWNERSHIP: Jody Spikes, Hailey Pieper, Ian Dudley
// PURPOSE: Pixel Font Rendering
//==================================================

#include "Font.h"
#include <cctype>

// DRAW LARGE TEXT
void FontRenderer::drawLarge(SDL_Plotter& g, int x, int y, color c, const std::string& text, int flashTimer) {
    const int letterWidth = 30;

    for(size_t i = 0; i < text.size(); ++i) {
        char ch = toupper(text[i]);
        if(ch == ' ') { x += letterWidth / 8; continue; }
        int charX = x + i * letterWidth;

        if(flashTimer != 0 && flashTimer % 20 < 10) continue;

        switch(ch) {
            case 'A':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c); }
                break;
            case 'B':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 16; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 16; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int px = 0; px < 16; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 22; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int py = 20; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c); }
                break;
            case 'C':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 16; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 16; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c); }
                break;
            case 'D':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 16; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 16; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 15 - thick, y + py, c); }
                break;
            case 'E':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 10; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c); }
                break;
            case 'F':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 10; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c); }
                break;
            case 'G':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 16; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 10; px < 18; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int py = 20; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c); }
                break;
            case 'H':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 20 + thick, c); }
                break;
            case 'I':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 4; px < 14; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 4; px < 14; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 9 - thick, y + py, c); }
                break;
            case 'J':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 4; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 14, y + py, c);
                for(int px = 0; px < 14; px++) g.plotPixel(charX + px, y + 36 - thick, c); }
                break;
            case 'K':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 20; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int py = 20; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 20 + thick, c); }
                break;
            case 'L':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c); }
                break;
            case 'M':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int py = 4; py < 18; py++) g.plotPixel(charX + 8 + thick, y + py, c); }
                break;
            case 'N':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 2 + py / 2, y + py, c); }
                break;
            case 'O':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c); }
                break;
            case 'P':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 22; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int px = 6; px < 17; px++) g.plotPixel(charX + px, y + 20 + thick, c); }
                break;
            case 'Q':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 32; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int px = 12; px < 18; px++) g.plotPixel(charX + px, y + 32 + thick, c); }
                break;
            case 'R':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 22; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int px = 6; px < 17; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int py = 20; py < 36; py++) g.plotPixel(charX + 12 + (py - 20) / 4 + thick / 2, y + py, c); }
                break;
            case 'S':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 16; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 16; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int px = 4; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 20; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 20; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c); }
                break;
            case 'T':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 9 - thick, y + py, c); }
                break;
            case 'U':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c); }
                break;
            case 'V':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 32; py++) g.plotPixel(charX + 0 + (py - 4) / 4 + thick, y + py, c);
                for(int py = 4; py < 32; py++) g.plotPixel(charX + 17 - (py - 4) / 4 - thick, y + py, c); }
                break;
            case 'W':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int i = 0; i < 10; i++) g.plotPixel(charX + 3 + i, y + 22 + i / 2, c);
                for(int i = 0; i < 10; i++) g.plotPixel(charX + 14 - i, y + 22 + i / 2, c); }
                break;
            case 'X':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 36; py++) { int px = (py - 4) * 17 / 32 + thick; if(px >= 0 && px < 18) g.plotPixel(charX + px, y + py, c); }
                for(int py = 4; py < 36; py++) { int px = 17 - (py - 4) * 17 / 32 + thick / 2; if(px >= 0 && px < 18) g.plotPixel(charX + px, y + py, c); } }
                break;
            case 'Y':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 16; py++) g.plotPixel(charX + 2 + thick, y + py, c);
                for(int py = 4; py < 16; py++) g.plotPixel(charX + 16 - thick, y + py, c);
                for(int py = 16; py < 36; py++) g.plotPixel(charX + 9 + thick / 2, y + py, c); }
                break;
            case 'Z':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - (py - 4) / 4, y + py, c); }
                break;
            case ':':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 6; px < 12; px++) g.plotPixel(charX + px, y + 10 + thick, c);
                for(int px = 6; px < 12; px++) g.plotPixel(charX + px, y + 26 + thick, c); }
                break;
            case '.':
                for(int thick = 0; thick < 3; thick++)
                for(int px = 6; px < 12; px++) g.plotPixel(charX + px, y + 32 + thick, c);
                break;
            case '!':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 30; py++) g.plotPixel(charX + 9 - thick, y + py, c);
                for(int px = 6; px < 12; px++) g.plotPixel(charX + px, y + 34 + thick, c); }
                break;
            case '/':
                for(int thick = 0; thick < 3; thick++)
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - (py - 4) / 4, y + py, c);
                break;
            case '=':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 12 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 24 + thick, c); }
                break;
            case '0':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c); }
                break;
            case '1':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 8 + thick, y + py, c);
                for(int px = 4; px < 12; px++) g.plotPixel(charX + px, y + 36 - thick, c); }
                break;
            case '2':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int py = 4; py < 20; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int py = 20; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c); }
                break;
            case '3':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c); }
                break;
            case '4':
                for(int thick = 0; thick < 3; thick++) {
                for(int py = 4; py < 20; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c); }
                break;
            case '5':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int py = 4; py < 20; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int py = 20; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c); }
                break;
            case '6':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 20; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c); }
                break;
            case '7':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - (py - 4) / 4, y + py, c); }
                break;
            case '8':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c); }
                break;
            case '9':
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 20 + thick, c);
                for(int py = 4; py < 22; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 4; py < 36; py++) g.plotPixel(charX + 17 - thick, y + py, c);
                for(int px = 0; px < 18; px++) g.plotPixel(charX + px, y + 36 - thick, c); }
                break;
            default:
                for(int thick = 0; thick < 3; thick++) {
                for(int px = 2; px < 16; px++) g.plotPixel(charX + px, y + 8 + thick, c);
                for(int px = 2; px < 16; px++) g.plotPixel(charX + px, y + 32 - thick, c);
                for(int py = 8; py < 32; py++) g.plotPixel(charX + 2 + thick, y + py, c);
                for(int py = 8; py < 32; py++) g.plotPixel(charX + 15 - thick, y + py, c); }
                break;
        }
    }
}

// DRAW SMALL TEXT
void FontRenderer::drawSmall(SDL_Plotter& g, int x, int y, color c, const string& text, int flashTimer) {
    const int smallWidth = 15;

    for(size_t i = 0; i < text.size(); ++i) {
        char ch = toupper(text[i]);
        if(ch == ' ') { x += smallWidth / 2; continue; }
        int charX = x + i * smallWidth;

        if(flashTimer != 0 && flashTimer % 30 < 15) continue;

        switch(ch) {
            case 'A':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 10 + thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c); }
                break;
            case 'B':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 8; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 8; px++) g.plotPixel(charX + px, y + 10 + thick, c);
                for(int px = 0; px < 8; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 11; py++) g.plotPixel(charX + 7 - thick, y + py, c);
                for(int py = 10; py < 18; py++) g.plotPixel(charX + 7 - thick, y + py, c); }
                break;
            case 'C':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 8; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 8; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c); }
                break;
            case 'D':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 8; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 8; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 7, y + py, c); }
                break;
            case 'E':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 5; px++) g.plotPixel(charX + px, y + 9 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c); }
                break;
            case 'F':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 5; px++) g.plotPixel(charX + px, y + 9 + thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c); }
                break;
            case 'G':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 8; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 8; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 5; px < 8; px++) g.plotPixel(charX + px, y + 9 + thick, c);
                for(int py = 9; py < 18; py++) g.plotPixel(charX + 7 - thick, y + py, c); }
                break;
            case 'H':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 9 + thick, c); }
                break;
            case 'I':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 1; px < 8; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 1; px < 8; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 3 + thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 4, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 5 - thick, y + py, c); }
                break;
            case 'J':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 2; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int px = 0; px < 8; px++) g.plotPixel(charX + px, y + 16 - thick, c); }
                break;
            case 'K':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 10; py++) g.plotPixel(charX + 8 - (py - 2), y + py, c);
                for(int py = 10; py < 18; py++) g.plotPixel(charX + 0 + (py - 10), y + py, c); }
                break;
            case 'L':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c); }
                break;
            case 'M':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int py = 2; py < 10; py++) g.plotPixel(charX + 4 - thick, y + py, c); }
                break;
            case 'N':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 1 + (py - 2) / 2, y + py, c); }
                break;
            case 'O':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c); }
                break;
            case 'P':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 11; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int px = 3; px < 8; px++) g.plotPixel(charX + px, y + 10 + thick, c); }
                break;
            case 'Q':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 15; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int px = 6; px < 9; px++) g.plotPixel(charX + px, y + 15 + thick, c); }
                break;
            case 'R':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 11; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int px = 3; px < 8; px++) g.plotPixel(charX + px, y + 10 + thick, c);
                for(int py = 10; py < 18; py++) g.plotPixel(charX + 6 + (py - 10) / 3, y + py, c); }
                break;
            case 'S':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 9 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 9; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 9; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int px = 0; px < 4; px++) g.plotPixel(charX + px, y + 8 + thick, c);
                for(int px = 5; px < 9; px++) g.plotPixel(charX + px, y + 10 + thick, c); }
                break;
            case 'T':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 4 - thick, y + py, c); }
                break;
            case 'U':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c); }
                break;
            case 'V':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 13; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 13; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int py = 13; py < 18; py++) g.plotPixel(charX + 4 + (py - 13), y + py, c); }
                break;
            case 'W':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 16; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 16; py++) g.plotPixel(charX + 4 - thick, y + py, c);
                for(int py = 2; py < 16; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int py = 12; py < 18; py++) g.plotPixel(charX + 2 + thick, y + py, c);
                for(int py = 12; py < 18; py++) g.plotPixel(charX + 6 - thick, y + py, c); }
                break;
            case 'X':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 18; py++) { int px = (py - 2) * 8 / 16 + thick; if(px >= 0 && px < 9) g.plotPixel(charX + px, y + py, c); }
                for(int py = 2; py < 18; py++) { int px = 8 - (py - 2) * 8 / 16 + thick / 2; if(px >= 0 && px < 9) g.plotPixel(charX + px, y + py, c); } }
                break;
            case 'Y':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 9; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 9; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int py = 9; py < 18; py++) g.plotPixel(charX + 4 - thick, y + py, c); }
                break;
            case 'Z':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - (py - 2) / 2, y + py, c); }
                break;
            case ':':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 3; px < 6; px++) g.plotPixel(charX + px, y + 5 + thick, c);
                for(int px = 3; px < 6; px++) g.plotPixel(charX + px, y + 13 + thick, c); }
                break;
            case '.':
                for(int thick = 0; thick < 2; thick++)
                for(int px = 3; px < 6; px++) g.plotPixel(charX + px, y + 15 + thick, c);
                break;
            case '!':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 13; py++) g.plotPixel(charX + 4 - thick, y + py, c);
                for(int px = 3; px < 6; px++) g.plotPixel(charX + px, y + 14 + thick, c);
                for(int px = 3; px < 6; px++) g.plotPixel(charX + px, y + 17, c); }
                break;
            case '/':
                for(int thick = 0; thick < 2; thick++)
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - (py - 2) / 2, y + py, c);
                break;
            case '=':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 6 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 12 + thick, c); }
                break;
            case '0':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c); }
                break;
            case '1':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 1; px < 4; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int py = 2; py < 16; py++) g.plotPixel(charX + 4 - thick, y + py, c);
                for(int px = 1; px < 8; px++) g.plotPixel(charX + px, y + 16 - thick, c); }
                break;
            case '2':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int py = 2; py < 9; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 9 + thick, c);
                for(int py = 9; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c); }
                break;
            case '3':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 9 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c); }
                break;
            case '4':
                for(int thick = 0; thick < 2; thick++) {
                for(int py = 2; py < 10; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 9 + thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c); }
                break;
            case '5':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int py = 2; py < 10; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 9 + thick, c);
                for(int py = 9; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c); }
                break;
            case '6':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 9 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 9; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c); }
                break;
            case '7':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - (py - 2) / 2, y + py, c); }
                break;
            case '8':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 9 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c); }
                break;
            case '9':
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 2 + thick, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 9 + thick, c);
                for(int py = 2; py < 11; py++) g.plotPixel(charX + 0 + thick, y + py, c);
                for(int py = 2; py < 18; py++) g.plotPixel(charX + 8 - thick, y + py, c);
                for(int px = 0; px < 9; px++) g.plotPixel(charX + px, y + 16 - thick, c); }
                break;
            default:
                for(int thick = 0; thick < 2; thick++) {
                for(int px = 1; px < 8; px++) g.plotPixel(charX + px, y + 4 + thick, c);
                for(int px = 1; px < 8; px++) g.plotPixel(charX + px, y + 16 - thick, c);
                for(int py = 4; py < 16; py++) g.plotPixel(charX + 1 + thick, y + py, c);
                for(int py = 4; py < 16; py++) g.plotPixel(charX + 7 - thick, y + py, c); }
                break;
        }
    }
}
