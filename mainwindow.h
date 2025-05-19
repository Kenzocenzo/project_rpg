#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void listFiller();
    void characterFiller();
    void rollStatDice(int stat, QString name);

private slots:
    void on_importButton_clicked();

    void on_exportButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_rollButton_1_clicked();

    void on_rollButton_2_clicked();

    void on_rollButton_3_clicked();

    void on_rollButton_4_clicked();

    void on_rollButton_5_clicked();

    void on_rollButton_6_clicked();

    void on_rollAbilityButton_1_clicked();

    void on_rollAbilityButton_2_clicked();

    void on_rollAbilityButton_3_clicked();

    void on_rollAbilityButton_4_clicked();

    void on_rollAbilityButton_5_clicked();

    void on_hpEdit_valueChanged(int arg1);

    void on_deleteButton_clicked();

    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
