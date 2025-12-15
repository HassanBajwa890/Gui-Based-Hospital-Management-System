#ifndef DOCTORWINDOW_H
#define DOCTORWINDOW_H

#include <QDialog>

namespace Ui {
class DoctorWindow;
}

class DoctorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorWindow(QWidget *parent = nullptr);
    ~DoctorWindow();

private:
    Ui::DoctorWindow *ui;
private slots:
    void on_saveDoctorBtn_clicked();
    void on_viewDoctorBtn_clicked();
    void on_closeDoctorBtn_clicked();

};

#endif
