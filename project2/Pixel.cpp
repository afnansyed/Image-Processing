#include "Pixel.h"

using namespace std;

Pixel::Pixel() {

}

Pixel::Pixel(unsigned char blue, unsigned char green, unsigned char red) {
    this->blue = blue;
    this->green = green;
    this->red = red;
}

unsigned char Pixel::getBlue() {
    return blue;
}

unsigned char Pixel::getGreen() {
    return green;
}

unsigned char Pixel::getRed() {
    return red;
}
