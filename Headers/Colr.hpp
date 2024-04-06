#pragma once

class Colr {
    public:
    Colr () : r(0), g(0), b(0) {}
    Colr(int r, int g, int b) : r(r), g(g), b(b){};
    bool operator==(const Colr& other) const {
        return r == other.r && g == other.g && b == other.b;
    };
    bool operator<(const Colr& other) const {
        if (r != other.r) return r < other.r;
        if (g != other.g) return g < other.g;
        return b < other.b;
    };
    int r, g, b;
};

enum Shape { 
    Cube,
    Circle,
    Triangle,
    RotatedCube
};

enum Color
{
    Reden,
    Greenen,
    Yellowen,
    Blueen,
    Blacken
};

enum Type
{
    Shapels,
    Colorls
};

const Colr Red(255, 0, 0);
const Colr Green(0, 255, 0);
const Colr Blue(0, 0, 255);
const Colr Yellow(255, 255, 0);
const Colr White(255, 255, 255);
const Colr Black(0,0,0 );
