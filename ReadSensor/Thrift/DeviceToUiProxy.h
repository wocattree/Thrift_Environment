#pragma once
////////////////////////////////
//filename:DeviceToUiProxy.h
//description:Thrift客户端文件
//data:2022/09/18 21:15:08
//author:wocattree
////////////////////////////////
class DeviceToUiProxy
{
public:

	static DeviceToUiProxy& GetInstance()
	{
		static DeviceToUiProxy instance;
		return instance;
	}

	////////////////////////////////
	//funcname:ReportDeviceTemps
	//description:返回树莓派读取的温度
	//param:
	//return:
	//data:2022/09/18 21:14:40
	//author:wocattree
	///////////////////////////////
	void ReportDeviceTemps(double temp, double humi);

private:
	DeviceToUiProxy();
	~DeviceToUiProxy();
};
