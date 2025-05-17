#ifndef GLOBALS_H
#define GLOBALS_H
#include <iostream>
#include <vector>
#include <memory>
#include "BusinessLogic/character.h"

extern std::vector<std::unique_ptr<Character>> characters;
extern const QString abilities[4][5];
extern const QString skills[12];
extern int currentCharacter;

#endif // GLOBALS_H
