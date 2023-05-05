#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Pixel {
public:
    unsigned char blue;
    unsigned char green;
    unsigned char red;


    Pixel();
    Pixel(unsigned char blue, unsigned char green, unsigned char red);
    unsigned char getBlue();
    unsigned char getGreen();
    unsigned char getRed();
};