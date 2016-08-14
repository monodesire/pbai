#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <string>
#include "enums.hpp"

using namespace std;

class StateMachine
{
private:
  globalEnums::Player playerOne;
  globalEnums::Player activePlayer;
  globalEnums::CurrentState currentState;
public:
  StateMachine(globalEnums::Player playerOne);
  globalEnums::Player getPlayerOne(void);
  globalEnums::Player getActivePlayer(void);
  string getActivePlayerInText(void);
  globalEnums::CurrentState getCurrentState(void);
  string getCurrentStateInText(void);
};

#endif
