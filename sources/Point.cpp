#include <iostream>
#include <cmath>
#include "Point.hpp"
using namespace std;

namespace ariel
{

    Point::Point(double x_Location, double y_Location) : x_Location(x_Location), y_Location(y_Location) {}

    double Point::distance(const Point &other) const
    {
        return std::sqrt(std::pow(x_Location - other.x_Location, 2) + std::pow(y_Location - other.y_Location, 2));
    }

    Point::Point(const Point &other)
    {
        x_Location = other.x_Location;
        y_Location = other.y_Location;
    }

    Point &Point::operator=(const Point &other)
    {
        if (this != &other)
        {
            x_Location = other.x_Location;
            y_Location = other.y_Location;
        }
        return *this;
    }

    Point::~Point()
    {
        x_Location = 0;
        y_Location = 0;
    }

    void Point::print() const
    {
        std::cout << "(" << x_Location << ", " << y_Location << ")" << std::endl;
    }

    Point Point::moveTowards(const Point &destination, double maxDistance) const
    {
        double dist = distance(destination);
        if (dist <= maxDistance)
        {
            return destination;
        }
        else
        {
            double fraction = maxDistance / dist;
            return Point(x_Location + fraction * (destination.x_Location - x_Location), y_Location + fraction * (destination.y_Location - y_Location));
        }
    }

    double Point::getX() const
    {
        return x_Location;
    }

    double Point::getY() const
    {
        return y_Location;
    }

    void Point::setX(double x_Location)
    {
        this->x_Location = x_Location;
    }

    void Point::setY(double y_Location)
    {
        this->y_Location = y_Location;
    }
}
