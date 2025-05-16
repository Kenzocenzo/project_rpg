#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <memory>
#include "BusinessLogic/character.h"

extern std::vector<std::unique_ptr<Character>> postaci;
extern const QString abilities[4][5];
extern const QString skills[12];

#endif // GLOBALS_H
