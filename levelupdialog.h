#ifndef LEVELUPDIALOG_H
#define LEVELUPDIALOG_H

#include <QDialog>

namespace Ui {
class LevelUpDialog;
}

class LevelUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LevelUpDialog(QWidget *parent = nullptr);
    ~LevelUpDialog();
    void labelFiller();
    void textFiller(int stat);
    int getStat();
    QString getSkill();

private slots:
    void on_statBox_currentTextChanged(const QString &arg1);

private:
    Ui::LevelUpDialog *ui;
};

#endif // LEVELUPDIALOG_H
