#ifndef RANGER_H
#define RANGER_H

#include "BusinessLogic_global.h"
#include "character.h"
#include <Qstring>
class BUSINESSLOGIC_EXPORT Ranger:public Character
{
protected:
    QString className = "Łucznik";
public:
    Ranger();
    Ranger(int str,
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
    virtual QString first_ability() override;
    virtual QString second_ability() override;
    virtual QString third_ability() override;
    virtual QString fourth_ability() override;
    virtual QString fifth_ability() override;

};

#endif // RANGER_H
