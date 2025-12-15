#include "patientwindow.h"
#include "ui_patientwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

PatientWindow::PatientWindow(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::PatientWindow)
{
    ui->setupUi(this);
    setWindowTitle("Patient Management");
}

PatientWindow::~PatientWindow()
{
    delete ui;
}

/* ================= SAVE PATIENT ================= */
void PatientWindow::on_saveBtn_clicked()
{
    QString id   = ui->idLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString age  = ui->ageLineEdit->text();
    QString disease = ui->diseaseLineEdit->text();

    if(id.isEmpty() || name.isEmpty() || age.isEmpty() || disease.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please fill all fields");
        return;
    }

    QFile file("patients.txt");
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::critical(this, "Error", "File not opened");
        return;
    }

    QTextStream out(&file);
    out << "ID: " << id << "\n";
    out << "Name: " << name << "\n";
    out << "Age: " << age << "\n";
    out << "Disease: " << disease << "\n";
    out << "------------------------\n";

    file.close();

    QMessageBox::information(this, "Saved", "Patient record saved successfully");

    ui->idLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->ageLineEdit->clear();
    ui->diseaseLineEdit->clear();
}

/* ================= VIEW ALL ================= */
void PatientWindow::on_viewBtn_clicked()
{
    QFile file("patients.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "No records found");
        return;
    }

    QTextStream in(&file);
    QString data = in.readAll();
    file.close();

    QMessageBox::information(this, "All Patients", data);
}

/* ================= SEARCH BY ID ================= */
void PatientWindow::on_searchBtn_clicked()
{
    QString searchId = ui->idLineEdit->text();

    if(searchId.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter Patient ID");
        return;
    }

    QFile file("patients.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "File not found");
        return;
    }

    QTextStream in(&file);
    QString line;
    QString record;
    bool found = false;

    while(!in.atEnd())
    {
        line = in.readLine();

        if(line == "ID: " + searchId)
        {
            found = true;
            record = line + "\n";
            record += in.readLine() + "\n";
            record += in.readLine() + "\n";
            record += in.readLine() + "\n";
            break;
        }
    }

    file.close();

    if(found)
        QMessageBox::information(this, "Patient Found", record);
    else
        QMessageBox::information(this, "Result", "Patient not found");
}
