#ifndef MAGE_H
#define MAGE_H
#include "BusinessLogic_global.h"
#include "character.h"
#include <Qstring>
class BUSINESSLOGIC_EXPORT Mage:public Character
{

public:
    Mage();
    Mage(int str,
            int dex,
            int cons,
            int inte,
            int ws,
            int rizz,
            int ac,
            int hp,
            bool skills[12],
            const QString& name,
            const QString& race);
    virtual QString toString() const override;
    virtual QString first_ability() override;
    virtual QString second_ability() override;
    virtual QString third_ability() override;
    virtual QString fourth_ability() override;
    virtual QString fifth_ability() override;
    void save(QDataStream& out) const;
    static Mage* load(QDataStream& in);

};

#endif // MAGE_H
