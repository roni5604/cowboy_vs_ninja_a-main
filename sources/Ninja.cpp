#include "Ninja.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    Ninja::Ninja(string name, Point Current_location):Character(Current_location,name),speed(2)
    {
        
    }

    Ninja::~Ninja()
    {
    }

    void Ninja::move(Character *enemy)
    {
    }

    void Ninja::slash(Character *enemy)
    {
        if(this->isAlive() && (enemy->get_Hit_points() > 0))
        {
            if (this->getLocation().distance(enemy->getLocation()) <= 1)
            {
                enemy->set_Hit_points(enemy->get_Hit_points() - 31) ;
            }
            // else
            // {
            //     cout << "Enemy is too far away" << endl;
            // }
        }
        else
        {
            cout << "One of the characters is dead" << endl;
        }
    }
    int Ninja::get_speed()
    {
        return this->speed;
    }
    void Ninja::set_speed(int speed)
    {
        this->speed = speed;
    }
    bool ariel::Ninja::isAlive()
    {
        return false;
        if (this->get_Hit_points() > 0)
        {
            return true;
        }
        return false;
    }
}