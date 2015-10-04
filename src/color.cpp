#include "color.h"

ColorRGB::ColorRGB() :
    red(0),
    green(0),
    blue(0)
{}

ColorRGB::ColorRGB(double _red, double _green, double _blue) {
    red = validateComponent(_red);
    green = validateComponent(_green);
    blue = validateComponent(_blue);
}

ColorRGB ColorRGB::operator+(ColorRGB other) {
    ColorRGB result;
    result.setRed(validateComponent(this->red + other.getRed()));
    result.setGreen(validateComponent(this->green + other.getGreen()));
    result.setBlue(validateComponent(this->blue + other.getBlue()));
    return result;
}

ColorRGB ColorRGB::operator-(ColorRGB other) {
    ColorRGB result;
    result.setRed(validateComponent(this->red - other.getRed()));
    result.setGreen(validateComponent(this->green - other.getGreen()));
    result.setBlue(validateComponent(this->blue - other.getBlue()));
    return result;
}

double ColorRGB::validateComponent(double value) {
    double result;
    if (value < 0)
        result = 0;
    else if (value > 255)
        result = 255;
    else result = value;

    return result;
}

double ColorRGB::getRed() const {
    return red;
}
void ColorRGB::setRed(double value) {
    red = value;
}

double ColorRGB::getGreen() const {
    return green;
}
void ColorRGB::setGreen(double value) {
    green = value;
}

double ColorRGB::getBlue() const {
    return blue;
}
void ColorRGB::setBlue(double value) {
    blue = value;
}

std::string ColorRGB::toString() const {
    std::ostringstream stringStream;
    stringStream << "( " << this->red << ", " << this->green << ", " << this->blue << ")";
    std::string stringPoint = stringStream.str();
    return stringPoint;
}
