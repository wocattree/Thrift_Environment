#include "MonitorTempHumiThread.h"
#include<cmath>

CMonitorHumiThread::CMonitorHumiThread(CDevice* pDevice) : CThreadMonitorBase(pDevice)
{

}

CMonitorHumiThread::~CMonitorHumiThread()
{

}



int CMonitorHumiThread::Run()
{
	if (-1 == wiringPiSetup())
	{
		printf("Setup WiringPi failed!\n");

		//DLOG
	}
	
	m_spThread.reset(new	std::thread([&]() {
		std::this_thread::sleep_for(std::chrono::seconds(3));
		BeginRecvTempHumi();
		}));
	return 1;
}

/*
//��ʼ������
//�ϵ�1s�ڲ�������ά�ֵ�ƽ�ȶ�
*/
void CMonitorHumiThread::GPIO_init(int gpio_pin)
{
	pinMode(gpio_pin, OUTPUT); // set mode to output
	digitalWrite(gpio_pin, 1); // output a high level

	sleep(1);

	return;
}

/*
//��ʼ�ź�
	1.������״̬�Ǹߵ�ƽ��Ҫ����1s�ȶ���ƽ
	2.������������ʱ18ms-30ms
	3.����ĩ״̬�Ǹߵ�ƽ���ȴ�
*/
void CMonitorHumiThread::DHT11_start(int gpio_pin)
{
	pinMode(gpio_pin, OUTPUT);
	digitalWrite(gpio_pin, 0);

	delay(25);

	digitalWrite(gpio_pin, 1);
	pinMode(gpio_pin, INPUT);
	pullUpDnControl(gpio_pin, PUD_UP);	//�����ű�����Ϊ����(INPUT)ģʽ��ʹ�ú���pullUpDnControl���������ڲ��������������������

	delayMicroseconds(27);

	return;
}

/*
//������������
	1.�������ܵ��ӻ��ظ�����Ӧ�ź�
	2.��ʽ0����54us�ĵ͵�ƽ+23��27us�ĸߵ�ƽ
	  ��ʽ1����54us�ĵ͵�ƽ+68��74us�ĸߵ�ƽ
	3.˼·����ʶ�𵽵͵�ƽ��ʼ��Ȼ��ȥ������ǰ��54��ĵ͵�ƽ����
*/
uint8 CMonitorHumiThread::DHT11_read(int gpio_pin)
{
	uint8 crc, i;

	if (0 == digitalRead(gpio_pin))			//�������յ��ӻ����͵���Ӧ�źţ��͵�ƽ��
	{
		while (!digitalRead(gpio_pin));		//�������յ��ӻ����͵���Ӧ�źţ��ߵ�ƽ��

		for (i = 0; i < 32; i++)
		{
			while (digitalRead(gpio_pin));	//����λ��ʼ��54us�͵�ƽ
			while (!digitalRead(gpio_pin));	//����λ��ʼ�ĸߵ�ƽ�Ϳ�ʼ

			delayMicroseconds(32);			//����λ���ݣ�32us�Ѿ�������0������1�Ĳ���

			databuf *= 2;

			if (digitalRead(gpio_pin) == 1)
			{
				databuf++;
			}
		}

		for (i = 0; i < 8; i++)
		{
			while (digitalRead(gpio_pin));
			while (!digitalRead(gpio_pin));

			delayMicroseconds(32);

			crc *= 2;
			if (digitalRead(gpio_pin) == 1)
			{
				crc++;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}


void CMonitorHumiThread::BeginRecvTempHumi()
{
    GPIO_init(2);

    DHT11_start(2);

    if (DHT11_read(2))
    {
        printf("RH:%d.%d\n", (databuf >> 24) & 0xff, (databuf >> 16) & 0xff);
        printf("TMP:%d.%d\n", (databuf >> 8) & 0xff, databuf & 0xff);

        double humi = ((databuf >> 24) & 0xff) + (((databuf >> 16) & 0xff) / 1.0);
        double temp = ((databuf >> 8) & 0xff) + (((databuf & 0xff) / 10.0));
        auto& m_DeviceToUiProxy = DeviceToUiProxy::GetInstance();
        round(10 / 8.0 * 10) / 10.0;

        temp = round(temp * 100) / 100.0;

        m_DeviceToUiProxy.ReportDeviceTemps(temp, humi);

        databuf = 0;
    }
    else
    {
        printf("Sensor dosent ans!\n");
        databuf = 0;
    }
}

void CMonitorHumiThread::WaitThreadFinish()
{
    if (m_spThread != nullptr && m_spThread->joinable())
    {
        m_spThread->join();
    }
}
