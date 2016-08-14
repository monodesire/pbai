#include "player.hpp"

// ***************************************************************************
// Constructor/Destructors
// ***************************************************************************

Player::Player()
{
  for(int i = 0; i < MAX_NUMBER_OF_UNITS_PER_PLAYER; i++)
  {
    units[i] = NULL;
  }
}

Player::~Player()
{
  for(int i = 0; i < MAX_NUMBER_OF_UNITS_PER_PLAYER; i++)
  {
    delete units[i];
  }
}

// ***************************************************************************
// Functions
// ***************************************************************************

// ---------------------------------------------------------------------------
// createUnit:
// Creates and adds a unit to a player. Given to this function are the troops
// that will be forming the newly created unit.
// ---------------------------------------------------------------------------
void Player::createUnit(vector<Troop> troops)
{
  int index = 0;
  while(units[index] != NULL)
  {
    index++;
    if(index >= MAX_NUMBER_OF_UNITS_PER_PLAYER)
    {
      throw runtime_error("Player::createUnit: Max number of units reached: " + to_string(MAX_NUMBER_OF_UNITS_PER_PLAYER));
    }
  }

  units[index] = new Unit;
  units[index]->numberOfOrderTokens = 0;

  for(size_t i = 0; i < troops.size(); i++)
  {
    units[index]->troops.push_back(troops.at(i));
  }
}

// ---------------------------------------------------------------------------
// getUnit:
// Returns a pointer to a unit at a given index. May return NULL if there is
// no unit at requested index.
// ---------------------------------------------------------------------------
Unit* Player::getUnit(int unitIndex)
{
  if(unitIndex < 0 || unitIndex > MAX_NUMBER_OF_UNITS_PER_PLAYER)
  {
    throw runtime_error("Player::getUnit: unitIndex=" + to_string(unitIndex) + " out of range.");
  }

  return units[unitIndex];
}
