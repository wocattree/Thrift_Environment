#pragma once
#include "Device.h"
#include <boost/noncopyable.hpp>

class ThreadBase : boost::noncopyable
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

