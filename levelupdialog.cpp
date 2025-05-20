#include "levelupdialog.h"
#include "ui_levelupdialog.h"
#include "globals.h"
#include<QDialogButtonBox>
#include<QPushButton>

LevelUpDialog::LevelUpDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LevelUpDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Zatwierdź");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Anuluj");
    ui->hpLabel->setText("Max punkty życia " + QString::number(characters.at(currentCharacter)->getMaxHp()) + ">>>" + QString::number(characters.at(currentCharacter)->getMaxHp()+5));
    ui->acLabel->setText("Klasa pancerza " + QString::number(characters.at(currentCharacter)->getAc()) + ">>>" + QString::number(characters.at(currentCharacter)->getAc()+1));
    ui->statBox->addItem("Siła");
    ui->statBox->addItem("Zręczność");
    ui->statBox->addItem("Wytrzymałość");
    ui->statBox->addItem("Inteligencja");
    ui->statBox->addItem("Mądrość");
    ui->statBox->addItem("Charyzma");
    for(int i=0; i<12; i++){
        if(!characters.at(currentCharacter)->getSkill(i)){
            ui->skillBox->addItem(skills[i]);
        }
    }
    QString klasa = characters.at(currentCharacter)->getClassName();
    if(klasa == "Wojownik") ui->abilityLabel->setText("🔓"+abilities[0][characters.at(currentCharacter)->getLevel()]+"🔓");
    else if(klasa == "Mag")ui->abilityLabel->setText("🔓"+abilities[1][characters.at(currentCharacter)->getLevel()]+"🔓");
    else if(klasa == "Łucznik")ui->abilityLabel->setText("🔓"+abilities[2][characters.at(currentCharacter)->getLevel()]+"🔓");
    else ui->abilityLabel->setText("🔓"+abilities[3][characters.at(currentCharacter)->getLevel()]+"🔓");
    labelFiller();
}

LevelUpDialog::~LevelUpDialog()
{
    delete ui;
}


void LevelUpDialog::on_statBox_currentTextChanged(const QString &arg1)
{
    labelFiller();
}

void LevelUpDialog::labelFiller(){
    switch(ui->statBox->currentIndex()){
    case 0:
        textFiller(characters.at(currentCharacter)->getStr());
        break;
    case 1:
        textFiller(characters.at(currentCharacter)->getDex());
        break;
    case 2:
        textFiller(characters.at(currentCharacter)->getCons());
        break;
    case 3:
        textFiller(characters.at(currentCharacter)->getInte());
        break;
    case 4:
        textFiller(characters.at(currentCharacter)->getWs());
        break;
    case 5:
        textFiller(characters.at(currentCharacter)->getRizz());
    }
}

void LevelUpDialog::textFiller(int stat){
    if(stat<4){
        ui->statLabel->setText(QString::number(stat) + ">>>" + QString::number(stat+1));
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
    else if(stat == 4){
        ui->statLabel->setText("4>>>5 (MAX)");
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
    else{
        ui->statLabel->setText("Osiągnięto maksymalny poziom");
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}
int LevelUpDialog::getStat(){
    return ui->statBox->currentIndex();
}

QString LevelUpDialog::getSkill(){
    return ui->skillBox->currentText();
}

