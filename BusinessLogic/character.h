#ifndef CHARACTER_H
#define CHARACTER_H
#include <QString>

#include "BusinessLogic_global.h"
#include <iostream>
class BUSINESSLOGIC_EXPORT Character
{
protected:
    int str;
    int dex;
    int cons;
    int inte;
    int ws;
    int rizz;
    int ac;
    int hp;
    int max_hp;
    bool skills[12];
    QString name;
    QString race;
public:
    Character();
    virtual ~Character() = default;
    Character(int str,
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
    virtual QString toString() const;
    // Gettery
    int getStr() const;
    int getDex() const;
    int getCons() const;
    int getInte() const;
    int getWs() const;
    int getRizz() const;
    int getAc() const;
    int getHp() const;
    int getMaxHp() const;
    bool getSkill(int index) const;
    QString getName() const;
    QString getRace() const;

    // Settery
    void setStr(int value);
    void setDex(int value);
    void setCons(int value);
    void setInte(int value);
    void setWs(int value);
    void setRizz(int value);
    void setAc(int value);
    void setHp(int value);
    void setMaxHp(int value);
    void setSkill(int index, bool value);
    void setName(const QString& value);
    void setRace(const QString& value);

};

#endif // CHARACTER_H
