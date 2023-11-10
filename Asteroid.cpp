// ///////////////////////////////////////////////////
// //                   Framework
// // Bibliothèque encapsulant l'utilisation de SDL 2

#include "Asteroid.hpp"
#include "framework.hpp"
#include <iostream>
#include "Missile.hpp"
#include <cmath>

// /////////////// 
// // Constructeur 
// // ------- 
// // * x, y : position dans l'écran 
// // * size : diamètre de l'objet 
// // * xSpeed, ySpeed : vecteur de vitesse de l'objet 

// void Asteroid::move()
// {
//     // Mettez ici la logique pour déplacer l'astéroïde
//     x += xSpeed;
//     y += ySpeed;
// }




// double Asteroid::GetX()
// {
//     return x;
// }

// double Asteroid::GetY() 
// {
//     return y;
// }

// double Asteroid::GetSize() 
// {
//     return size; // or whatever the member variable's name is
// }

// void SetSize(double s) {
//         size = s;
//     }


// Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed)
// : FlyingObject(x, y, size, xSpeed, ySpeed)
// {

// };


// bool Asteroid::UpdatePosition(double screenWidth, double screenHeight) {
//     // Mettez à jour la position en fonction de la vitesse
    
//     x += xSpeed;
//     y += ySpeed;

//     // Ajoutez ici des conditions pour garder le vaisseau dans les limites de l'écran si nécessaire

//     if (x > screenWidth)
//     {
//         x = 0;
//     }
//      if (x < 0)
//     {
//         x = screenWidth;
//     }
//     if (y > screenHeight)
//     {
//         y = 0;
//     }
//       if (y < 0)
//     {
//         y = screenHeight;
//     }

//     // Vérifiez si l'objet est sorti des limites de l'écran
//     if (x > screenWidth || x < 0 || y > screenHeight || y < 0) {
//         xSpeed =0;
//         ySpeed =0;
//         return true; // L'objet est sorti de l'écran
//     } else {
//         return false; // L'objet est toujours à l'intérieur de l'écran
//     }
// }

// void Asteroid::Move(double screenWidth, double screenHeight)
// {
//     x += xSpeed;
//     y += ySpeed;
// };


#include "Asteroid.hpp"

// Constructeur
Asteroid::Asteroid(double x, double y, double s, double xSpeed, double ySpeed)
    : FlyingObject(x, y, s, xSpeed, ySpeed), size(s) 
{}

double Asteroid::GetSize() const {
    return size;
}

void Asteroid::Move1(double elapsedTime) {
    // Mettre ici la logique de mouvement pour les astéroïdes
    // Par exemple, pour un mouvement linéaire :
    x += xSpeed * elapsedTime;
    y += ySpeed * elapsedTime;
}


void Asteroid::move(double screenHeight, double screenWidth)
{
    // Mettez ici la logique pour déplacer l'astéroïde
    // Par exemple :
    x += xSpeed;
    y += ySpeed;


//    if (x > screenWidth || x < 0 )
//     {
//        x  = 0;
//     }

//     if (y > screenHeight || y < 0) 
//     {
//         y=0;
//     }
}