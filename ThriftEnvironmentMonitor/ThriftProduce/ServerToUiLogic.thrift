struct MonitorTemps
{
	1:list<double> Temps										//温度值列表
}

service DeviceToUi										//下位机传递到客户端的服务
{
	void ReportDeviceTemps(1:MonitorTemps monitortemps);					//定义下位机传输接口
}