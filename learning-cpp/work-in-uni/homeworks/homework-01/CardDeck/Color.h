#ifndef COLOR_H
#define COLOR_H

enum Color
{
    COLOR_UNKNOWN,
    RED,
    BLACK,
    BLUE,
    WHITE,
    GREEN,

    COLOR_COUNT
};

const Color textToColor(const char text[]);
const char* const colorToText(Color color);

#endif // COLOR_H
