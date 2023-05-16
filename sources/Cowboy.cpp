#include "Cowboy.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel{
    Cowboy::Cowboy(Point Current_location, string name) : Character(Current_location, name,110), num_of_bullets(6) 
    {}

    Cowboy::Cowboy(string name, Point Current_location): Character(Current_location, name,110), num_of_bullets(6)
    {
    }


    Cowboy::~Cowboy()
    {
    }

    void Cowboy::shoot(Character *enemy)
    {
        if (num_of_bullets > 0)
        {
            num_of_bullets--;
            enemy->set_Hit_points(enemy->get_Hit_points() - 10);
        }
        else
        {
            cout << "No bullets left" << endl;
        }
    }
    string Cowboy::print()
    {
        return "C";
    }

    int Cowboy::get_num_of_bullets()
    {
        return num_of_bullets;
    }
    void Cowboy::reload()
    {
        num_of_bullets = 6;
    }
    bool Cowboy::isAlive()
    {
        if (this->get_Hit_points() > 0)
        {
            return true;
        }
        return false;
    }
    bool Cowboy::hasboolets()
    {
        if (num_of_bullets > 0)
        {
            return true;
        }
        return false;
    }
    
}