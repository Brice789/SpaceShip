///////////////////////////////////////////////////
//                   Classe FlyingObject
///////////////////////////////////////////////////
#include <iostream>
#include "Asteroid.hpp"
#include "framework.hpp"
#include "Missile.hpp"
#include <cmath>
#include "FlyingObject.hpp"
#include "Spaceship.hpp"


FlyingObject::FlyingObject(double x, double y, double size, double xSpeed, double ySpeed)
{
    this->x = x;
    this->y = y;
    this->size = size;
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
};


bool FlyingObject::Collide(FlyingObject o1, FlyingObject o2)
{
    double distance = sqrt(pow(o2.GetX() - o1.GetX(), 2) + pow(o2.GetY() - o1.GetY(), 2));
    double Rayon = o1.GetSize()/2.0 + o2.GetSize()/2.0;
    //diviser un double par un double
    if(distance < Rayon)
    {
        std::cout << "Collision" << std::endl;
        return true;
    }
    else
    {
        //std::cout << "Pas de collision" << std::endl;
        return false;
    }
}


// Getters
double FlyingObject::GetX()
{
    return x;
}

double FlyingObject::GetY()
{
    return y;
}

double FlyingObject::GetXSpeed()
{
    return xSpeed;
}

double FlyingObject::GetYSpeed()
{
    return ySpeed;
}

double FlyingObject::GetSize()
{
    return size;
}

// Setters
void FlyingObject::SetX(double x)
{
    this->x = x;
}

void FlyingObject::SetY(double y)
{
    this->y = y;
}

void FlyingObject::SetXSpeed(double xSpeed)
{
    this->xSpeed = xSpeed;
}

void FlyingObject::SetYSpeed(double ySpeed)
{
    this->ySpeed = ySpeed;
}

void FlyingObject::SetSize(double size)
{
    this->size = size;
}