struct MonitorTemps
{
	1:list<double> Temps										//�¶�ֵ�б�
}

service DeviceToUi										//��λ�����ݵ��ͻ��˵ķ���
{
	void ReportDeviceTemps(1:MonitorTemps monitortemps);					//������λ������ӿ�
}