#include "battlefield.hpp"

using namespace std;

// ***************************************************************************
// Constructors/Destructors
// ***************************************************************************

Battlefield::Battlefield()
{
  for(int i = 0; i < NUMBER_OF_SECTORS; i++)
  {
    for(int j = 0; j < NUMBER_OF_POSITIONS; j++)
    {
      for(int k = 0; k < MAX_NUMBER_OF_UNITS_PER_ZONE; k++)
      {
        zones[i][j].units[k] = nullptr;
      }
    }
  }
}

// ***************************************************************************
// Functions
// ***************************************************************************

// ---------------------------------------------------------------------------
// moveUnitToZone:
// Moves a unit (from whereever it's currently located) to a new zone.
// ---------------------------------------------------------------------------
void Battlefield::moveUnitToZone(Unit *unitToMove, int destSector, int destPosition)
{
  if(unitToMove == NULL)
  {
    throw runtime_error("Battlefield::moveUnitToZone: Unexpected NULL pointer (unitToMove).");
  }

  if(destSector < 0 || destSector >= NUMBER_OF_SECTORS ||
     destPosition < 0 || destPosition >= NUMBER_OF_POSITIONS)
  {
    throw runtime_error("Battlefield::moveUnitToZone: destSector=" + to_string(destSector) + " or destPosition=" + to_string(destPosition) + " out of range.");
  }

  // remove unit pointer from all zones (if present somewhere)

  for(int i = 0; i < NUMBER_OF_SECTORS; i++)
  {
    for(int j = 0; j < NUMBER_OF_POSITIONS; j++)
    {
      for(int k = 0; k < MAX_NUMBER_OF_UNITS_PER_ZONE; k++)
      {
        if(zones[i][j].units[k] == unitToMove)  // compare pointer addresses
        {
          zones[i][j].units[k] = nullptr;
        }
      }
    }
  }

  // add unit pointer to new zone

  int k = 0;
  bool foundEmptySpaceForNewUnit = false;
  while(k < MAX_NUMBER_OF_UNITS_PER_ZONE)
  {
    if(!zones[destSector][destPosition].units[k])
    {
      zones[destSector][destPosition].units[k] = unitToMove;
      foundEmptySpaceForNewUnit = true;
      break;
    }
    k++;
  }

  if(!foundEmptySpaceForNewUnit)
  {
    throw runtime_error("Battlefield::moveUnitToZone: Can't move unit to this zone, since it's full: sector=" + to_string(destSector) + ", positon=" + to_string(destPosition));
  }
}

// ---------------------------------------------------------------------------
// getNumberOfUnitsInZone:
// Returns the number of units in a given zone.
// ---------------------------------------------------------------------------
int Battlefield::getNumberOfUnitsInZone(int sector, int position)
{
  if(sector < 0 || sector >= NUMBER_OF_SECTORS ||
     position < 0 || position >= NUMBER_OF_POSITIONS)
  {
    throw runtime_error("Battlefield::getNumberOfUnitsInZone: sector=" + to_string(sector) + " or position=" + to_string(position) + " out of range.");
  }

  int numberOfUnitsFound = 0;

  for(int i = 0; i < MAX_NUMBER_OF_UNITS_PER_ZONE; i++)
  {
    if(zones[sector][position].units[i])
    {
      numberOfUnitsFound++;
    }
  }

  return numberOfUnitsFound;
}
