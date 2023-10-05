#include "coordinate_translate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    coordinate_translate w;
    w.show();
    return a.exec();
}
