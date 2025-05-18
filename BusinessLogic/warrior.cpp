#include "warrior.h"
#include "character.h"
#include <QString>
#include <QFile>
#include <QDataStream>
Warrior::Warrior() {}
Warrior::Warrior(int str,
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
                          race){
    className = "Wojownik";
}
QString Warrior::toString() const {
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
     result += QString("Ability Lvl: %1\n").arg(level);
    result += "Umiejętności: ";
    for (int i = 0; i < 12; ++i) {
        result += skills[i] ? "✓ " : "✗ ";
    }
    result += "\n";

    return result;
}

QString Warrior::first_ability(){
    QString a = "Cios mieczem: 1d20 + DEX, obrażenia = 2d6\n";
    a += "Trafia za "+ QString::number(rollDice(20)+dex)+'\n';
    a += "Wojownik zamachuje się ostrzem i zadaje: " + QString::number(rollDice(6)+rollDice(6)) + " obrażeń";
    return a;
}
QString Warrior::second_ability(){
    QString a = "Cios toporem: 1d20 + STR, obrażenia = 3d8\n";
    a += "Trafia za "+ QString::number(rollDice(20)+str)+'\n';
    a += "Wojownik unosi swój topór wysoko w powietrze i z impetem opuszcza go na głowę przeciwnika, zadając: " + QString::number(rollDice(8)+rollDice(8)+rollDice(8)) + " obrażeń";
    return a;
}
QString Warrior::third_ability(){
    QString a = "Mikstura leczenia: 2d6\n";
    int b = rollDice(6)+rollDice(6);
    a += "Wojownik wyciąga zza pasa złotą miksturę i ją zeruje lecząc: " + QString::number(b) + " punktów życia";
    hp += b;
    if(hp>max_hp) hp = max_hp;
    return a;
}
QString Warrior::fourth_ability(){
    QString a = "Spartański kop: 1d20 + 3STR, obrażenia = 3d10\n";
    a += "Trafia za "+ QString::number(rollDice(20)+3*str)+'\n';
    a += "Wojownik ładuje energię chaosu, i wykonuje potężne kopnięcie wyrzucające przeciwnika do tyłu i zadające: " + QString::number(rollDice(10)+rollDice(10)+rollDice(10)) + " obrażeń";
    return a;
}
QString Warrior::fifth_ability(){
    QString a = "Boska szarża: 1d20 + 3DEX, obrażenia = 3d20+5\n";
    a += "Trafia za "+ QString::number(rollDice(20)+3*dex)+'\n';
    a += "Wojownik ładuje boską energię, cofa się trzy kroki w tył, po czym wyskakuje w przód z prędkością błyskawicy, gdy zderza się z wrogiem zadaje mu: " + QString::number(rollDice(20)+rollDice(20)+rollDice(20)+5) + " obrażeń";
    return a;
}
