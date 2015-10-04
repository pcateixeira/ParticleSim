#ifndef COLOR_H
#define COLOR_H

#include <ostream>
#include <sstream>
#include <iomanip>

class ColorRGB
{
public:
    ColorRGB();
    ColorRGB(double red, double green, double blue);

    ColorRGB operator+(ColorRGB other);
    ColorRGB operator-(ColorRGB other);

    double validateComponent(double value);

    double getRed() const;
    void setRed(double value);

    double getGreen() const;
    void setGreen(double value);

    double getBlue() const;
    void setBlue(double value);

    //debug purposes
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& stream, const ColorRGB& color) {
        stream << color.toString();
        return stream;
    }

private:
    double red, green, blue;
};

#endif // COLOR_H
