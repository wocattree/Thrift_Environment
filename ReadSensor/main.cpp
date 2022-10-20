#include "Device.h"
#include "Monitor/Monitor.h"

int main(void)
{
    CDevice* pDevice = new CDevice();
    CMonitor* pMonitor = new CMonitor(pDevice);

    pMonitor->StarkWork();


    getchar();
}