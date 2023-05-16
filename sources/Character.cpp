#include "Character.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    Character::Character(Point Current_location, string name) : Current_location(Current_location), name(name), hit_points(0) 
    {
    }
    Character::Character(string name, Point Current_location)
    {
        Character(Current_location, name);
    }
    Character::Character(Point Current_location, string name, int hit_points) : Current_location(Current_location), name(name), hit_points(hit_points)
    {
    }

    Character::Character(Character const &other)
    {
        Current_location = other.Current_location;
        name = other.name;
        hit_points = other.hit_points;
    }

    Character &Character::operator=(Character const &other)
    {
        if (this != &other)
        {
            Current_location = other.Current_location;
            name = other.name;
            hit_points = other.hit_points;
        }
        return *this;
    }
    Character::~Character()
    {
        this->name = "";
        this->hit_points = 0;
        this->Current_location = Point(0, 0);
    }
    double Character::distance(Character &other)
    {
        return Current_location.distance(other.Current_location);
    }
    void Character::hit(int damage)
    {
        hit_points -= damage;
    }
    string Character::getName()
    {
        return name;
    }
    int Character::get_Hit_points()
    {
        return hit_points;
    }
    Point Character::getLocation()
    {
        return Current_location;
    }
    string Character::print()
    {
        return name + " " + "have points :  "+to_string(hit_points) + " " + to_string(Current_location.getX()) + " " + to_string(Current_location.getY());
    }
    void Character::moveTowards(Point dest, double maxDistance)
    {
        if (Current_location.distance(dest) <= maxDistance)
        {
            Current_location = dest;
        }
        else
        {
            Current_location = Current_location.moveTowards(dest, maxDistance);
        }
    }
    void Character::setLocation(Point newLocation)
    {
        Current_location = newLocation;
    }
    void Character::setName(string newName)
    {
        name = newName;
    }
    void Character::set_Hit_points(int new_Hit_points)
    {
        hit_points = new_Hit_points;
    }
}
