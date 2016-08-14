#include <iostream>
#include "defines.hpp"
#include "statemachine.hpp"
#include "battlefield.hpp"
#include "cli.hpp"
#include "player.hpp"
#include "human.hpp"

using namespace std;
using namespace cli;

// ---------------------------------------------------------------------------
// main()
// ---------------------------------------------------------------------------
void main()
{
  try
  {
    cout << "---------------------------------------" << endl;
    cout << "Pockets Battles AI - A Foolish Opponent" << endl;
    cout << "---------------------------------------" << endl << endl;

    StateMachine stateMachine = StateMachine(globalEnums::Player::HUMAN);
    Battlefield battlefield = Battlefield();
    Player players[NUMBER_OF_PLAYERS];
    players[globalEnums::Player::HUMAN] = Human();
    //players[globalEnums::Player::COMPUTER] = Computer();
    CliResult cliResult;

    do
    {
      cliResult = processUserInput(waitUserInput());

      if(cliResult.action == Action::INVALID)
      {
        cout << "Error! Invalid input." << endl << endl;
      }
      else if(cliResult.action == Action::INFO)
      {
        cout << "Active player: " << stateMachine.getActivePlayerInText() << endl;
        cout << "Current state: " << stateMachine.getCurrentStateInText() << endl;
        cout << endl;
      }

      // TODO: Player turn ideas:
      //         * list units
      //         * move unit
      //         * add wound markers to troops
      //         * add order tokens to units
      //         * attack

    }
    while(cliResult.action != Action::QUIT);
  }
  catch(exception& e)
  {
    cout << "ERROR! There was an execution problem: " << e.what() << endl;
  }
}
