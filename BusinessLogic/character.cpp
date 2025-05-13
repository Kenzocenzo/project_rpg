#include "character.h"
#include <algorithm>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <time.h>
#include "warrior.h"
#include "ranger.h"
#include "mage.h"
#include "brainrotter.h"
#include <vector>
#include <memory>
Character::Character() {}
Character::Character(int str,
          int dex,
          int cons,
          int inte,
          int ws,
          int rizz,
          int ac,
          int hp,
          bool skills[12],
          const QString& name,
          const QString& race)
    : str(str),
    dex(dex),
    cons(cons),
    inte(inte),
    ws(ws),
    rizz(rizz),
    ac(ac),
    hp(hp),
    max_hp(hp),
    name(name),
    race(race)
{
    std::copy(skills, skills + 12, this->skills);
}

QString Character::toString() const {
    QString result;
    result += QString("Imię: %1\n").arg(name);
    result += QString("Rasa: %1\n").arg(race);
    result += QString("STR: %1\n").arg(str);
    result += QString("DEX: %1\n").arg(dex);
    result += QString("CON: %1\n").arg(cons);
    result += QString("INT: %1\n").arg(inte);
    result += QString("WS: %1\n").arg(ws);
    result += QString("RIZZ: %1\n").arg(rizz);
    result += QString("AC: %1\n").arg(ac);
    result += QString("HP: %1/%2\n").arg(hp).arg(max_hp);
    result += QString("Ability Lvl: %1\n").arg(abilityLvl);
    result += "Umiejętności: ";
    for (int i = 0; i < 12; ++i) {
        result += skills[i] ? "✓ " : "✗ ";
    }
    result += "\n";

    return result;
}
// Gettery
int Character::getStr() const { return str; }
int Character::getDex() const { return dex; }
int Character::getCons() const { return cons; }
int Character::getInte() const { return inte; }
int Character::getWs() const { return ws; }
int Character::getRizz() const { return rizz; }
int Character::getAc() const { return ac; }
int Character::getHp() const { return hp; }
int Character::getMaxHp() const { return max_hp; }
bool Character::getSkill(int index) const {
    if (index >= 0 && index < 12)
        return skills[index];
    return false;
}
int Character::getAbilityLvl() const { return abilityLvl; }
QString Character::getName() const { return name; }
QString Character::getRace() const { return race; }

// Settery
void Character::setStr(int value) { str = value; }
void Character::setDex(int value) { dex = value; }
void Character::setCons(int value) { cons = value; }
void Character::setInte(int value) { inte = value; }
void Character::setWs(int value) { ws = value; }
void Character::setRizz(int value) { rizz = value; }
void Character::setAc(int value) { ac = value; }
void Character::setHp(int value) { hp = value; }
void Character::setMaxHp(int value) { max_hp = value; }
void Character::setSkill(int index, bool value) {
    if (index >= 0 && index < 12)
        skills[index] = value;
}
void Character::setAbilityLvl(int value) { ws = value; }
void Character::setName(const QString& value) { name = value; }
void Character::setRace(const QString& value) { race = value; }


int Character::rollDice(int dice) const{

    return rand()%dice+1;
}

Character* Character::load(QDataStream& in) {
    QString className;
    in >> className;

    if (className == "Mag")
        return Mage::load(in);
    else if (className == "Wojownik")
        return Warrior::load(in);
    else if (className == "Łucznik")
        return Ranger::load(in);
    else if (className == "Mózgognij")
        return Brainrotter::load(in);
    else
        return nullptr;
}

void Character::saveBase(QDataStream& out) const {
    out << str << dex << cons << inte << ws << rizz << ac << hp << max_hp;
    for (int i = 0; i < 12; ++i) {
        out << skills[i];
    }
    out << abilityLvl << name << race;
}

void Character::loadBase(QDataStream& in) {
    in >> str >> dex >> cons >> inte >> ws >> rizz >> ac >> hp >> max_hp;
    for (int i = 0; i < 12; ++i) {
        in >> skills[i];
    }
    in >> abilityLvl >> name >> race;
}
