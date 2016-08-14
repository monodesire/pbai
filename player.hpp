#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "troop.hpp"
#include "unit.hpp"

class Player
{
protected:
  Unit *units[MAX_NUMBER_OF_UNITS_PER_PLAYER];
public:
  Player();
  ~Player();
  void createUnit(vector<Troop> troops);
  Unit* getUnit(int unitIndex);
};

#endif
