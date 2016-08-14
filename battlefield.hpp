#ifndef BATTLEFIELD_HPP
#define BATTLEFIELD_HPP

#include <string>
#include <vector>
#include "enums.hpp"
#include "unit.hpp"

class Battlefield
{
private:
  struct Zone
  {
    Unit* units[MAX_NUMBER_OF_UNITS_PER_ZONE];
  };

  Zone zones[NUMBER_OF_SECTORS][NUMBER_OF_POSITIONS];
  // TODO: Explain sectors and positions here.

public:
  Battlefield();
  void moveUnitToZone(Unit *unitToMove, int destSector, int destPosition);
  int getNumberOfUnitsInZone(int sector, int position);
};

#endif
