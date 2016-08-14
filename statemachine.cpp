#include "statemachine.hpp"

// ***************************************************************************
// Constructors/Destructors
// ***************************************************************************

StateMachine::StateMachine(globalEnums::Player playerOne)
{
  this->playerOne = playerOne;
  this->activePlayer = playerOne;
  this->currentState = globalEnums::CurrentState::UNIT_REDEPLOYMENT;
}

// ***************************************************************************
// Functions
// ***************************************************************************

// ---------------------------------------------------------------------------
// getPlayerOne:
// Returns player one.
// ---------------------------------------------------------------------------
globalEnums::Player StateMachine::getPlayerOne(void)
{
  return playerOne;
}

// ---------------------------------------------------------------------------
// getActivePlayer:
// Returns the active player.
// ---------------------------------------------------------------------------
globalEnums::Player StateMachine::getActivePlayer(void)
{
  return activePlayer;
}

// ---------------------------------------------------------------------------
// getActivePlayerInText:
// Returns the active player, in textual format.
// ---------------------------------------------------------------------------
string StateMachine::getActivePlayerInText(void)
{
  string returnValue = "INVALID PLAYER";

  if(activePlayer == globalEnums::Player::HUMAN)
  {
    return "Human";
  }
  else if(activePlayer == globalEnums::Player::COMPUTER)
  {
    return "Computer";
  }

  return returnValue;
}

// ---------------------------------------------------------------------------
// getCurrentState:
// Returns the current state of the state machine.
// ---------------------------------------------------------------------------
globalEnums::CurrentState StateMachine::getCurrentState(void)
{
  return currentState;
}

// ---------------------------------------------------------------------------
// getCurrentStateInText:
// Returns the current state of the state machine, in textual format.
// ---------------------------------------------------------------------------
string StateMachine::getCurrentStateInText(void)
{
  string returnValue = "INVALID STATE";

  if(currentState == globalEnums::CurrentState::UNIT_REDEPLOYMENT)
  {
    return "Unit redeployment";
  }

  return returnValue;
}
