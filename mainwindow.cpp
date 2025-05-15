#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "BusinessLogic/character.h"
#include "BusinessLogic/warrior.h"
#include "BusinessLogic/ranger.h"
#include "BusinessLogic/mage.h"
#include "BusinessLogic/brainrotter.h"
#include "BusinessLogic/serializer.h"
#include <vector>
#include <iostream>
#include <memory>
#include <time.h>
const QString abilities[4][5] = {
    {"Cios mieczem","Cios toporem","Mikstura leczenia","Spartański kop","Boska szarża"},
    {"Cięcie","Otwarcie pieca","Techniki odwracające","Przeklęty relikwiarz","Nie używałem tego od ery Heian"},
    {"Snajperski strzał","Grad strzał","Złote jabłko","Bonk z łuku","Niewidzialność"},
    {"Bombardiro Crocodilo","Tralelero Tralala","Ballerina Cappucina","Lirili Larila","Tung Tung Tung Tung Tung Sahur"}};
const QString skills[12] = {"Akrobatyka", "Opieka nad zwierzętami", "Oszustwo", "Historia", "Zastraszanie", "Przeszukiwanie","Medycyna","Percepcja","Religia","Zwinne dłonie","Skradanie","Przetrwanie"};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    srand(time(NULL));
    bool tab[12]={false,false,false,false,false,false,false,false,false,false,false,false};
    std::vector<std::unique_ptr<Character>> postaci;

    postaci = Serializer::loadCharactersTxt("characters.txt");
    // postaci.push_back(std::make_unique<Ranger>(1,1,1,1,1,1,13,20,tab,"Elrond","elf"));
    // postaci.push_back(std::make_unique<Warrior>(1,1,1,1,1,1,13,20,tab,"Alron","człowiek"));
    // postaci.push_back(std::make_unique<Mage>(1,1,1,1,1,1,13,20,tab,"Gandalf","człowiek"));
    // postaci.push_back(std::make_unique<Brainrotter>(1,1,1,1,1,1,13,20,tab,"Bombardiro","Krokodyl"));
    // Serializer::saveCharactersTxt(postaci, "characters.txt");
    for(int i=0;i<postaci.size();i++){
        ui->label->setText(ui->label->text() + "\n"+ postaci.at(i)->toString());

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

