#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "BusinessLogic/character.h"
#include "BusinessLogic/warrior.h"
#include <vector>
#include <iostream>
#include <memory>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bool tab[12]={false};
    std::vector<std::unique_ptr<Character>> postaci;


    postaci.push_back(std::make_unique<Character>(1,1,1,1,1,1,13,20,tab,"Elrond","elf"));
    postaci.push_back(std::make_unique<Character>(1,1,1,1,1,1,13,20,tab,"Alron","czlowiek"));
    postaci.push_back(std::make_unique<Warrior>(1,1,1,1,1,1,13,20,tab,"Bombardiro","Krokodyl"));
    for(int i=0;i<postaci.size();i++){
        ui->label->setText(ui->label->text() + "\n"+ postaci.at(i)->toString());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

