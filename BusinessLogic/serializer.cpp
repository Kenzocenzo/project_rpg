#include "serializer.h"

#include <QFile>
#include <QTextStream>
#include "Warrior.h"
#include "Mage.h"
#include "Ranger.h"
#include "Brainrotter.h"

void Serializer::saveCharactersTxt(const std::vector<std::unique_ptr<Character>>& characters, const QString& filename) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream out(&file);
        for (const auto& c : characters) {
            QString type = "Unknown";
            QString className = "";

            if (const Warrior* w = dynamic_cast<const Warrior*>(c.get())) {
                type = "Warrior";
                className = w->getClassName();
            } else if (const Mage* m = dynamic_cast<const Mage*>(c.get())) {
                type = "Mage";
                className = m->getClassName();
            } else if (const Ranger* r = dynamic_cast<const Ranger*>(c.get())) {
                type = "Ranger";
                className = r->getClassName();
            } else if (const Brainrotter* b = dynamic_cast<const Brainrotter*>(c.get())) {
                type = "Brainrotter";
                className = b->getClassName();
            }

            out << "Class: " << type << "\n";
            out << "Str: " << c->getStr() << "\n";
            out << "Dex: " << c->getDex() << "\n";
            out << "Cons: " << c->getCons() << "\n";
            out << "Inte: " << c->getInte() << "\n";
            out << "Ws: " << c->getWs() << "\n";
            out << "Rizz: " << c->getRizz() << "\n";
            out << "Ac: " << c->getAc() << "\n";
            out << "Hp: " << c->getHp() << "\n";
            out << "MaxHp: " << c->getMaxHp() << "\n";
            out << "AbilityLvl: " << c->getAbilityLvl() << "\n";
            out << "Name: " << c->getName() << "\n";
            out << "Race: " << c->getRace() << "\n";
            out << "Skills:";
            for (int i = 0; i < 12; ++i)
                out << " " << c->getSkill(i);
            out << "\n";
            out << "ClassName: " << className << "\n";

            out << "---\n";
        }
        file.close();}
}
std::vector<std::unique_ptr<Character>> Serializer::loadCharactersTxt(const QString& filename) {
    std::vector<std::unique_ptr<Character>> characters;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        QString line, type, name, race, className;
        int str, dex, cons, inte, ws, rizz, ac, hp, maxHp, abilityLvl;
        bool skills[12] = { false };

        while (!in.atEnd()) {
            line = in.readLine();
            if (line.startsWith("Class:"))
                type = line.section(": ", 1);
            else if (line.startsWith("Str:"))
                str = line.section(": ", 1).toInt();
            else if (line.startsWith("Dex:"))
                dex = line.section(": ", 1).toInt();
            else if (line.startsWith("Cons:"))
                cons = line.section(": ", 1).toInt();
            else if (line.startsWith("Inte:"))
                inte = line.section(": ", 1).toInt();
            else if (line.startsWith("Ws:"))
                ws = line.section(": ", 1).toInt();
            else if (line.startsWith("Rizz:"))
                rizz = line.section(": ", 1).toInt();
            else if (line.startsWith("Ac:"))
                ac = line.section(": ", 1).toInt();
            else if (line.startsWith("Hp:"))
                hp = line.section(": ", 1).toInt();
            else if (line.startsWith("MaxHp:"))
                maxHp = line.section(": ", 1).toInt();
            else if (line.startsWith("AbilityLvl:"))
                abilityLvl = line.section(": ", 1).toInt();
            else if (line.startsWith("Name:"))
                name = line.section(": ", 1);
            else if (line.startsWith("Race:"))
                race = line.section(": ", 1);
            else if (line.startsWith("Skills:")) {
                QStringList skillList = line.section(": ", 1).split(" ");
                for (int i = 0; i < 12; ++i)
                    skills[i] = skillList.value(i).toInt();
            }
            else if (line.startsWith("ClassName:"))
                className = line.section(": ", 1);
            else if (line == "---") {
                if (type == "Warrior") {
                    auto w = std::make_unique<Warrior>(str, dex, cons, inte, ws, rizz, ac, hp, skills, name, race);
                    w->setMaxHp(maxHp);
                    w->setAbilityLvl(abilityLvl);
                    characters.emplace_back(std::move(w));
                }
                else if (type == "Mage") {
                    auto w = std::make_unique<Mage>(str, dex, cons, inte, ws, rizz, ac, hp, skills, name, race);
                    w->setMaxHp(maxHp);
                    w->setAbilityLvl(abilityLvl);
                    characters.emplace_back(std::move(w));
                }
                else if (type == "Ranger") {
                    auto w = std::make_unique<Ranger>(str, dex, cons, inte, ws, rizz, ac, hp, skills, name, race);
                    w->setMaxHp(maxHp);
                    w->setAbilityLvl(abilityLvl);
                    characters.emplace_back(std::move(w));
                }
                else if (type == "Brainrotter") {
                    auto w = std::make_unique<Brainrotter>(str, dex, cons, inte, ws, rizz, ac, hp, skills, name, race);
                    w->setMaxHp(maxHp);
                    w->setAbilityLvl(abilityLvl);
                    characters.emplace_back(std::move(w));
                }
            }

        }
        file.close();
    }
    return characters;
}
