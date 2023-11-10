///////////////////////////////////////////////////
//                   Classe Asteroid 
///////////////////////////////////////////////////

// #ifndef ASTEROID_HPP_
// #define ASTEROID_HPP_
// #include <string>
// #include "include/SDL2/SDL.h"
// #include "FlyingObject.hpp"
// #pragma once
// #include "Missile.hpp"
//using std::string;

// class Asteroid : public FlyingObject
// {
//     public:
//         //////////
//         // Getters
//         double GetX() ;
//         double GetY();
//         double GetXSpeed();
//         double GetYSpeed();
//         double GetSize();

//         void SetSize();
//         //////////
//         // Setters
//         void SetX(double x);
//         void SetY(double y);
//         void SetXSpeed(double xSpeed);
//         void SetYSpeed(double ySpeed);
//         void SetSize(double size);

//         void move();

//         void move(double screenHeight, double screenWidth);

//         Asteroid(double x, double y, double size, double xSpeed, double ySpeed);
//         bool UpdatePosition(double screenWidth, double screenHeight);
       
//     private:
//     double velocityX;
//     double velocityY;
//     double xSpeed;
//     double ySpeed;
//     double size;
// };

// #endif


#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "FlyingObject.hpp"

class Asteroid : public FlyingObject {
public:
    // Constructeur
    Asteroid(double x, double y, double s, double xSpeed, double ySpeed);

    // Méthodes
    double GetSize() const;

    // Surcharge de la méthode Move pour les astéroïdes
    virtual void Move1(double elapsedTime) ;

    void move(double screenWidth, double screenHeight);

private:
    double size; // La taille de l'astéroïde
};

#endif // ASTEROID_HPP