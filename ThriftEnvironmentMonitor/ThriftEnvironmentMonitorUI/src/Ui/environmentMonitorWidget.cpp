#include "environmentMonitorWidget.h"
#include "../Ui/component/DlgDataTime.h"
#include "../Ui/component/DlgTempChart.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>


environmentMonitorWidget::environmentMonitorWidget(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *Clock = new DlgDataTime();
    ui.setupUi(this);
    //添加时间控件
    ui.DataTimeHlayout->addWidget(Clock);

    //设置按钮图标
    ui.pbBack->setIcon(QIcon(":/src/Ui/png/信息查询.png"));
    ui.pbBack->setIconSize(QSize(80, 80));
    SetLabelImg(":/src/Ui/png/照明.png", ui.Label_Light);
    SetLabelImg(":/src/Ui/png/新风管.png", ui.Label_Fan);
    SetLabelImg(":/src/Ui/png/摄氏度.png", ui.Label_Temp);
    SetLabelImg(":/src/Ui/png/湿度.png", ui.Label_Humi);
    SetLabelImg(":/src/Ui/png/二氧化碳.png", ui.Label_CO2);
    SetLabelImg(":/src/Ui/png/日照.png", ui.Label_LightValue);
    SetLabelImg(":/src/Ui/png/开关-开.png", ui.Label_Switch);
    SetLabelImg(":/src/Ui/png/开关-关.png", ui.Label_Switch_2);

    ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //添加当前时间到表格
    QDateTime TabelTime = QDateTime::currentDateTime();
    QString STabelTime = TabelTime.toString("yyyy/MM/dd HH:mm:ss");
    QTableWidgetItem* Item = new QTableWidgetItem(STabelTime);
    ui.tableWidget->setItem(0, 0, Item);

    DlgTempChart* chart = new DlgTempChart();
    chart->setTitle("温湿度曲线");
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);
    ui.testwidget->setRenderHint(QPainter::Antialiasing);
    ui.testwidget->setChart(chart);

    connect(ui.MainListWidget, SIGNAL(currentRowChanged(int)), ui.MainStackWidget, SLOT(setCurrentIndex(int)));
    connect(ui.pbBack, &QPushButton::clicked, this, &environmentMonitorWidget::signalBack);

    ui.la_envi_view->setPixmap(QPixmap(":/src/Ui/png/监控.png"));
    ui.la_envi_view->setScaledContents(true);
}

environmentMonitorWidget::~environmentMonitorWidget()
{}

void environmentMonitorWidget::SetLabelImg(const char* FilePath, QLabel* label)
{
    img.load(FilePath);
    QPixmap pixmap = QPixmap::fromImage(img);
    int with = label->width();
    int height = label->height();
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
    label->setPixmap(fitpixmap);
}