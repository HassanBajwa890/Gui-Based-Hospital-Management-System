#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet(
        "QMainWindow {"
        "background-image: url(:/images/hospital_bg.jpg);"
        "background-position: center;"
        "background-repeat: no-repeat;"
        "}"
        );


    setWindowTitle("Hospital Management System");

    patientWindow = new PatientWindow(this);
    doctorWindow  = new DoctorWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_patientBtn_clicked()
{
    patientWindow->show();
}

void MainWindow::on_doctorBtn_clicked()
{
    doctorWindow->show();
}

void MainWindow::on_exitBtn_clicked()
{
    close();
}
