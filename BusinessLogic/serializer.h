#ifndef SERIALIZER_H
#define SERIALIZER_H
#include "BusinessLogic_global.h"
#include <vector>
#include <memory>
#include <QString>
#include "character.h"
class BUSINESSLOGIC_EXPORT  Serializer
{
public:
    static void saveCharactersTxt(const std::vector<std::unique_ptr<Character>>& characters, const QString& filename);
    static std::vector<std::unique_ptr<Character>> loadCharactersTxt(const QString& filename);
};

#endif // SERIALIZER_H
