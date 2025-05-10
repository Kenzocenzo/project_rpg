#ifndef WARRIOR_H
#define WARRIOR_H
#include "BusinessLogic_global.h"
#include "character.h"
#include <Qstring>
class BUSINESSLOGIC_EXPORT Warrior:public Character
{
protected:
    QString className = "Wojownik";
    int abilityLvl=0;
public:
    Warrior();
    Warrior(int str,
            int dex,
            int cons,
            int inte,
            int ws,
            int rizz,
            int ac,
            int hp,
            const bool skills[12],
            const QString& name,
            const QString& race);
    virtual QString toString() const override;

};

#endif // WARRIOR_H
