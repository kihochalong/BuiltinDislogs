#include "cbuiltindig.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CBuiltinDig w;
    w.show();
    return a.exec();
}
