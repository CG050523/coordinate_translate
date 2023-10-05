#pragma once

#include <QtWidgets/QMainWindow>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qmenubar.h>
#include "ui_coordinate_translate.h"

class coordinate_translate : public QMainWindow
{
    Q_OBJECT

public:
    double e2 = 0.00669437999013;
    double a = 6378137.0;
    double b = 6356752.3142;
    double pi = 3.1415926;
    double N = 0;
    double lamda = 0, phi = 0, h = 0;
    double x = 0, y = 0, z = 0;
    int press_flag = 0;
    void set_button();
    void set_lineEdit();
    void build_lineEdit_connect();
    coordinate_translate(QWidget *parent = nullptr);
    ~coordinate_translate();
public slots:
    void lbh2xyz();
    void xyz2lbh();
private:
    QPushButton* button_switch_xyz = new QPushButton;
    QPushButton* button_switch_lbh = new QPushButton;
    QLineEdit* inputtext_l = new QLineEdit;
    QLineEdit* inputtext_b = new QLineEdit;
    QLineEdit* inputtext_h = new QLineEdit;
    QLineEdit* inputtext_x = new QLineEdit;
    QLineEdit* inputtext_y = new QLineEdit;
    QLineEdit* inputtext_z = new QLineEdit;
    Ui::coordinate_translateClass ui;
};
