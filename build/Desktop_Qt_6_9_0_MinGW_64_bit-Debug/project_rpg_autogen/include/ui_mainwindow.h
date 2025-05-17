/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *levelUpButton;
    QPushButton *rollButton;
    QLabel *statLabel;
    QLabel *statLabel_2;
    QPushButton *rollButton_2;
    QLabel *statLabel_3;
    QPushButton *rollButton_3;
    QLabel *statLabel_4;
    QPushButton *rollButton_4;
    QLabel *statLabel_5;
    QPushButton *rollButton_5;
    QLabel *statLabel_6;
    QPushButton *rollButton_6;
    QLabel *hpLabel;
    QListWidget *listWidget;
    QLabel *acLabel;
    QLabel *nameLabel;
    QLabel *raceLabel;
    QLabel *classLabel;
    QLabel *skillsLabel;
    QListWidget *listWidget_2;
    QLabel *abilitiesLabel;
    QLabel *abilityLabel;
    QPushButton *rollAbilityButton;
    QLabel *abilityLabel_2;
    QPushButton *rollAbilityButton_2;
    QLabel *abilityLabel_3;
    QPushButton *rollAbilityButton_3;
    QLabel *abilityLabel_4;
    QPushButton *rollAbilityButton_4;
    QLabel *abilityLabel_5;
    QPushButton *rollAbilityButton_5;
    QPushButton *importButton;
    QPushButton *exportButton;
    QSpinBox *hpEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(856, 748);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(20, 110, 91, 61));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(660, 90, 101, 61));
        levelUpButton = new QPushButton(centralwidget);
        levelUpButton->setObjectName("levelUpButton");
        levelUpButton->setGeometry(QRect(660, 210, 101, 61));
        rollButton = new QPushButton(centralwidget);
        rollButton->setObjectName("rollButton");
        rollButton->setGeometry(QRect(70, 460, 81, 61));
        statLabel = new QLabel(centralwidget);
        statLabel->setObjectName("statLabel");
        statLabel->setGeometry(QRect(70, 410, 71, 41));
        statLabel_2 = new QLabel(centralwidget);
        statLabel_2->setObjectName("statLabel_2");
        statLabel_2->setGeometry(QRect(190, 410, 71, 41));
        rollButton_2 = new QPushButton(centralwidget);
        rollButton_2->setObjectName("rollButton_2");
        rollButton_2->setGeometry(QRect(190, 460, 81, 61));
        statLabel_3 = new QLabel(centralwidget);
        statLabel_3->setObjectName("statLabel_3");
        statLabel_3->setGeometry(QRect(310, 410, 71, 41));
        rollButton_3 = new QPushButton(centralwidget);
        rollButton_3->setObjectName("rollButton_3");
        rollButton_3->setGeometry(QRect(310, 460, 81, 61));
        statLabel_4 = new QLabel(centralwidget);
        statLabel_4->setObjectName("statLabel_4");
        statLabel_4->setGeometry(QRect(420, 410, 71, 41));
        rollButton_4 = new QPushButton(centralwidget);
        rollButton_4->setObjectName("rollButton_4");
        rollButton_4->setGeometry(QRect(420, 460, 81, 61));
        statLabel_5 = new QLabel(centralwidget);
        statLabel_5->setObjectName("statLabel_5");
        statLabel_5->setGeometry(QRect(530, 410, 71, 41));
        rollButton_5 = new QPushButton(centralwidget);
        rollButton_5->setObjectName("rollButton_5");
        rollButton_5->setGeometry(QRect(530, 460, 81, 61));
        statLabel_6 = new QLabel(centralwidget);
        statLabel_6->setObjectName("statLabel_6");
        statLabel_6->setGeometry(QRect(630, 410, 71, 41));
        rollButton_6 = new QPushButton(centralwidget);
        rollButton_6->setObjectName("rollButton_6");
        rollButton_6->setGeometry(QRect(630, 460, 81, 61));
        hpLabel = new QLabel(centralwidget);
        hpLabel->setObjectName("hpLabel");
        hpLabel->setGeometry(QRect(480, 330, 171, 41));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(230, 50, 341, 221));
        acLabel = new QLabel(centralwidget);
        acLabel->setObjectName("acLabel");
        acLabel->setGeometry(QRect(200, 340, 121, 31));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(120, 300, 151, 21));
        raceLabel = new QLabel(centralwidget);
        raceLabel->setObjectName("raceLabel");
        raceLabel->setGeometry(QRect(330, 300, 151, 21));
        classLabel = new QLabel(centralwidget);
        classLabel->setObjectName("classLabel");
        classLabel->setGeometry(QRect(500, 300, 151, 21));
        skillsLabel = new QLabel(centralwidget);
        skillsLabel->setObjectName("skillsLabel");
        skillsLabel->setGeometry(QRect(40, 570, 101, 16));
        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(30, 610, 101, 81));
        abilitiesLabel = new QLabel(centralwidget);
        abilitiesLabel->setObjectName("abilitiesLabel");
        abilitiesLabel->setGeometry(QRect(440, 570, 81, 16));
        abilityLabel = new QLabel(centralwidget);
        abilityLabel->setObjectName("abilityLabel");
        abilityLabel->setGeometry(QRect(230, 600, 111, 41));
        rollAbilityButton = new QPushButton(centralwidget);
        rollAbilityButton->setObjectName("rollAbilityButton");
        rollAbilityButton->setGeometry(QRect(220, 650, 71, 41));
        abilityLabel_2 = new QLabel(centralwidget);
        abilityLabel_2->setObjectName("abilityLabel_2");
        abilityLabel_2->setGeometry(QRect(340, 600, 111, 41));
        rollAbilityButton_2 = new QPushButton(centralwidget);
        rollAbilityButton_2->setObjectName("rollAbilityButton_2");
        rollAbilityButton_2->setGeometry(QRect(330, 650, 71, 41));
        abilityLabel_3 = new QLabel(centralwidget);
        abilityLabel_3->setObjectName("abilityLabel_3");
        abilityLabel_3->setGeometry(QRect(440, 600, 111, 41));
        rollAbilityButton_3 = new QPushButton(centralwidget);
        rollAbilityButton_3->setObjectName("rollAbilityButton_3");
        rollAbilityButton_3->setGeometry(QRect(430, 650, 71, 41));
        abilityLabel_4 = new QLabel(centralwidget);
        abilityLabel_4->setObjectName("abilityLabel_4");
        abilityLabel_4->setGeometry(QRect(560, 600, 111, 41));
        rollAbilityButton_4 = new QPushButton(centralwidget);
        rollAbilityButton_4->setObjectName("rollAbilityButton_4");
        rollAbilityButton_4->setGeometry(QRect(550, 650, 71, 41));
        abilityLabel_5 = new QLabel(centralwidget);
        abilityLabel_5->setObjectName("abilityLabel_5");
        abilityLabel_5->setGeometry(QRect(660, 600, 111, 41));
        rollAbilityButton_5 = new QPushButton(centralwidget);
        rollAbilityButton_5->setObjectName("rollAbilityButton_5");
        rollAbilityButton_5->setGeometry(QRect(650, 650, 71, 41));
        importButton = new QPushButton(centralwidget);
        importButton->setObjectName("importButton");
        importButton->setGeometry(QRect(10, 10, 75, 24));
        exportButton = new QPushButton(centralwidget);
        exportButton->setObjectName("exportButton");
        exportButton->setGeometry(QRect(110, 10, 75, 24));
        hpEdit = new QSpinBox(centralwidget);
        hpEdit->setObjectName("hpEdit");
        hpEdit->setGeometry(QRect(430, 340, 42, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 856, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Dodaj posta\304\207", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Usu\305\204", nullptr));
        levelUpButton->setText(QCoreApplication::translate("MainWindow", "Zwi\304\231ksz poziom", nullptr));
        rollButton->setText(QCoreApplication::translate("MainWindow", "Rzu\304\207 ko\305\233ci\304\205", nullptr));
        statLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        statLabel_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rollButton_2->setText(QCoreApplication::translate("MainWindow", "Rzu\304\207 ko\305\233ci\304\205", nullptr));
        statLabel_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rollButton_3->setText(QCoreApplication::translate("MainWindow", "Rzu\304\207 ko\305\233ci\304\205", nullptr));
        statLabel_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rollButton_4->setText(QCoreApplication::translate("MainWindow", "Rzu\304\207 ko\305\233ci\304\205", nullptr));
        statLabel_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rollButton_5->setText(QCoreApplication::translate("MainWindow", "Rzu\304\207 ko\305\233ci\304\205", nullptr));
        statLabel_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rollButton_6->setText(QCoreApplication::translate("MainWindow", "Rzu\304\207 ko\305\233ci\304\205", nullptr));
        hpLabel->setText(QCoreApplication::translate("MainWindow", "/xx punkt\303\263w zdrowia", nullptr));
        acLabel->setText(QCoreApplication::translate("MainWindow", "Klasa pancerza: x", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "Imi\304\231:", nullptr));
        raceLabel->setText(QCoreApplication::translate("MainWindow", "Rasa:", nullptr));
        classLabel->setText(QCoreApplication::translate("MainWindow", "Klasa:", nullptr));
        skillsLabel->setText(QCoreApplication::translate("MainWindow", "Umiej\304\231tno\305\233ci:", nullptr));
        abilitiesLabel->setText(QCoreApplication::translate("MainWindow", "Zdolno\305\233ci:", nullptr));
        abilityLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rollAbilityButton->setText(QCoreApplication::translate("MainWindow", "Rzu\304\207 ko\305\233ci\304\205", nullptr));
        abilityLabel_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rollAbilityButton_2->setText(QCoreApplication::translate("MainWindow", "Rzu\304\207 ko\305\233ci\304\205", nullptr));
        abilityLabel_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rollAbilityButton_3->setText(QCoreApplication::translate("MainWindow", "Rzu\304\207 ko\305\233ci\304\205", nullptr));
        abilityLabel_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rollAbilityButton_4->setText(QCoreApplication::translate("MainWindow", "Rzu\304\207 ko\305\233ci\304\205", nullptr));
        abilityLabel_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rollAbilityButton_5->setText(QCoreApplication::translate("MainWindow", "Rzu\304\207 ko\305\233ci\304\205", nullptr));
        importButton->setText(QCoreApplication::translate("MainWindow", "Importuj", nullptr));
        exportButton->setText(QCoreApplication::translate("MainWindow", "Eksportuj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
