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

    //设置按钮图标
    ui.BtnShutDown->setIcon(QIcon("./png/关机.png"));
    ui.BtnShutDown->setIconSize(QSize(80,80));

    ui.BtnQuery->setIcon(QIcon("./png/信息查询.png"));
    ui.BtnQuery->setIconSize(QSize(80, 80));

    SetLabelImg("./png/照明.png", ui.Label_Light);
    SetLabelImg("./png/新风管.png", ui.Label_Fan);
    SetLabelImg("./png/摄氏度.png", ui.Label_Temp);
    SetLabelImg("./png/湿度.png", ui.Label_Humi);
    SetLabelImg("./png/二氧化碳.png", ui.Label_CO2);
    SetLabelImg("./png/日照.png", ui.Label_LightValue);
    SetLabelImg("./png/开关-开.png", ui.Label_Switch);
    SetLabelImg("./png/开关-关.png", ui.Label_Switch_2);

    ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

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
    ui.testwidget->setRenderHint(QPainter::Antialiasing);
    ui.testwidget->setChart(chart);
}

ThriftEnvironmentMonitorUI::~ThriftEnvironmentMonitorUI()
{}

void ThriftEnvironmentMonitorUI::SetLabelImg(const char* FilePath, QLabel* label)
{
    img.load(FilePath);
    QPixmap pixmap = QPixmap::fromImage(img);
    int with = label->width();
    int height = label->height();
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
    label->setPixmap(fitpixmap);
}