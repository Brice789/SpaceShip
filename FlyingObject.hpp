///////////////////////////////////////////////////
//                   Classe FlyingObject
///////////////////////////////////////////////////


#ifndef FlyingObject_HPP_
#define FlyingObject_HPP_
#include <string>
#include "include/SDL2/SDL.h"
#include <cmath>


class FlyingObject
{
    public:
        // Getters
        double GetX() ;
        double GetY();
        double GetXSpeed();
        double GetYSpeed();
        double GetSize();
        // Setters
        void SetX(double x);
        void SetY(double y);
        void SetXSpeed(double xSpeed);
        void SetYSpeed(double ySpeed);
        void SetSize(double size);

        FlyingObject(double x, double y, double size, double xSpeed, double ySpeed);

        static bool Collide(FlyingObject o1, FlyingObject o2);

    protected:
        double x; 
        double y; 
        double size; 
        double xSpeed; 
        double ySpeed;
};

#endif