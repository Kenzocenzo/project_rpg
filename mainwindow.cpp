#include "mainwindow.h"
#include "addcharacterdialog.h"
#include "levelupdialog.h"
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
#include "globals.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    srand(time(NULL));
    characterFiller();
    ui->exportButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_importButton_clicked()
{
    try{
        QString filter = "Pliki tekstowe (*.txt)";
        QString path = QFileDialog::getOpenFileName(this,
                                                    "Wybierz plik tekstowy",
                                                    QDir::homePath(),
                                                    filter);

        if (!path.isEmpty()) {
            characters = Serializer::loadCharactersTxt(path);
            currentCharacter = -1;
            listFiller();
            ui->exportButton->setEnabled(true);
        } else {
            throw std::runtime_error("Nie wybrano pliku .txt!");
        }
    }
    catch (const std::exception &e) {
        QMessageBox::critical(this, "Błąd", e.what());
    }
}

void MainWindow::on_exportButton_clicked()
{
    QString filter = "Pliki tekstowe (*.txt)";
    QString path = QFileDialog::getSaveFileName(this, "Zapisz plik", QDir::homePath(), filter);
    Serializer::saveCharactersTxt(characters, path);
    QMessageBox::information(this, "Sukces", "Poprawnie zapisano plik");
}

void MainWindow::listFiller(){
    ui->listWidget->clear();
    for(int i = 0; i<characters.size(); i++){
        ui->listWidget->addItem(characters.at(i)->toSmallString());
    }
    characterFiller();
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    currentCharacter = ui->listWidget->row(item);
    characterFiller();
}

void MainWindow::characterFiller(){
    if(currentCharacter>=0){
        ui->nameLabel->setText("Imię: " + characters.at(currentCharacter)->getName());
        ui->raceLabel->setText("Rasa: " + characters.at(currentCharacter)->getRace());
        ui->classLabel->setText("Klasa: " + characters.at(currentCharacter)->getClassName());
        ui->acLabel->setText("Klasa pancerza: " + QString::number(characters.at(currentCharacter)->getAc()));
        ui->hpEdit->setMaximum(characters.at(currentCharacter)->getMaxHp());
        ui->hpEdit->setValue(characters.at(currentCharacter)->getHp());
        ui->hpLabel->setText("/" + QString::number(characters.at(currentCharacter)->getMaxHp()) + " punktów zdrowia");
        ui->statLabel_1->setText("Siła: " + QString::number(characters.at(currentCharacter)->getStr()));
        ui->statLabel_2->setText("Zręczność: " + QString::number(characters.at(currentCharacter)->getDex()));
        ui->statLabel_3->setText("Wytrzymałość:" + QString::number(characters.at(currentCharacter)->getCons()));
        ui->statLabel_4->setText("Inteligencja: " + QString::number(characters.at(currentCharacter)->getInte()));
        ui->statLabel_5->setText("Mądrość: " + QString::number(characters.at(currentCharacter)->getWs()));
        ui->statLabel_6->setText("Charyzma: " + QString::number(characters.at(currentCharacter)->getRizz()));
        ui->skillList->clear();
        for(int i = 0; i<12; i++){
            if(characters.at(currentCharacter)->getSkill(i)){
                ui->skillList->addItem(skills[i]);
            }
        }
        int index = 0; //wojownik
        if(characters.at(currentCharacter)->getClassName() == "Mag") index = 1;
        else if(characters.at(currentCharacter)->getClassName() == "Łucznik") index = 2;
        else if(characters.at(currentCharacter)->getClassName() == "Mózgognij") index = 3;
        ui->abilityLabel_1->setText(abilities[index][0]);
        ui->abilityLabel_2->setText(abilities[index][1]);
        ui->abilityLabel_3->setText(abilities[index][2]);
        ui->abilityLabel_4->setText(abilities[index][3]);
        ui->abilityLabel_5->setText(abilities[index][4]);

        ui->rollButton_1->setEnabled(true);
        ui->rollButton_2->setEnabled(true);
        ui->rollButton_3->setEnabled(true);
        ui->rollButton_4->setEnabled(true);
        ui->rollButton_5->setEnabled(true);
        ui->rollButton_6->setEnabled(true);

        ui->rollAbilityButton_2->setEnabled(false);
        ui->rollAbilityButton_3->setEnabled(false);
        ui->rollAbilityButton_4->setEnabled(false);
        ui->rollAbilityButton_5->setEnabled(false);

        if(characters.at(currentCharacter)->getLevel() >= 1) ui->rollAbilityButton_1->setEnabled(true);
        if(characters.at(currentCharacter)->getLevel() >= 2) ui->rollAbilityButton_2->setEnabled(true);
        if(characters.at(currentCharacter)->getLevel() >= 3) ui->rollAbilityButton_3->setEnabled(true);
        if(characters.at(currentCharacter)->getLevel() >= 4) ui->rollAbilityButton_4->setEnabled(true);
        if(characters.at(currentCharacter)->getLevel() == 5) ui->rollAbilityButton_5->setEnabled(true);

        if(characters.at(currentCharacter)->getLevel() != 5){
            ui->levelUpButton->setEnabled(true);
            ui->levelUpButton->setText("Zwiększ poziom");
        }
        else{
            ui->levelUpButton->setEnabled(false);
            ui->levelUpButton->setText("Maksymalny poziom");
        }

    } else {
        ui->levelUpButton->setEnabled(false);
        ui->levelUpButton->setText("Zwiększ poziom");

        ui->nameLabel->setText("Imię: ");
        ui->raceLabel->setText("Rasa: ");
        ui->classLabel->setText("Klasa: ");
        ui->acLabel->setText("Klasa pancerza: X");
        ui->hpEdit->setValue(0);
        ui->hpEdit->setMaximum(0);
        ui->hpLabel->setText("/0 punktów zdrowia");
        ui->statLabel_1->setText("Siła: X");
        ui->statLabel_2->setText("Zręczność: X");
        ui->statLabel_3->setText("Wytrzymałość: X");
        ui->statLabel_4->setText("Inteligencja: X");
        ui->statLabel_5->setText("Mądrość: X");
        ui->statLabel_6->setText("Charyzma: X");
        ui->skillList->clear();

        ui->abilityLabel_1->setText("Zdolność 1");
        ui->abilityLabel_2->setText("Zdolność 2");
        ui->abilityLabel_3->setText("Zdolność 3");
        ui->abilityLabel_4->setText("Zdolność 4");
        ui->abilityLabel_5->setText("Zdolność 5");

        ui->rollAbilityButton_1->setEnabled(false);
        ui->rollAbilityButton_2->setEnabled(false);
        ui->rollAbilityButton_3->setEnabled(false);
        ui->rollAbilityButton_4->setEnabled(false);
        ui->rollAbilityButton_5->setEnabled(false);

        ui->rollButton_1->setEnabled(false);
        ui->rollButton_2->setEnabled(false);
        ui->rollButton_3->setEnabled(false);
        ui->rollButton_4->setEnabled(false);
        ui->rollButton_5->setEnabled(false);
        ui->rollButton_6->setEnabled(false);
    }
}

void MainWindow::rollStatDice(int stat, QString name){
    int roll = rand()%20+1+stat;
    QMessageBox::information(this, "Rzut na " + name, "1d20+" + QString::number(stat) + "= " + QString::number(roll));
}

void MainWindow::on_rollButton_1_clicked()
{
    rollStatDice(characters.at(currentCharacter)->getStr(), "siłę");
}

void MainWindow::on_rollButton_2_clicked()
{
    rollStatDice(characters.at(currentCharacter)->getDex(), "zręczność");
}
void MainWindow::on_rollButton_3_clicked()
{
    rollStatDice(characters.at(currentCharacter)->getCons(), "wytrzymałość");
}

void MainWindow::on_rollButton_4_clicked()
{
    rollStatDice(characters.at(currentCharacter)->getInte(), "inteligencję");
}

void MainWindow::on_rollButton_5_clicked()
{
    rollStatDice(characters.at(currentCharacter)->getWs(), "mądrość");
}

void MainWindow::on_rollButton_6_clicked()
{
    rollStatDice(characters.at(currentCharacter)->getRizz(), "charyzmę");
}

void MainWindow::on_rollAbilityButton_1_clicked()
{
    int index = 0; //wojownik
    if(characters.at(currentCharacter)->getClassName() == "Mag") index = 1;
    else if(characters.at(currentCharacter)->getClassName() == "Łucznik") index = 2;
    else if(characters.at(currentCharacter)->getClassName() == "Mózgognij") index = 3;
    QMessageBox::information(this, abilities[index][0], characters.at(currentCharacter)->first_ability());
}


void MainWindow::on_rollAbilityButton_2_clicked()
{
    QMessageBox::information(this, "Zdolność", characters.at(currentCharacter)->second_ability());
}


void MainWindow::on_rollAbilityButton_3_clicked()
{
    QMessageBox::information(this, "Zdolność", characters.at(currentCharacter)->third_ability());
}


void MainWindow::on_rollAbilityButton_4_clicked()
{
    QMessageBox::information(this, "Zdolność", characters.at(currentCharacter)->fourth_ability());
}


void MainWindow::on_rollAbilityButton_5_clicked()
{
    QMessageBox::information(this, "Zdolność", characters.at(currentCharacter)->fifth_ability());
}


void MainWindow::on_hpEdit_valueChanged(int arg1)
{
    if(currentCharacter >= 0){
        characters.at(currentCharacter)->setHp(arg1);
        listFiller();
    }
}


void MainWindow::on_deleteButton_clicked()
{
    try{
        QListWidgetItem *item = ui->listWidget->currentItem();

        int index = ui->listWidget->row(item);
        if(index<0) throw std::runtime_error("Nie wybrano żadnej postaci");
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(
            this,                                  // parent
            "Potwierdzenie",                       // tytuł okienka
            "Czy na pewno chcesz usunąć ten element?", // treść
            QMessageBox::Yes | QMessageBox::No     // przyciski
            );

        if (reply == QMessageBox::Yes) {
            characters.erase(characters.begin() + index);
            if(currentCharacter > index) currentCharacter = currentCharacter - 1;
            else if(currentCharacter == index) currentCharacter = -1;
            listFiller();
            if(characters.size() == 0){
                ui->exportButton->setEnabled(false);
            }
        }

    }
    catch(const std::exception &e){
        QMessageBox::critical(this, "Błąd", e.what());
    }

}


void MainWindow::on_addButton_clicked()
{
    AddCharacterDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted){
        QString imie = dialog.getName();
        QString rasa = dialog.getRace();
        QString klasa = dialog.getClass();
        auto s = dialog.getStats();
        auto u = dialog.getSkills();

        if(klasa == "Wojownik"){
            characters.push_back(std::make_unique<Warrior>(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], u.data(), imie, rasa));
        }
        else if(klasa == "Mag"){
            characters.push_back(std::make_unique<Mage>(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], u.data(), imie, rasa));
        }
        else if(klasa == "Łucznik"){
            characters.push_back(std::make_unique<Ranger>(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], u.data(), imie, rasa));
        }
        else{
            characters.push_back(std::make_unique<Brainrotter>(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], u.data(), imie, rasa));
        }
        currentCharacter = characters.size()-1;
        listFiller();
        ui->exportButton->setEnabled(true);
    }
}


void MainWindow::on_levelUpButton_clicked()
{
    LevelUpDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted){
        characters.at(currentCharacter)->levelUp(dialog.getStat(),dialog.getSkill());
        listFiller();
    }
}

