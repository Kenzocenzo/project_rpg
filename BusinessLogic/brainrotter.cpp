#include "brainrotter.h"
#include "character.h"
Brainrotter::Brainrotter() {}
Brainrotter::Brainrotter(int str,
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
QString Brainrotter::toString() const {
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

QString Brainrotter::first_ability(){
    QString a = "Bombardiro Crocodilo: 1d20 + WIS, obrażenia = 3d6\n";
    a += "Trafia za "+ QString::number(rollDice(20)+ws)+'\n';
    a += "Mózgognij unosi się w powietrze. Z nieba spada bomba zadająca: " + QString::number(rollDice(6)+rollDice(6)+rollDice(6)) + " obrażeń";
    return a;
}
QString Brainrotter::second_ability(){
    QString a = "Tralelero Tralala: 1d20 + CON, obrażenia = 3d8\n";
    a += "Trafia za "+ QString::number(rollDice(20)+cons)+'\n';
    a += "Mózgognij zakłada nike'i i wykonuje potęzne kopnięcie z siłą rekina, które zadaje: " + QString::number(rollDice(8)+rollDice(8)+rollDice(8)) + " obrażeń";
    return a;
}
QString Brainrotter::third_ability(){
    QString a = "Ballerina Cappucina: 3d6\n";
    int b = rollDice(6)+rollDice(6)+rollDice(6);
    a += "Mózgognij przygotwuje kawkę, leczy sobie: " + QString::number(b) + " punktów życia";
    hp += b;
    if(hp>max_hp) hp = max_hp;
    return a;
}
QString Brainrotter::fourth_ability(){
    QString a = "Lirili Larila: 1d20 + CHA\n";
    a += "Wynik rzutu "+ QString::number(rollDice(20)+rizz)+'\n';
    a += "Mózgognij zakłada klapki i wyjmuje zegar, czas zatrzymuje się.";
    return a;
}
QString Brainrotter::fifth_ability(){
    QString a = "Tung Tung Tung Tung Tung Sahur: 1d20 + STR, obrażenia = 2d100\n";
    a += "Trafia za "+ QString::number(rollDice(20)+str)+'\n';
    a += "Mózgognij wyjmuje wielki drewniany kij i uderza przeciwnika w głowę zadając: " + QString::number(rollDice(100)+rollDice(100)) + " obrażeń";
    return a;
}
