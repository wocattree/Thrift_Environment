#include "DigiClock.h"


DigiClock::DigiClock(QWidget* parent) :
	QLCDNumber(parent)
{
	QPalette p = palette();
	//p.setColor(QPalette::Window, Qt::blue);
	setPalette(p);

	setWindowFlags(Qt::FramelessWindowHint);
	//setWindowOpacity(0.5);

	QTimer* timer = new QTimer(this);
	this->setDigitCount(19);
	connect(timer, SIGNAL(timeout()), this, SLOT(ShowTime()));
	timer->start(500);
	ShowTime();
	resize(100, 50);
	showColon = true;
}

void DigiClock::ShowTime()
{
	QDateTime time = QDateTime::currentDateTime();
	QString text = time.toString("yyyy MM dd HH:mm:ss");
	/*if (showColon)
	{
		text[2] = ':';
		showColon = false;
	}
	else
	{
		text[2] = ' ';
		showColon = true;
	}
	*/
	display(text);
}

void DigiClock::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		dragPosition = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
	else if (event->button() == Qt::RightButton)
	{
		close();
	}
}
void DigiClock::mouseMoveEvent(QMouseEvent* event)
{
	move(event->globalPos() - dragPosition);
	event->accept();
}