REM Script for building in Microsoft's Developer Command Prompt for VS2012.

cl /W4 /EHsc pbai.cpp statemachine.cpp cli.cpp human.cpp player.cpp battlefield.cpp /link /out:pbai.exe
