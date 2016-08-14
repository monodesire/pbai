#ifndef TROOP_HPP
#define TROOP_HPP

#include <string>
#include "defines.hpp"

using namespace std;

struct Troop
{
  string name;
  int engagementDice[3];
  int shootingDice[3];
  int woundPoints;
  int wounds;
};

#endif
