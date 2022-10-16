#include "MonitorEnvironment.h"

int main(int argc, char *argv[])
{
	auto& m_pDeviceDB = DeviceDB::GetInstance();
	//连接数据库
	m_pDeviceDB.Connect("localhost", "root", "1234", "m_device", 0);

    QApplication a(argc, argv);
    ThriftEnvironmentMonitorUI w;
    w.show();
    return a.exec(); 
}
