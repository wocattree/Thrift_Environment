#include "mainWidget.h"

enum
{
	ENVIRONMENT,		//环境概括界面
	HISTORY_DATA		//历史数据界面
};

mainWidget::mainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	LabelHomeStatu = new QPushButton(this);
	LabelHistory = new QPushButton(this);
	currentStu = new QLabel(this);
	MainGridLayout = new QGridLayout(this);
	MainWigetFont.setPointSize(20);

	EnvironmentStu = new environmentMonitorWidget();

	currentStu->setText(tr("运行中。。。"));
	currentStu->setFont(MainWigetFont);
	currentStu->setAlignment(Qt::AlignHCenter);

	LabelHomeStatu->setText(tr("环境概括"));
	LabelHomeStatu->setFont(MainWigetFont);
	LabelHomeStatu->setMaximumSize(512, 512);
	LabelHomeStatu->setMinimumSize(512, 512);
	LabelHomeStatu->setStyleSheet("QPushButton{border-image: url(:/src/Ui/png/MainButton1.png) }");

	LabelHistory->setText(tr("历史数据"));
	LabelHistory->setMaximumSize(512, 512);
	LabelHistory->setMinimumSize(512, 512);
	LabelHistory->setFont(MainWigetFont);
	LabelHistory->setStyleSheet("QPushButton{border-image: url(:/src/Ui/png/MainButton2.png)}");

	MainGridLayout->addWidget(currentStu, 0, 0 , 1 , 2);
	MainGridLayout->addWidget(LabelHomeStatu, 1, 0);
	MainGridLayout->addWidget(LabelHistory, 1, 1);
	//ui.mainStackedWidget->setCurrentWidget(EnvironmentStu);
	//ui.mainStackedWidget->addWidget(EnvironmentStu);

	//MainGridLayout->addWidget(ui.mainStackedWidget);

	//connect(LabelHomeStatu, SIGNAL(clicked()), ui.mainStackedWidget, SLOT(setCurrentIndex(ENVIRONMENT)));
	connect(LabelHomeStatu, SIGNAL(clicked()), this, SLOT(ShowEnvironmentStatus()));
}

void mainWidget::ShowEnvironmentStatus()
{
	this->hide();
	EnvironmentStu->show();
}

mainWidget::~mainWidget()
{}
