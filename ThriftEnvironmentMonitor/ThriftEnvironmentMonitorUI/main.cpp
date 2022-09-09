#include "ThriftEnvironmentMonitorUI.h"
#include <QtWidgets/QApplication>
#include "../EnvironmentMonitor/logs.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThriftEnvironmentMonitorUI w;
    SystemLogs *Logs = new SystemLogs;

    w.show();
    return a.exec();
}
