#include <iostream>
#include <string>
#include "framework.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "Spaceship.hpp"
#include <cmath>
#include <random>
#include <ctime>
#include <SDL.h>

const double MISSILE_SPEED = 5.0;
const int NUM_ASTEROIDS = 6;

int main(int argc, char* argv[]) {
    Framework fmw(60, 32, 20);

    double screenHeight = fmw.GetScreenHeight();
    double screenWidth = fmw.GetScreenWidth();
    
    Spaceship spaceship(screenWidth/2, screenHeight/2, 30.0, 0.0);
    
    double missileStartX = 340;
    double missileStartY = spaceship.GetY() + spaceship.GetSize() / 2 + 10;
    Missile missile(missileStartX, missileStartY, 10, 0, 0, 0);

    std::vector<Asteroid> asteroids;

    std::mt19937 gen(time(nullptr));
    std::uniform_real_distribution<> disPos(0.0, 1.0);
    std::uniform_real_distribution<> disSize(50.0, 150.0);

    time_t startTime = time(nullptr);
  
    for (int i = 0; i < NUM_ASTEROIDS; i++) {
        double x = disPos(gen) * screenWidth;
        double y = disPos(gen) * screenHeight;
        double size = disSize(gen);
        asteroids.push_back(Asteroid(x, y, size, disPos(gen), disPos(gen)));
    }

    bool collisionDetected = false;

    while (1) 
    {
        int input = fmw.GetInput();
        fmw.Update();

        switch (input)
        {
            case SDLK_ESCAPE: 
                return 0;         
                break;
            case SDLK_UP:
                spaceship.SpeedUp(1);
                break;
            case SDLK_DOWN:
                spaceship.SpeedDown(1);
                break;
            case SDLK_RIGHT:
                spaceship.Rotate(-15.0);
                break;
            case SDLK_LEFT:
                spaceship.Rotate(15.0);
                break;
            case SDLK_SPACE:
                missile.SetX(spaceship.GetX());
                missile.SetY(spaceship.GetY());
                missile.SetXSpeed(cos(spaceship.GetAngle() * M_PI / 180.0) * MISSILE_SPEED); 
                missile.SetYSpeed(-sin(spaceship.GetAngle() * M_PI / 180.0) * MISSILE_SPEED);
                break;
            default:
                break;
        }

        missile.move(screenWidth, screenHeight);
        fmw.DrawMissile(missile.GetX(), missile.GetY());

        time_t currentTime = time(nullptr);
        if (currentTime - startTime >= 7) {
            for (int i = 0; i < NUM_ASTEROIDS; i++) {
                double x = disPos(gen) * screenWidth;
                double y = disPos(gen) * screenHeight;
                double size = disSize(gen);
                asteroids.push_back(Asteroid(x, y, size, disPos(gen), disPos(gen)));
            }
            startTime = currentTime;
        }

        for (Asteroid &asteroid : asteroids) {
            if (FlyingObject::Collide(spaceship, asteroid)) {
                std::cout << "Le vaisseau spatial a heurté un astéroïde!" << std::endl;
                collisionDetected = true;
            }
            asteroid.move(screenWidth, screenHeight);
            fmw.DrawAsteroid(asteroid.GetX(), asteroid.GetY(), asteroid.GetSize());
        }

        spaceship.move(screenHeight, screenWidth);
        fmw.DrawShip(spaceship.GetX(), spaceship.GetY(), spaceship.GetAngle(), 1, collisionDetected);

        collisionDetected = false; // Reset collision flag for the next frame
    }

    return 0;
}
