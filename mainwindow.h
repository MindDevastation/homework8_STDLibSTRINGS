#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "encoding.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Encoding encode;

private slots:
    void on_Check_clicked();

    void on_Enter_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
