#include "mainWidget.h"
#include "./component/DlgDataTime.h"

mainWidget::mainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	InitUI();
	InitData();
	InitConnect();
}

void mainWidget::slotShowMainWidget()
{
	ui.mainStackedWidget->setCurrentIndex(EM_MAIN);
}

mainWidget::~mainWidget()
{}

////////////////////////////////
//function name:InitUI()
//description:初始化UI界面
//param in:
//
//return:
//
//data:2023/3/11 22:12
//
//author:wocattree
///////////////////////////////
void mainWidget::InitUI()
{
	this->setWindowTitle("我的家");

	ui.mainStackedWidget->setCurrentIndex(EM_MAIN);
}

////////////////////////////////
//function name:InitData()
//description:初始化数据
//param in:
//
//return:
//
//data:2023/3/11 22:14
//
//author:wocattree
///////////////////////////////
void mainWidget::InitData()
{
	QWgtHomeStatu = new QWidget(ui.page);
	QWgtHistory = new QWidget(ui.page);
	currentStu = new QLabel(ui.page);
	MainGridLayout = new QGridLayout(ui.page);
	MainWigetFont.setPointSize(20);
	Clock = new DlgDataTime();
	EnvironmentWgt = new environmentMonitorWidget(this);

	ui.mainStackedWidget->insertWidget(EM_ENV, EnvironmentWgt);

	currentStu->setText(tr("运行中。。。"));
	currentStu->setFont(MainWigetFont);
	currentStu->setAlignment(Qt::AlignHCenter);

	QLabel* lb_Env;
	lb_Env = new QLabel(QWgtHomeStatu);
	lb_Env->setText(tr("环境概括"));
	lb_Env->setFont(MainWigetFont);
	QWgtHomeStatu->setMaximumSize(512, 512);
	QWgtHomeStatu->setMinimumSize(512, 512);
	QWgtHomeStatu->setStyleSheet("border-image: url(:/src/Ui/png/MainButton1.png)");

	QLabel* lb_History;
	lb_History = new QLabel(QWgtHistory);
	lb_History->setText(tr("历史数据"));
	lb_History->setFont(MainWigetFont);
	QWgtHistory->setMaximumSize(512, 512);
	QWgtHistory->setMinimumSize(512, 512);
	QWgtHistory->setFont(MainWigetFont);
	QWgtHistory->setStyleSheet("border-image: url(:/src/Ui/png/MainButton2.png)");

	MainGridLayout->addWidget(Clock, 0, 0, 1, 2);
	MainGridLayout->addWidget(currentStu, 1, 0, 1, 2);
	MainGridLayout->addWidget(QWgtHomeStatu, 2, 0);
	MainGridLayout->addWidget(QWgtHistory, 2, 1);
}

////////////////////////////////
//function name:InitConnect()
//description:初始化连接
//param in:
//
//return:
//
//data:2023/3/11 22:13
//
//author:wocattree
///////////////////////////////
void mainWidget::InitConnect()
{
	connect(EnvironmentWgt, &environmentMonitorWidget::signalBack, this, &mainWidget::slotShowMainWidget);
}

bool mainWidget::judgeArea(QWidget* wgt, const QPoint& pos)
{
	int w = wgt->rect().width();
	int h = wgt->rect().height();
	//转为屏幕坐标
	auto wgtGlobalPos = wgt->mapToGlobal(QPoint(0, 0));
	QRect rect = QRect(wgtGlobalPos.x(), wgtGlobalPos.y(), w, h);
	return rect.contains(pos);
}

void mainWidget::mousePressEvent(QMouseEvent* event)
{
	//若鼠标左键按下
	if (event->button() == Qt::LeftButton && ui.mainStackedWidget->currentIndex() == EM_MAIN)
	{
		//鼠标位置转为屏幕坐标
		auto globalPos = event->globalPos();
		//判断点击的区域
		if (judgeArea(QWgtHomeStatu, globalPos))
		{
			ui.mainStackedWidget->setCurrentIndex(EM_ENV);
		}
		if (judgeArea(QWgtHistory, globalPos))
		{
			ui.mainStackedWidget->setCurrentIndex(EM_HISTORY);
		}
	}
	QWidget::mousePressEvent(event);
}
