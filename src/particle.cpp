#include "particle.h"

Particle::Particle() :
    position(Point3D(0,0,0)),
    mass(1),
    size(1)
{}

Particle::Particle(Point3D _position, double _mass, int _size) :
    position(_position),
    mass(_mass),
    size(_size)
{}

Point3D Particle::getPosition() const {
    return position;
}
void Particle::setPosition(Point3D value) {
    position = value;
}

double Particle::getMass() const {
    return mass;
}
void Particle::setMass(double value) {
    mass = value;
}

int Particle::getSize() const {
    return size;
}
void Particle::setSize(int value) {
    size = value;
}

std::string Particle::toString() const {
    std::ostringstream stringStream;
    stringStream << "Particle coordinates: " << this->position << ", mass: " << this->mass << ", size: " << this->size;
    std::string stringParticle = stringStream.str();
    return stringParticle;
}
