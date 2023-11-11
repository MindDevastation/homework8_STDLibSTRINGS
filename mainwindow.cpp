#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Enter->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Check_clicked()
{
    QString inp = ui->InputText->text();
    this->encode.setInput(inp);

    this->encode.encode();
    ui->label->setText("Encoded Text: " + this->encode.encondingOutput);

    ui->Enter->setEnabled(true);
}




void MainWindow::on_Enter_clicked()
{
    this->encode.decode();
    ui->label_2->setText("Decoded Text: " + this->encode.decodingOutput);
}

