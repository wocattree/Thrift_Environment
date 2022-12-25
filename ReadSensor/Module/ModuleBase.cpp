////////////////////////////////
//filename:ModuleBase.cpp
//description:模块管理基类
//data:2022/09/17 20:10:50
//author:wocattree
////////////////////////////////

#include "ModuleBase.h"

CModuleBase::CModuleBase(CDevice* pDevice) :  CThreadBase(pDevice)
{

}

CModuleBase::~CModuleBase()
{

}

