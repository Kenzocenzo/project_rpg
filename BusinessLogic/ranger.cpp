#include "ranger.h"
#include "character.h"
Ranger::Ranger() {}
Ranger::Ranger(int str,
                 int dex,
                 int cons,
                 int inte,
                 int ws,
                 int rizz,
                 int ac,
                 int hp,
                 const bool skills[12],
                 const QString& name,
                 const QString& race):Character(str,
                dex,
                cons,
                inte,
                ws,
                rizz,
                ac,
                hp,
                &skills[12],
                name,
                race){}
QString Ranger::toString() const {
    QString result;
    result += QString("Imię: %1\n").arg(name);
    result += QString("Rasa: %1\n").arg(race);
    result += QString("Klasa: %1\n").arg(className);
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

QString Ranger::first_ability(){
    return "abc";
}
QString Ranger::second_ability(){
    return "abc";
}
QString Ranger::third_ability(){
    return "abc";
}
QString Ranger::fourth_ability(){
    return "abc";
}
QString Ranger::fifth_ability(){
    return "abc";
}
