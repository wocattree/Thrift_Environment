#include "ThriftEnvironmentMonitorUI.h"
#include "DlgDataTime.h"
#include "DlgTempChart.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>


ThriftEnvironmentMonitorUI::ThriftEnvironmentMonitorUI(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *Clock = new DlgDataTime();
    ui.setupUi(this);
    //添加时间控件
    ui.DataTimeHlayout->addWidget(Clock);

    //添加当前时间到表格
    QDateTime TabelTime = QDateTime::currentDateTime();
    QString STabelTime = TabelTime.toString("yyyy/MM/dd HH:mm:ss");
    QTableWidgetItem* Item = new QTableWidgetItem(STabelTime);
    ui.tableWidget->setItem(0, 0, Item);


    connect(ui.BtnShutDown, SIGNAL(clicked()), this, SLOT(close()));

    DlgTempChart* chart = new DlgTempChart();
    chart->setTitle("温湿度曲线");
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);
    //QChartView chartView(chart); 控件已经在UI里提升为QchartView类型，因此不用转换
    //chartView.setRenderHint(QPainter::Antialiasing);
    ui.testwidget->setRenderHint(QPainter::Antialiasing);
    ui.testwidget->setChart(chart);


}

ThriftEnvironmentMonitorUI::~ThriftEnvironmentMonitorUI()
{}

