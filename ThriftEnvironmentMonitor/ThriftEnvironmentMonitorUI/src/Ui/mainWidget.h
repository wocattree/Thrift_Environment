#pragma once

#include <QWidget>
#include <QLabel>
#include <QFont>
#include <QGridLayout>
#include <QPushButton>
#include "environmentMonitorWidget.h"
#include "ui_mainWidget.h"

class mainWidget : public QWidget
{
	Q_OBJECT

	//各个页面索引
	enum ENUM_PAGE_INDEX
	{
		EM_MAIN = 0,		//主界面
		EM_ENV = 1,			//环境界面
		EM_HISTORY = 2		//历史数据界面
	};

public:
	mainWidget(QWidget *parent = nullptr);
	~mainWidget();

public:
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
	void InitUI();

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
	void InitData();

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
	void InitConnect();

private:
//判断鼠标是否点击对应的wgt
//wgt ：指定的wgt
//pos ：鼠标相对于屏幕的绝对位置
//return 1:是指定的wgt， 0:不是指定的
	bool judgeArea(QWidget* wgt, const QPoint& pos);

protected:
	//重写鼠标按下事件
	void mousePressEvent(QMouseEvent* event) override;

private slots:
	void slotShowMainWidget();

private:
	Ui::MainWidgetsClassClass ui;
	QWidget *QWgtHomeStatu;			//环境状态按钮
	QWidget*QWgtHistory;				//历史数据按钮
	QGridLayout* MainGridLayout;				//主窗口布局
	QFont MainWigetFont;					//字体设置
	QLabel *currentStu;						//运行状态
	environmentMonitorWidget* EnvironmentWgt;	//窗口界面
	QWidget* Clock;						//时钟显示
};
