#include <QApplication>
#include "controlpresencial.h"
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControlPresencial w;
    w.showFullScreen();

    w.show();
    
    return a.exec();

}
