#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString user= "1234";
QString user_input;


void MainWindow::on_pushButton_clicked()
{
    user_input= ui->lineEdit_Username->text();
    if(user== user_input)
    {
        this->hide();
        MainWindow2 *welcome_page= new MainWindow2();
        welcome_page->show();

    }
}

