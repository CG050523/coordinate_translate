#include "coordinate_translate.h"
#include <cmath>

coordinate_translate::coordinate_translate(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    set_button();
    set_lineEdit();
    build_lineEdit_connect();
    connect(button_switch_lbh, &QPushButton::clicked, this, &coordinate_translate::lbh2xyz);
    connect(button_switch_xyz, &QPushButton::clicked, this, &coordinate_translate::xyz2lbh);
    
}

coordinate_translate::~coordinate_translate()
{

}

void coordinate_translate::lbh2xyz()
{
    lamda = lamda * pi / 180;
    phi = phi * pi / 180;
    N = a / sqrtf(1 - e2 * powf(sinf(phi), 2));
    x = (N + h) * cosf(phi) * cosf(lamda);
    y = (N + h) * cosf(phi) * sinf(lamda);
    z = (N * (1 - e2) + h) * sinf(phi);
    phi = phi * 180 / pi;
    lamda = lamda * 180 / pi;

    inputtext_x->setText(QString::number(x, 'f', 6));

    inputtext_y->setText(QString::number(y, 'f', 6));
               
    inputtext_z->setText(QString::number(z, 'f', 6));
               
    inputtext_l->setText(QString::number(lamda, 'f', 6));
               
    inputtext_b->setText(QString::number(phi, 'f', 6));
               
    inputtext_h->setText(QString::number(h, 'f', 6));
}

void coordinate_translate::xyz2lbh()
{
    double p = sqrtl(powl(x, 2) + powl(y, 2));
    lamda = atan2l(y, x) * 180 / pi;
    phi = 0;
    for (int i = 0; i < 5; i++)
    {
        N = a / sqrtl(1 - e2 * powl(sinl(phi), 2));
        h = p / cosl(phi) - N;
        phi = atan2l(z  * 1 / ((1 - e2 * (N / (N + h)))),p);
    }
    phi = phi * 180 / pi;

    inputtext_x->setText(QString::number(x, 'f', 6));

    inputtext_y->setText(QString::number(y, 'f', 6));

    inputtext_z->setText(QString::number(z, 'f', 6));

    inputtext_l->setText(QString::number(lamda, 'f', 6));

    inputtext_b->setText(QString::number(phi, 'f', 6));

    inputtext_h->setText(QString::number(h, 'f', 6));
}

void coordinate_translate::set_button()
{
    button_switch_lbh->setParent(this);
    button_switch_lbh->setFixedSize(60, 20);
    button_switch_lbh->move(200, 20);
    button_switch_lbh->setText("lbh->xyz");
    button_switch_xyz->setParent(this);
    button_switch_xyz->setFixedSize(60, 20);
    button_switch_xyz->move(300, 20);
    button_switch_xyz->setText("xyz->lbh");
}

void coordinate_translate::set_lineEdit()
{
    inputtext_x->setParent(this);
    inputtext_x->setFixedSize(150, 20);
    inputtext_x->setPlaceholderText("input:x");
    inputtext_x->move(20, 20);
    inputtext_y->setParent(this);
    inputtext_y->setFixedSize(150, 20);
    inputtext_y->setPlaceholderText("input:y");
    inputtext_y->move(20, 60);
    inputtext_z->setParent(this);
    inputtext_z->setFixedSize(150, 20);
    inputtext_z->setPlaceholderText("input:z");
    inputtext_z->move(20, 100);
    inputtext_l->setParent(this);
    inputtext_l->setFixedSize(150, 20);
    inputtext_l->setPlaceholderText("input:l");
    inputtext_l->move(400, 20);
    inputtext_b->setParent(this);
    inputtext_b->setFixedSize(150, 20);
    inputtext_b->setPlaceholderText("input:b");
    inputtext_b->move(400, 60);
    inputtext_h->setParent(this);
    inputtext_h->setFixedSize(150, 20);
    inputtext_h->setPlaceholderText("input:h");
    inputtext_h->move(400, 100);
}

void coordinate_translate::build_lineEdit_connect()
{
    connect(inputtext_l, &QLineEdit::textEdited,
        [&](QString text_l)
        {
            lamda = text_l.toDouble();
        });
    connect(inputtext_b, &QLineEdit::textEdited,
        [&](QString text_b)
        {
            phi = text_b.toDouble();
        });
    connect(inputtext_h, &QLineEdit::textEdited,
        [&](QString text_h)
        {
            h = text_h.toDouble();
        });
    connect(inputtext_x, &QLineEdit::textEdited,
        [&](QString text_x)
        {
            x = text_x.toDouble();
        });
    connect(inputtext_y, &QLineEdit::textEdited,
        [&](QString text_y)
        {
            y = text_y.toDouble();
        });
    connect(inputtext_z, &QLineEdit::textEdited,
        [&](QString text_z)
        {
            z = text_z.toDouble();
        });
}