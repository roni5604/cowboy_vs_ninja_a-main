#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include "Ninja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"
#include <vector>
using namespace std;

namespace ariel
{
    class Team
    {
    private:
        Character *leader;
        vector<Character *> fighters;

    public:
        Team(Character *leader);
        ~Team();
        void add(Character *fighter_to_add);
        void attack(Team *enemy);
        void print();
        void remove(Character *fighter_to_remove);
        Character *get_leader();
        vector<Character *> get_fighters();
        virtual Character *getByOrder();
        int stillAlive();
        
    };
}