#include "mage.h"
#include "character.h"
#include <QFile>
#include <QDataStream>
Mage::Mage() {}
Mage::Mage(int str,
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
    className = "Mag";
}
QString Mage::toString() const {
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

QString Mage::first_ability(){
    QString a = "Cięcie: 1d20 + INT, obrażenia = 2d6 + 5\n";
    a += "Trafia za "+ QString::number(rollDice(20)+inte)+'\n';
    a += "Mag skupia się i wypowiada cicho inkantację, celuje dłonią w przeciwnika, na jego ciele pojawia się siatka cięć zadająca: " + QString::number(rollDice(6)+rollDice(6)+5) + " obrażeń";
    return a;
}
QString Mage::second_ability(){
    QString a = "Otwarcie pieca: 1d20 + WIS, obrażenia = 3d8\n";
    a += "Trafia za "+ QString::number(rollDice(20)+ws)+'\n';
    a += "Powietrze zaczyna się nagrzewać. W dłoni maga buchają iskry, a następnie wybucha w nich płomień. Niczym łukiem celuje ognistą strzałą w przeciwnika i wypowiada słowo 'fuga'. Ognista strzała pędzi w przeciwnika zadając: " + QString::number(rollDice(8)+rollDice(8)+rollDice(8)) + " obrażeń";
    return a;
}
QString Mage::third_ability(){
    QString a = "Techniki odwracające: 3d6\n";
    int b = rollDice(6)+rollDice(6)+rollDice(6);
    a += "Mag skupia się, mnoży swoją przeklętą energię przez samą siebie tworząc pozytywną energię. Jego rany zaczynają się zasklepiać. Przywraca sobie : " + QString::number(b) + " punktów życia";
    hp += b;
    if(hp>max_hp) hp = max_hp;
    return a;
}
QString Mage::fourth_ability(){
    QString a = "Przeklęty relikwiarz: 1d20 + WIS, obrażenia = 3d8 + 2 na turę\n";
    a += "Wynik rzutu "+ QString::number(rollDice(20)+ws)+'\n';
    a += "Mag składa dłonie i wymawia inktantację: 'rozszerzenie domeny', za jego plecami pojawia się wielki ołtarz stojący na górze czaszek.\nStoi on tam aż do przerwania korzystania z tej umiejętności. Każda żyjąca istota w zasięgu działania domeny otrzymuje " + QString::number(rollDice(8)+rollDice(8)+rollDice(8)+2) + " obrażeń na turę walki";
    return a;
}
QString Mage::fifth_ability(){
    QString a = "Nie używałem tego od ery Heian: 1d20 + INT\n";
    a += "Wynik rzutu "+ QString::number(rollDice(20)+inte)+'\n';
    a += "Mag cicho śmieje się pod nosem szeptając inkantację. Zawiera pakt (ustal z mg), w wyniku tego zniweluj dowolną zdolność przeciwnika.";
    return a;
}
