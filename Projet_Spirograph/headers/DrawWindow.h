#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include "SFML/Graphics.hpp"
#include "Spirograph.h"

class DrawWindow
{
    public:
        DrawWindow();
        ~DrawWindow();
        void mainWindow();
        void updatePixels(int i, int tempx, int tempy, int phi);
        void pixelsToColor(int color);
        string getScreenFilename();

    private:
        int winX;
        int winY;
        sf::Uint8* pixels;
        Spirograph* spiro;
};

#endif // DRAWWINDOW_H
