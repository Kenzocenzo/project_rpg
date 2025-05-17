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
    bool tab[12]={false,false,false,false,false,false,false,false,false,false,false,false};

    // postaci = Serializer::loadCharactersTxt("characters.txt");
    // postaci.push_back(std::make_unique<Ranger>(1,1,1,1,1,1,13,20,tab,"Elrond","elf"));
    // postaci.push_back(std::make_unique<Warrior>(1,1,1,1,1,1,13,20,tab,"Alron","człowiek"));
    // postaci.push_back(std::make_unique<Mage>(1,1,1,1,1,1,13,20,tab,"Gandalf","człowiek"));
    // postaci.push_back(std::make_unique<Brainrotter>(1,1,1,1,1,1,13,20,tab,"Bombardiro","Krokodyl"));
    // Serializer::saveCharactersTxt(postaci, "characters.txt");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_importButton_clicked()
{
    try{
        QString filter = "Pliki tekstowe (*.txt)";
        QString path = QFileDialog::getOpenFileName(nullptr,
                                                    "Wybierz plik tekstowy",
                                                    QDir::homePath(),
                                                    filter);

        if (!path.isEmpty()) {
            characters = Serializer::loadCharactersTxt(path);
            listFiller();
        } else {
            throw std::runtime_error("Nie wybrano pliku .txt!");
        }
    }
    catch (const std::exception &e) {
        QMessageBox::critical(nullptr, "Błąd", e.what());
    }
}

void MainWindow::on_exportButton_clicked()
{
    QString filter = "Pliki tekstowe (*.txt)";
    QString path = QFileDialog::getSaveFileName(nullptr, "Zapisz plik", QDir::homePath(), filter);
    Serializer::saveCharactersTxt(characters, path);
    QMessageBox::information(nullptr, "Sukces", "Poprawnie zapisano plik");
}

void MainWindow::listFiller(){
    ui->listWidget->clear();
    for(int i = 0; i<characters.size(); i++){
        ui->listWidget->addItem(characters.at(i)->toSmallString());
    }
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
        ui->hpEdit->setValue(characters.at(currentCharacter)->getHp());
        ui->hpEdit->setMaximum(characters.at(currentCharacter)->getMaxHp());
        ui->hpLabel->setText("/" + QString::number(characters.at(currentCharacter)->getMaxHp()) + " punktów zdrowia");
    }
}
