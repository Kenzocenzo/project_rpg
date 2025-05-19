#ifndef ADDCHARACTERDIALOG_H
#define ADDCHARACTERDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QGridLayout>

namespace Ui {
class AddCharacterDialog;
}

class AddCharacterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCharacterDialog(QWidget *parent = nullptr);
    ~AddCharacterDialog();
    void hpSetter();
    void acSetter();
    void statChecker();
    void checkBoxChecker();

private slots:
    void on_constEdit_valueChanged(int arg1);

    void on_dexEdit_valueChanged(int arg1);

    void on_wsEdit_valueChanged(int arg1);

    void on_inteEdit_valueChanged(int arg1);

    void on_classBox_currentTextChanged(const QString &arg1);

    void on_strEdit_valueChanged(int arg1);

    void on_rizzEdit_valueChanged(int arg1);

private:
    Ui::AddCharacterDialog *ui;
    QVector<QCheckBox*> checkboxes;
    int hp;
    int ac;
    int statSum;
    int checkBoxCount;
};

#endif // ADDCHARACTERDIALOG_H
