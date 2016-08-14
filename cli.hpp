#ifndef CLI_HPP
#define CLI_HPP

#include <iostream>
#include <string>
#include <regex>

using namespace std;

namespace cli
{
  enum Action
  {
    INVALID,
    QUIT,
    INFO,
    INFO_UNITS
  };

  struct CliResult
  {
    Action action;
  };

  string trimString(const string &s);
  string waitUserInput(void);
  CliResult processUserInput(string);
}

#endif
