#include "particle.h"

Particle::Particle()
{}

Particle::Particle(Point3D _position, double _mass) :
    position(_position),
    mass(_mass)
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

std::string Particle::toString() const {
    std::ostringstream stringStream;
    stringStream << "Particle coordinates: " << this->position << ", mass: " << this->mass;
    std::string stringParticle = stringStream.str();
    return stringParticle;
}
