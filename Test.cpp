#include "sources/SmartTeam.hpp"
#include "sources/Team2.hpp"
#include "sources/Character.hpp"
#include "sources/Team.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Point.hpp"
#include "sources/Ninja.hpp"
#include "doctest.h"
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using namespace ariel;

TEST_CASE("Test 1- Point initialization")
{
    Point p1(1, 2);
    CHECK(p1.getX() == 1);
    CHECK(p1.getY() == 2);
    Point p2(3, 4);
    CHECK(p2.getX() == 3);
    CHECK(p2.getY() == 4);
    CHECK(p1.getX() != p2.getX());
    CHECK(p1.getY() != p2.getY());
}

TEST_CASE("Test 2- Point distance")
{
    Point p1(1, 2);
    Point p2(3, 4);
    CHECK(p1.distance(p2) == sqrt(8));
    CHECK(p2.distance(p1) == sqrt(8));
    Point p3(1, 2);
    CHECK(p1.distance(p3) == 0);
    CHECK(p3.distance(p1) == 0);
}
TEST_CASE("Test 3- Character initialization")
{
    Point p1(1, 2);
    Character c1(p1, "c1");
    CHECK(c1.getName() == "c1");
    CHECK(c1.get_Hit_points() == 100);
    CHECK(c1.getLocation().getX() == 1);
    CHECK(c1.getLocation().getY() == 2);
}
TEST_CASE("Test 4- Character initialization")
{
    Point p1(1, 2);
    Character c1("c1", p1);
    CHECK(c1.getName() == "c1");
    CHECK(c1.getLocation().getX() == 1);
    CHECK(c1.getLocation().getY() == 2);
}

TEST_CASE("Test 5- Ninja initialization")
{
    Point p1(1, 2);
    Ninja n1("n1", p1);
    CHECK(n1.getName() == "n1");
    CHECK(n1.get_Hit_points() == 100);
    CHECK(n1.getLocation().getX() == 1);
    CHECK(n1.getLocation().getY() == 2);
    CHECK(n1.get_speed() == 2);
}

TEST_CASE("Test 6- Ninja initialization")
{
    Point p1(1, 2);
    Ninja n1("n1", p1);
    CHECK(n1.getName() == "n1");
    CHECK(n1.getLocation().getX() == 1);
    CHECK(n1.getLocation().getY() == 2);
    CHECK(n1.get_speed() == 2);
}

TEST_CASE("Test 7- YoungNinja initialization")
{
    Point p1(1, 2);
    YoungNinja n1("n1", p1);
    CHECK(n1.getName() == "n1");
    CHECK(n1.get_Hit_points() == 100);
    CHECK(n1.getLocation().getX() == 1);
    CHECK(n1.getLocation().getY() == 2);
    CHECK(n1.get_speed() == 14);
}
TEST_CASE("Test 8- TrainNinja initialization")
{
    Point p1(1, 2);
    TrainedNinja n1("n1", p1);
    CHECK(n1.getName() == "n1");
    CHECK(n1.get_Hit_points() == 120);
    CHECK(n1.getLocation().getX() == 1);
    CHECK(n1.getLocation().getY() == 2);
    CHECK(n1.get_speed() == 12);
}
TEST_CASE("Test 9- OldNinja initialization")
{
    Point p1(1, 2);
    OldNinja n1("n1", p1);
    CHECK(n1.getName() == "n1");
    CHECK(n1.get_Hit_points() == 150);
    CHECK(n1.getLocation().getX() == 1);
    CHECK(n1.getLocation().getY() == 2);
    CHECK(n1.get_speed() == 8);
}
TEST_CASE("Test 10- Cowboy initialization")
{
    Point p1(1, 2);
    Cowboy n1("n1", p1);
    CHECK(n1.getName() == "n1");
    CHECK(n1.get_Hit_points() == 110);
    CHECK(n1.getLocation().getX() == 1);
    CHECK(n1.getLocation().getY() == 2);
    CHECK(n1.hasboolets() == true);
}
TEST_CASE("Test 11- Team initialization")
{
    Point p1(1, 2);
    OldNinja n1("n1", p1);
    Team t1(&n1);
    CHECK(t1.get_leader()->get_Hit_points() == 150);
    CHECK(t1.get_leader()->getLocation().getX() == 1);
    CHECK(t1.get_leader()->getLocation().getY() == 2);
    }
TEST_CASE("Test 12- Team add")
{
    Point p1(1, 2);
    OldNinja n1("n1", p1);
    Team t1(&n1);
    Point p2(3, 4);
    YoungNinja n2("n2", p2);
    t1.add(&n2);
    CHECK(t1.get_leader()->getName() == "n1");
    CHECK(t1.get_fighters().size() == 2);
}
TEST_CASE("Test 13- SmartTeam")
{
    Point p1(1, 2);
    OldNinja n1("n1", p1);
    SmartTeam t1(&n1);
    Point p2(3, 4);
    YoungNinja n2("n2", p2);
    t1.add(&n2);

    Point p3(5, 6);
    OldNinja n3("n3", p3);
    SmartTeam t2(&n3);
    Point p4(7, 8);
    YoungNinja n4("n4", p4);
    t2.add(&n4);

    t1.attack(&t2);
   
}
TEST_CASE("Test 14- Team2")
{
    Point p1(1, 2);
    OldNinja n1("n1", p1);
    Team2 t1(&n1);
    Point p2(3, 4);
    YoungNinja n2("n2", p2);
    t1.add(&n2);

    Point p3(5, 6);
    OldNinja n3("n3", p3);
    Team2 t2(&n3);
    Point p4(7, 8);
    YoungNinja n4("n4", p4);
    t2.add(&n4);

    t1.attack(&t2);
    CHECK(t1.get_leader()->getName() == "n1");
 
}
TEST_CASE("Test 15- attack")
{
    Point p1(1, 2);
    OldNinja n1("n1", p1);
    Point p2(3, 4);
    YoungNinja n2("n2", p2);
    n1.slash(&n2);
    CHECK(n2.get_Hit_points() == 90);
    CHECK(n2.isAlive() == true);
    CHECK(n1.get_Hit_points() == 150);
    CHECK(n1.isAlive() == true);
    n2.slash(&n1);
    CHECK(n2.get_Hit_points() == 90);
    CHECK(n2.isAlive() == true);
    CHECK(n1.get_Hit_points() == 140);
    CHECK(n1.isAlive() == true);
}
TEST_CASE("Test 16- attack all")
{
    Point p1(1, 2);
    OldNinja n1("n1", p1);
    Point p2(3, 4);
    YoungNinja n2("n2", p2);
    Point p3(5, 6);
    TrainedNinja n3("n3", p3);
    Point p4(7, 8);
    Cowboy n4("n4", p4);
    n1.slash(&n2);
    CHECK(n2.get_Hit_points() == 90);
    CHECK(n2.isAlive() == true);
    CHECK(n1.get_Hit_points() == 150);
    CHECK(n1.isAlive() == true);
    n2.slash(&n1);
    CHECK(n2.get_Hit_points() == 90);
    CHECK(n2.isAlive() == true);
    CHECK(n1.get_Hit_points() == 140);
    CHECK(n1.isAlive() == true);
    n3.slash(&n2);
    CHECK(n3.get_Hit_points() == 120);
    CHECK(n3.isAlive() == true);
    n4.shoot(&n3);
    CHECK(n4.get_Hit_points() == 110);
    CHECK(n4.isAlive() == true);
}
TEST_CASE("Test 17- reload")
{
    Point p1(1, 2);
    Cowboy n1("n1", p1);
    CHECK(n1.hasboolets() == true);
    Point p2(3, 3);
    YoungNinja n2("n2", p2);
    while (n1.hasboolets())
    {
        n1.shoot(&n2);
    }
    CHECK(n1.hasboolets() == false);
    n1.reload();
    CHECK(n1.hasboolets() == true);
}
TEST_CASE("Test 18- Slash")
{
    Point p1(1, 2);
    OldNinja n1("n1", p1);
    Point p2(3, 4);
    YoungNinja n2("n2", p2);
    CHECK(n2.get_Hit_points() == 100);
    n1.slash(&n2);
    CHECK(n2.get_Hit_points() == 69);
    CHECK(n2.isAlive() == true);
    CHECK(n1.get_Hit_points() == 150);
    CHECK(n1.isAlive() == true);
    n2.slash(&n1);
    CHECK(n2.get_Hit_points() == 119);
    CHECK(n2.isAlive() == true);
}
TEST_CASE("Test 19- Shoot")
{
    Point p1(1, 2);
    Cowboy n1("n1", p1);
    CHECK(n1.hasboolets() == true);
    Point p2(3, 4);
    YoungNinja n2("n2", p2);
    CHECK(n2.get_Hit_points() == 100);
    n1.shoot(&n2);
    CHECK(n2.get_Hit_points() == 90);
    CHECK(n2.isAlive() == true);
    CHECK(n1.get_Hit_points() == 110);
    CHECK(n1.isAlive() == true);
}
TEST_CASE("Test 20- slash to far")
{
    Point p1(1, 2);
    OldNinja n1("n1", p1);
    Point p2(33, 42);
    YoungNinja n2("n2", p2);
    CHECK(n2.get_Hit_points() == 100);
    n1.slash(&n2);
    CHECK(n2.get_Hit_points() == 100);
    CHECK(n1.get_Hit_points() == 150);
    n2.slash(&n1);
    CHECK(n1.get_Hit_points() == 150);
}
TEST_CASE("Test 21- Game test")
{
    Point p1(1, 2);
    OldNinja n1("n1", p1);
    Point p2(33.5, 49.2);
    YoungNinja n2("n2", p2);
    double d = n1.distance(n2);
    double d2 = n2.distance(n1);
    CHECK(d == d2);
    while (n2.isAlive() )
    {
        n1.move(&n2);
        n1.slash(&n2);
    }
    CHECK_NOTHROW(n1.move(&n2));
    CHECK_NOTHROW(n1.slash(&n2));
}
TEST_CASE("Test 22- Team aginst one")
{
     Point a(32.3,44),b(1.3,3.5);
    Cowboy *roni = new Cowboy("Roni", a);
    OldNinja *Enamy = new OldNinja("Enamy", b);
    Team team_A(roni); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));
     Team team_B(Enamy);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));
     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
     }
        CHECK(team_A.stillAlive() == 0);
        CHECK(team_B.stillAlive() >= 1);
        CHECK_NOTHROW(team_A.attack(&team_B));
        CHECK_NOTHROW(team_B.attack(&team_A));
}





