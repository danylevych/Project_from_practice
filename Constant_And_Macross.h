#pragma once
#ifndef _CONSTANT_AND_MACROSS_
#define _CONSTANT_AND_MACROSS_

#include <string>
#include <Windows.h>

extern int _stateMenu;
extern std::string _choose_format_file;
#pragma region Select Console Color

extern HANDLE hConsole;
#define GET_CONSOLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define U_COLOR SetConsoleTextAttribute(hConsole, 10); // Green - User Console Color
#define A_COLOR  SetConsoleTextAttribute(hConsole, 15);// White - Application Console Color
#define E_COLOR  SetConsoleTextAttribute(hConsole, 4);// Red - Error Console Color
#define S_COLOR  SetConsoleTextAttribute(hConsole, 2);

#pragma endregion Select Console Color

#endif
