#include "Color.h"

#include <string.h>
#include <cassert>

const Color textToColor(const char text[])
{
    if(!strcmp(text, "Red")) return RED;
    else if(!strcmp(text, "Blue")) return BLUE;
    else if(!strcmp(text, "Black")) return BLACK;
    else if(!strcmp(text, "Green")) return GREEN;
    else if(!strcmp(text, "White")) return WHITE;
    else return COLOR_UNKNOWN;
}

const char* const colorToText(Color color)
{
    switch (color)
    {
        case COLOR_UNKNOWN:   return "Unknown color";
        case RED:             return "Red";
        case BLACK:           return "Black";
        case BLUE:            return "Blue";
        case WHITE:           return "White";
        case GREEN:           return "Green";
        default:              return "Bad color value!";
    }
    // must never reach this line
    assert(false);
    return NULL;
}

