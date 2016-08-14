REM Build and run unit tests.

cl /W4 /EHsc test.cpp statemachine.cpp cli.cpp human.cpp player.cpp battlefield.cpp /link /out:test.exe
