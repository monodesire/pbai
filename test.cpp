#include <iostream>
#include <cassert>
#include "statemachine.hpp"
#include "human.hpp"
#include "troop.hpp"
#include "battlefield.hpp"
#include "enums.hpp"
#include "cli.hpp"

using namespace std;
using namespace cli;

void main()
{
  bool caughtException = false;

  cout << "------------------" << endl;
  cout << "Running unit tests" << endl;
  cout << "------------------" << endl;
  cout << endl;

  // ***************************************************************************
  cout << "TEST: Class StateMachine" << endl;
  // ***************************************************************************

  StateMachine stateMachine = StateMachine(globalEnums::Player::HUMAN);

  assert(stateMachine.getActivePlayer() == globalEnums::Player::HUMAN);
  assert(stateMachine.getActivePlayerInText().compare("Human") == 0);
  assert(stateMachine.getCurrentState() == globalEnums::CurrentState::UNIT_REDEPLOYMENT);
  assert(stateMachine.getCurrentStateInText().compare("Unit redeployment") == 0);
  assert(stateMachine.getPlayerOne() == globalEnums::Player::HUMAN);

  // ***************************************************************************
  cout << "TEST: Class Human" << endl;
  // ***************************************************************************

  Human human = Human();

  vector<Troop> troops;

  Troop newTroop;
  newTroop.name = "FakeName1";
  newTroop.engagementDice[0] = 2;
  newTroop.engagementDice[1] = 3;
  newTroop.engagementDice[2] = 4;
  newTroop.shootingDice[0] = 3;
  newTroop.shootingDice[1] = -1;
  newTroop.shootingDice[2] = -1;
  newTroop.woundPoints = 1;
  newTroop.wounds = 0;
  troops.push_back(newTroop);

  newTroop.name = "FakeName2";
  newTroop.engagementDice[0] = 1;
  newTroop.engagementDice[1] = 6;
  newTroop.engagementDice[2] = -1;
  newTroop.shootingDice[0] = 4;
  newTroop.shootingDice[1] = 1;
  newTroop.shootingDice[2] = -1;
  newTroop.woundPoints = 2;
  newTroop.wounds = 0;
  troops.push_back(newTroop);

  newTroop.name = "FakeName3";
  newTroop.engagementDice[0] = -1;
  newTroop.engagementDice[1] = -1;
  newTroop.engagementDice[2] = -1;
  newTroop.shootingDice[0] = 5;
  newTroop.shootingDice[1] = 1;
  newTroop.shootingDice[2] = 3;
  newTroop.woundPoints = 1;
  newTroop.wounds = 0;
  troops.push_back(newTroop);

  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);

  caughtException = false;
  try { human.getUnit(100); }
  catch(exception& e)
  {
    caughtException = true;
    string exceptionMessage = e.what();
    assert(exceptionMessage.compare("Player::getUnit: unitIndex=100 out of range.") == 0);
  }
  assert(caughtException);

  assert(human.getUnit(0) != NULL);

  // test max number of units per player

  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);
  human.createUnit(troops);

  caughtException = false;
  try { human.createUnit(troops); }
  catch(exception& e)
  {
    caughtException = true;
    string exceptionMessage = e.what();
    assert(exceptionMessage.compare("Player::createUnit: Max number of units reached: 20") == 0);
  }
  assert(caughtException);

  // ***************************************************************************
  cout << "TEST: Class Battlefield" << endl;
  // ***************************************************************************

  Battlefield battlefield = Battlefield();

  caughtException = false;
  try { battlefield.moveUnitToZone(human.getUnit(0), 0, 110); }
  catch(exception& e)
  {
    caughtException = true;
    string exceptionMessage = e.what();
    assert(exceptionMessage.compare("Battlefield::moveUnitToZone: destSector=0 or destPosition=110 out of range.") == 0);
  }
  assert(caughtException);

  assert(battlefield.getNumberOfUnitsInZone(0, 0) == 0);
  battlefield.moveUnitToZone(human.getUnit(0), 0, 0);
  battlefield.moveUnitToZone(human.getUnit(1), 0, 0);
  battlefield.moveUnitToZone(human.getUnit(2), 0, 0);
  battlefield.moveUnitToZone(human.getUnit(3), 0, 0);
  battlefield.moveUnitToZone(human.getUnit(4), 0, 0);
  battlefield.moveUnitToZone(human.getUnit(5), 0, 0);
  assert(battlefield.getNumberOfUnitsInZone(0, 0) == 6);

  caughtException = false;
  try { battlefield.moveUnitToZone(NULL, 0, 0); }
  catch(exception& e)
  {
    caughtException = true;
    string exceptionMessage = e.what();
    assert(exceptionMessage.compare("Battlefield::moveUnitToZone: Unexpected NULL pointer (unitToMove).") == 0);
  }
  assert(caughtException);

  // make sure that nothing strange happens if we try to add the same unit twice into the same zone

  assert(battlefield.getNumberOfUnitsInZone(2, 2) == 0);
  battlefield.moveUnitToZone(human.getUnit(0), 2, 2);
  assert(battlefield.getNumberOfUnitsInZone(2, 2) == 1);
  battlefield.moveUnitToZone(human.getUnit(0), 2, 2);
  assert(battlefield.getNumberOfUnitsInZone(2, 2) == 1);

  caughtException = false;
  try { battlefield.getNumberOfUnitsInZone(100, 5); }
  catch(exception& e)
  {
    caughtException = true;
    string exceptionMessage = e.what();
    assert(exceptionMessage.compare("Battlefield::getNumberOfUnitsInZone: sector=100 or position=5 out of range.") == 0);
  }
  assert(caughtException);

  // ***************************************************************************
  cout << "TEST: CLI functions" << endl;
  // ***************************************************************************

  assert(trimString("  qwerty     ").compare("qwerty") == 0);
  assert(trimString("  qwerty  asdf   ").compare("qwerty  asdf") == 0);
  assert(trimString("qwerty  asdf   ").compare("qwerty  asdf") == 0);
  assert(trimString("  qwerty  asdf").compare("qwerty  asdf") == 0);
  assert(trimString("qwerty  asdf").compare("qwerty  asdf") == 0);

  CliResult cliResult = processUserInput("asdf");
  assert(cliResult.action == Action::INVALID);

  cliResult = processUserInput("quiT ");
  assert(cliResult.action == Action::QUIT);

  cliResult = processUserInput(" inFo");
  assert(cliResult.action == Action::INFO);

//  cliResult = processUserInput(" inFo units");
//  assert(cliResult.action == Action::INFO_UNITS);
}
