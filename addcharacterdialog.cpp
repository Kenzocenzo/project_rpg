#include "addcharacterdialog.h"
#include "ui_addcharacterdialog.h"
#include "globals.h"
#include <QCheckBox>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

AddCharacterDialog::AddCharacterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCharacterDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Dodaj");
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Anuluj");
    for(int i=0; i<12; i++){
        QCheckBox* cb = new QCheckBox(skills[i], this);
        connect(cb,&QCheckBox::stateChanged,this,&AddCharacterDialog::checkBoxChecker);
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
    checkBoxCount = 0;
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
    validator();
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

void AddCharacterDialog::checkBoxChecker(int status){
    if(status){
        checkBoxCount++;
    }
    else{
        checkBoxCount--;
    }
    if(checkBoxCount == 4){
        for(int i=0; i<12; i++){
            if(!checkboxes.at(i)->isChecked()){
                checkboxes.at(i)->setEnabled(false);
            }
        }
    }
    else{
        for(int i=0; i<12; i++){
            checkboxes.at(i)->setEnabled(true);
        }
    }
    validator();
}

QString AddCharacterDialog::getName(){
    return ui->nameEdit->text();
}
QString AddCharacterDialog::getRace(){
    return ui->raceBox->currentText();
}
QString AddCharacterDialog::getClass(){
    return ui->classBox->currentText();
}
std::array<int, 8> AddCharacterDialog::getStats() const {
    return { ui->strEdit->value(),
            ui->dexEdit->value(),
            ui->constEdit->value(),
            ui->inteEdit->value(),
            ui->wsEdit->value(),
            ui->rizzEdit->value(),
            ac,
            hp };
}

std::array<bool, 12> AddCharacterDialog::getSkills() const {
    std::array<bool, 12> result{};
    for (int i = 0; i < 12; ++i) {
        result[i] = checkboxes.at(i)->isChecked();
    }
    return result;
}

void AddCharacterDialog::validator(){
    if(!ui->nameEdit->text().trimmed().isEmpty() && statSum == 5 && checkBoxCount == 4)
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    else
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

void AddCharacterDialog::on_nameEdit_textChanged(const QString &arg1)
{
    validator();
}

