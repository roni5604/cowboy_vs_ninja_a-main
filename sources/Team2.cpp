#include "Team2.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

namespace ariel{
    Team2::Team2(Character *leader):Team(leader)
    {
    
    }
    Team2::~Team2()
    {

    }
    Character *Team2::getByOrder()
    {
        return this->get_leader();
    }
}