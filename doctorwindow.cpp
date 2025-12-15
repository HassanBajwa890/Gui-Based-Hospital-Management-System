#include "doctorwindow.h"
#include "ui_doctorwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

DoctorWindow::DoctorWindow(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::DoctorWindow)
{
    ui->setupUi(this);
    setWindowTitle("Doctor Management");
}

DoctorWindow::~DoctorWindow()
{
    delete ui;
}

/* ================= SAVE DOCTOR ================= */
void DoctorWindow::on_saveDoctorBtn_clicked()
{
    QString name = ui->docNameLineEdit->text();
    QString age  = ui->docAgeLineEdit->text();
    QString spec = ui->specializationLineEdit->text();

    if(name.isEmpty() || age.isEmpty() || spec.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please fill all fields");
        return;
    }

    QFile file("doctors.txt");
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::critical(this, "Error", "File not opened");
        return;
    }

    QTextStream out(&file);
    out << "Name: " << name << "\n";
    out << "Age: " << age << "\n";
    out << "Specialization: " << spec << "\n";
    out << "------------------------\n";

    file.close();

    QMessageBox::information(this, "Saved", "Doctor record saved");

    ui->docNameLineEdit->clear();
    ui->docAgeLineEdit->clear();
    ui->specializationLineEdit->clear();
}

/* ================= VIEW DOCTOR ================= */
void DoctorWindow::on_viewDoctorBtn_clicked()
{
    QFile file("doctors.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "No records found");
        return;
    }

    QTextStream in(&file);
    QString data = in.readAll();
    file.close();

    QMessageBox::information(this, "Doctor Records", data);
}

/* ================= CLOSE ================= */
void DoctorWindow::on_closeDoctorBtn_clicked()
{
    close();
}
