#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QMessageBox>
#include <QStandardPaths>
#include <QIODevice>
#include<QTextStream>
#include<QFile>

MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\toDoFile.txt");

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::critical(this, "Error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()){
        QListWidgetItem *item = new QListWidgetItem(in.readLine(), ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }

    file.close();
}

MainWindow2::~MainWindow2()
{
    delete ui;
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\toDoFile.txt");

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::critical(this, "Error", file.errorString());
    }

    QTextStream out(&file);

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        out<< ui->listWidget->item(i)->text()<< "\n";
    }

    file.close();
}

void MainWindow2::on_btnAdd_clicked()
{
    QString taskText = ui->txtTask->text().trimmed(); // Get trimmed text to remove leading/trailing whitespace
    if (taskText.isEmpty()) {
        QMessageBox::critical(this, "Error", "Task cannot be empty");
        return;
    }

    QListWidgetItem *item = new QListWidgetItem(taskText, ui->listWidget);
    ui->listWidget->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->txtTask->clear();
    ui->txtTask->setFocus();
}

void MainWindow2::on_btnRemove_clicked()
{
    QListWidgetItem *item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}


void MainWindow2::on_btnRemoveAll_clicked()
{
    ui->listWidget->clear();
}

