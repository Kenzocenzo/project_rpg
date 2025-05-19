#include "addcharacterdialog.h"
#include "ui_addcharacterdialog.h"
#include "globals.h"
#include <QCheckBox>
#include <QGridLayout>
#include <QDebug>

AddCharacterDialog::AddCharacterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCharacterDialog)
{
    ui->setupUi(this);
    for(int i=0; i<12; i++){
        QCheckBox* cb = new QCheckBox(skills[i], this);
        checkboxes.append(cb);
        ui->checkboxContainer->addWidget(cb, i / 3, i % 3);
    }
    for(int i=0; i<9; i++){
        ui->raceBox->addItem(races[i]);
    }
    ui->classBox->addItem("Wojownik");
    ui->classBox->addItem("Mag");
    ui->classBox->addItem("Łucznik");
    ui->classBox->addItem("Mózgognij");
    hpSetter();
    acSetter();
    statChecker();
}

AddCharacterDialog::~AddCharacterDialog()
{
    delete ui;
}

void AddCharacterDialog::hpSetter(){
    hp = 15 + ui->constEdit->value();
    ui->hpLabel->setText("HP: 15 + wytrzymałość = " + QString::number(hp));
}

void AddCharacterDialog::acSetter(){
    qDebug()<<ui->classBox->currentText();
    if(ui->classBox->currentText() == "Mag"){
        ac = 10 + ui->wsEdit->value();
        ui->acLabel->setText("Klasa Pancerza: 10 + mądrość = " + QString::number(ac));
    }
    else if(ui->classBox->currentText() == "Mózgognij"){
        ac = 10 + ui->inteEdit->value();
        ui->acLabel->setText("Klasa Pancerza: 10 + inteligencja = " + QString::number(ac));
    }
    else{
        ac = 10 + ui->dexEdit->value();
        ui->acLabel->setText("Klasa Pancerza: 10 + zręczność = " + QString::number(ac));
    }
}

void AddCharacterDialog::statChecker(){
    statSum = ui->strEdit->value()+ui->dexEdit->value()+ui->constEdit->value()+ui->wsEdit->value()+ui->inteEdit->value()+ui->rizzEdit->value();
    ui->statLabel->setText("Suma statystyk: "+QString::number(statSum)+"/5");
    if(statSum==5) ui->statLabel->setStyleSheet("color: green;");
    else ui->statLabel->setStyleSheet("color: red;");
}


void AddCharacterDialog::on_constEdit_valueChanged(int arg1)
{
    hpSetter();
    statChecker();
}


void AddCharacterDialog::on_dexEdit_valueChanged(int arg1)
{
    acSetter();
    statChecker();
}


void AddCharacterDialog::on_wsEdit_valueChanged(int arg1)
{
    acSetter();
    statChecker();
}


void AddCharacterDialog::on_inteEdit_valueChanged(int arg1)
{
    acSetter();
    statChecker();
}


void AddCharacterDialog::on_classBox_currentTextChanged(const QString &arg1)
{
    acSetter();
}


void AddCharacterDialog::on_strEdit_valueChanged(int arg1)
{
    statChecker();
}


void AddCharacterDialog::on_rizzEdit_valueChanged(int arg1)
{
    statChecker();
}

void AddCharacterDialog::checkBoxChecker(){

}

