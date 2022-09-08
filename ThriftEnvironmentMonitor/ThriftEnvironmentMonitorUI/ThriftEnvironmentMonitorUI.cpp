#include "ThriftEnvironmentMonitorUI.h"
#include "DigiClock.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

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

	//添加在widget中显示
	QSplineSeries* LineSeries = new QSplineSeries();  //QSplineSeries 平滑曲线  QLineSeries折线
	for (double x = 0; x < 10; x += 0.1)
	{
		LineSeries->append(x, sin(x));
	}
	QChart* chart = new QChart();
	chart->addSeries(LineSeries);
	chart->legend()->hide();
	chart->createDefaultAxes();
	chart->setTheme(QChart::ChartThemeDark);
	ui.testwidget->setChart(chart);


}

ThriftEnvironmentMonitorUI::~ThriftEnvironmentMonitorUI()
{}

