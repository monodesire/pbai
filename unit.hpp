#ifndef UNIT_HPP
#define UNIT_HPP

#include <vector>
#include "troop.hpp"

struct Unit
{
  vector<Troop> troops;
  int numberOfOrderTokens;
};

#endif
