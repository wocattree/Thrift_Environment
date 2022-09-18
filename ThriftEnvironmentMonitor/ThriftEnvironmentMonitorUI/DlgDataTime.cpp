#include "DlgDataTime.h"

#include <iomanip>

#include <sstream>

DlgDataTime::DlgDataTime(QWidget* parent) :
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

void DlgDataTime::ShowTime()
{
    QDateTime time = QDateTime::currentDateTime();
    //QString text = time.toString("yyyy MM dd HH:mm:ss");
    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ss;
    ss << std::put_time(std::localtime(&t), "%F %T");// %F %T 等价于 %Y-%m-%d %H:%M:%S
    std::string str = ss.str();
    QString text = QString::fromStdString(str);

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

void DlgDataTime::mousePressEvent(QMouseEvent* event)
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
void DlgDataTime::mouseMoveEvent(QMouseEvent* event)
{
    move(event->globalPos() - dragPosition);
    event->accept();
}