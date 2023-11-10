#include <iostream>
#include "framework.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include <cmath>

///////////////////////////////////////////////////
//                   Classe Spaceship
///////////////////////////////////////////////////

#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP


class Spaceship : public FlyingObject {
private:
    double angle;
    double velocityX;
    double velocityY;

public:
    Spaceship(double x, double y, double size, double initialAngle);
    double GetAngle();
    void SpeedUp(double accelerationFactor);
    void SpeedDown(double decelerationFactor);
    void Rotate(double rotationAngle);
    bool UpdatePosition(double screenWidth, double screenHeight);
    void move(double screenWidth, double screenHeight);
};

#endif // SPACESHIP_HPP
