#include <string>
#include "include/SDL2/SDL.h"
#include "FlyingObject.hpp"

///////////////////////////////////////////////////
//                   Classe Missile
///////////////////////////////////////////////////

#ifndef MISSILE_HPP_
#define MISSILE_HPP_



class Missile : public FlyingObject 
{
    public:
        // Getters
        // double GetX() ;
        // double GetY();
        // double GetXSpeed();
        // double GetYSpeed();
        // double GetSize();
        // Setters
        // void SetX(double x);
        // void SetY(double y);
        // void SetXSpeed(double xSpeed);
        // void SetYSpeed(double ySpeed);
        // void SetSize(double size);


       Missile(double x, double y, double size, double xSpeed, double ySpeed, double angle);


      // bool move(double screenWidth, double screenHeight);

    //    bool IsActive() const { return active; }
    //    void Activate() { active = true; }
    //    void Deactivate() { active = false; }


        void move(double screenHeight, double screenWidth);

        //void move();


        void position();

        void Activate();
        void Deactivate();
        bool IsActive() const;

        Missile(double startX, double startY, double size, double xSpeed, double ySpeed);

        //void move(double screenWidth, double screenHeight);

        double GetX() const;
        double GetY() const;
        void SetX(double newX);
        void SetY(double newY);
        void SetXSpeed(double newXSpeed);
        void SetYSpeed(double newYSpeed);
    

    private:
        double m_angle; 
         bool active;
         double x, y;
         double xSpeed, ySpeed;
};
#endif