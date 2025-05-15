#include "ranger.h"
#include "character.h"
#include <QFile>
#include <QDataStream>
Ranger::Ranger() {}
Ranger::Ranger(int str,
                 int dex,
                 int cons,
                 int inte,
                 int ws,
                 int rizz,
                 int ac,
                 int hp,
                 bool skills[12],
                 const QString& name,
                 const QString& race):Character(str,
                dex,
                cons,
                inte,
                ws,
                rizz,
                ac,
                hp,
                skills,
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
    QString a = "Snajperski strzał: 1d20 + DEX, obrażenia = 2d6\n";
    a += "Trafia za "+ QString::number(rollDice(20)+dex)+'\n';
    a += "Łucznik naciąga cięciwę oddając potężny strzał i zadaje: " + QString::number(rollDice(6)+rollDice(6)) + " obrażeń";
    return a;
}
QString Ranger::second_ability(){
    QString a = "Grad strzał: 1d20 + DEX, obrażenia = 3 * (1d6+2)\n";
    a += "Trafia za "+ QString::number(rollDice(20)+dex)+'\n';
    a += "Łucznik naciąga klika strzał celując w powietrze, oddaje grad strzał i zadaje: " + QString::number(rollDice(6)+2) + " " + QString::number(rollDice(6)+2) + " " + QString::number(rollDice(6)+2) + " obrażeń trzem celom";
    return a;
}
QString Ranger::third_ability(){
    QString a = "Złote jabłko: 2d6\n";
    int b = rollDice(6)+rollDice(6);
    a += "Łucznik wyciąga złote jabłko i zjada je lecząc: " + QString::number(b) + " punktów życia";
    hp += b;
    if(hp>max_hp) hp = max_hp;
    return a;
}
QString Ranger::fourth_ability(){
    QString a = "Bonk z łuku: 1d20 + STR, obrażenia = 3d8\n";
    a += "Trafia za "+ QString::number(rollDice(20)+str)+'\n';
    a += "Łucznik zamachuje się, potężnie uderza i zadaje: " + QString::number(rollDice(8)+rollDice(8)+rollDice(8)) + " obrażeń";
    return a;
}
QString Ranger::fifth_ability(){
    QString a = "Niewidzialność: 1d20 + INT\n";
    a += "Wynik rzutu: "+ QString::number(rollDice(20)+inte)+'\n';
    a += "Łucznik narzuca na siebie pelerynę niewidkę i znika z pola widzenia";
    return a;
}
void Ranger::save(QDataStream& out) const {
    out << QString("Ranger");
    out << str << dex << cons << inte << ws << rizz << ac << hp << max_hp;
    for (int i = 0; i < 12; ++i)
        out << skills[i];
    out << abilityLvl << name << race << className;
}

Ranger* Ranger::load(QDataStream& in) {
    int str, dex, cons, inte, ws, rizz, ac, hp, max_hp, abilityLvl;
    bool skills[12];
    QString name, race, className;

    in >> str >> dex >> cons >> inte >> ws >> rizz >> ac >> hp >> max_hp;
    for (int i = 0; i < 12; ++i)
        in >> skills[i];
    in >> abilityLvl >> name >> race >> className;

    Ranger* w = new Ranger(str, dex, cons, inte, ws, rizz, ac, hp, skills, name, race);
    w->setMaxHp(max_hp);
    w->setAbilityLvl(abilityLvl);
    return w;
}
