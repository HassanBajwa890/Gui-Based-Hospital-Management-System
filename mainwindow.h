#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "patientwindow.h"
#include "doctorwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_patientBtn_clicked();
    void on_doctorBtn_clicked();
    void on_exitBtn_clicked();

private:
    Ui::MainWindow *ui;
    PatientWindow *patientWindow;
    DoctorWindow *doctorWindow;
};
#endif
