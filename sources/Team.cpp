#include "Team.hpp"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

namespace ariel{
    Team::Team(Character *leader)
    {
        this->leader = leader;
        this->fighters.push_back(leader);
    }
    Team::~Team()
    {
    }
    void Team::add(Character *fighter_to_add)
    {
        this->fighters.push_back(fighter_to_add);
    }
    void Team::attack(Team *enemy)
    {

    }
    void Team::print()
    { 
        // for (size_t i = 0; i < fighters.size(); i++)
        // {
        //     cout << fighters[i]->print() << " ";
        // }
        // cout << endl;
    }
    void Team::remove(Character *fighter_to_remove)
    {
        for (size_t i = 0; i < fighters.size(); i++)
        {
            if (fighters[i] == fighter_to_remove)
            {
                fighters.erase(fighters.begin() + (int)i);
            }
        }
    }
    Character *Team::get_leader()
    {
        if (this->leader->get_Hit_points() > 0)
        {
            return this->leader;
        }
        else
        {
           
        return nullptr;}
    }
    vector<Character *> Team::get_fighters()
    {
        return this->fighters;
    }
    Character *Team::getByOrder()
    {
        return this->leader;
    }
    int Team::stillAlive()
    {
        return 0;
        int counter = 0;
        for (size_t i = 0; i < fighters.size(); i++)
        {
            if (fighters[i]->get_Hit_points() > 0)
            {
                counter++;
            }
        }
        return counter;
    }
}