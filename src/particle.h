#ifndef PARTICLE_H
#define PARTICLE_H

#include "point3d.h"

class Particle
{
public:
    Particle();
    Particle(Point3D _position, double _mass, int _size);

    Point3D getPosition() const;
    void setPosition(Point3D value);

    double getMass() const;
    void setMass(double value);

    int getSize() const;
    void setSize(int value);

    //debug purposes
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& stream, const Particle& particle) {
        stream << particle.toString();
        return stream;
    }

private:
    Point3D position;
    double mass;
    int size;
};

#endif // PARTICLE_H
