#include "cli.hpp"

namespace cli
{
  // ---------------------------------------------------------------------------
  // trimString:
  // Removes leading and trailing whitespaces of a string.
  // ---------------------------------------------------------------------------
  string trimString(const string &s)
  {
    string s2 = s;
    string s3 = s;
    smatch m;
    regex e("^\\s*(.*)", regex_constants::icase | regex_constants::ECMAScript);

    if(regex_match(s, m, e))
    {
      s2 = m.str(1);
      s3 = s2;
    }

    regex e2("(.*?)\\s*$", regex_constants::icase | regex_constants::ECMAScript);
    if(regex_match(s2, m, e2))
    {
      s3 = m.str(1);
    }

    return s3;
  }

  // ---------------------------------------------------------------------------
  // waitUserInput:
  // Waits for a keyboard input. An carriage return will end the input.
  // ---------------------------------------------------------------------------
  string waitUserInput(void)
  {
    string userInput;

    cout << ">>> ";
    getline(cin, userInput);

    return trimString(userInput);
  }

  // ---------------------------------------------------------------------------
  // processUserInput:
  // Takes a user input, parses it and returns a result that can be understood
  // by the game logic.
  // ---------------------------------------------------------------------------
  CliResult processUserInput(string input)
  {
    CliResult cliResult;
    cliResult.action = Action::INVALID;
    smatch m;

    // check for different commands

    // --- quit ---

    if(regex_match(input, m, regex("^\\s*quit\\s*$", regex_constants::icase | regex_constants::ECMAScript)))
    {
      cliResult.action = Action::QUIT;
      return cliResult;
    }

    // --- info ---

    if(regex_match(input, m, regex("^\\s*info\\s*$", regex_constants::icase | regex_constants::ECMAScript)))
    {
      cliResult.action = Action::INFO;
      return cliResult;
    }

    return cliResult;
  }
}
