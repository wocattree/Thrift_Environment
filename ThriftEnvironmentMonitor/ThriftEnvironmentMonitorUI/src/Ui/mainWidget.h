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

public:
	mainWidget(QWidget *parent = nullptr);
	~mainWidget();

private slots:
	void ShowEnvironmentStatus();

private:
	Ui::MainWidgetsClassClass ui;
	QPushButton *LabelHomeStatu;			//环境状态按钮
	QPushButton *LabelHistory;				//历史数据按钮
	QGridLayout* MainGridLayout;				//主窗口布局
	QFont MainWigetFont;					//字体设置
	QLabel *currentStu;						//运行状态
	environmentMonitorWidget* EnvironmentStu;	//窗口界面
};
