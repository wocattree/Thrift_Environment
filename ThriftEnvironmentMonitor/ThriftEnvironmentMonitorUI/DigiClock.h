#pragma once
#ifndef DIGICLOCK_H
#define DIGICLOCK_H

#include <QLCDNumber>
#include <QTime>
#include <QTimer>
#include <QMouseEvent>

class DigiClock : public QLCDNumber
{
	Q_OBJECT
public:
	DigiClock(QWidget* parent = 0);
	void mousePressEvent(QMouseEvent*);//重载函数响应鼠标按下
	void mouseMoveEvent(QMouseEvent*);//重载函数响应鼠标移动
public slots:
	void ShowTime();
private:
	QPoint dragPosition;
	bool showColon;
};

#endif // DIGICLOCK_H