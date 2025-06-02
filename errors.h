#include <exception>
using namespace std;
#ifndef ERRORS_H
#define ERRORS_H
class NoFileException: public exception
{
public:
    NoFileException():exception("Nie wybrano pliku .txt!"){}
};

class NoCharacterException: public exception
{
public:
    NoCharacterException():exception("Nie wybrano żadnej postaci"){}
};

class WrongFormatException: public exception
{
public:
    WrongFormatException():exception("Nieprawidłowy format pliku."){}
};

#endif // ERRORS_H
