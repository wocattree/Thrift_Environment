#include "ThriftEnvironmentMonitorUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThriftEnvironmentMonitorUI w;
    w.show();
    return a.exec();
}
