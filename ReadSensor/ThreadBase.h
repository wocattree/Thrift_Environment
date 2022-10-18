#pragma once
#include "Device.h"

class ThreadBase : boost::noncopyable
				 : public std::enable_shared_from_this<ThreadBase>
{
public:
	ThreadBase(CDevice* pDevice);
	~ThreadBase();

public:
	bool IsStop();
	bool HasError();
	bool IsPause();
	bool Continue();

private:
	bool t_stop;
    bool t_error;
	bool t_pause;

};

