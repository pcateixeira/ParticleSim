#ifndef PARTICLE_H
#define PARTICLE_H

#include "point3d.h"

class Particle
{
public:
    Particle();
    Particle(Point3D _position, double _mass);

    Point3D getPosition() const;
    void setPosition(Point3D value);

    double getMass() const;
    void setMass(double value);

    //debug purposes
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& stream, const Particle& particle) {
        stream << particle.toString();
        return stream;
    }

private:
    Point3D position;
    double mass;
};

#endif // PARTICLE_H
