#include "ThriftEnvironmentMonitorUI.h"
#include "DigiClock.h"

ThriftEnvironmentMonitorUI::ThriftEnvironmentMonitorUI(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *Clock = new DigiClock();
    ui.setupUi(this);
    //添加时间控件
    ui.DataTimeHlayout->addWidget(Clock);

    //添加当前时间到表格
	QDateTime TabelTime = QDateTime::currentDateTime();
	QString STabelTime = TabelTime.toString("yyyy/MM/dd HH:mm:ss");
	QTableWidgetItem* Item = new QTableWidgetItem(STabelTime);
	ui.tableWidget->setItem(0, 0, Item);


    connect(ui.BtnShutDown, SIGNAL(clicked()), this, SLOT(close()));
}

ThriftEnvironmentMonitorUI::~ThriftEnvironmentMonitorUI()
{}
