#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private slots:
    void on_btnAdd_clicked();

    void on_btnRemove_clicked();

    void on_btnRemoveAll_clicked();

private:
    Ui::MainWindow2 *ui;
};

#endif // MAINWINDOW2_H
