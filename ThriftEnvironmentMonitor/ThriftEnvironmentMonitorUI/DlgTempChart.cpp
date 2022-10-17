#include "DlgTempChart.h"
#include <QtCore/QRandomGenerator>



DlgTempChart::DlgTempChart(QGraphicsItem* parent , Qt::WindowFlags wFlags):
    QChart(DlgTempChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axisX(new QDateTimeAxis()),
    m_axisY(new QValueAxis()),
    m_step(0),
    m_x(5),
    m_y(4.5)
{

    ScrolTime = QDateTime::currentDateTime().addSecs(0);

    QObject::connect(&m_timer, &QTimer::timeout, this, &DlgTempChart::HandleTimeout);
    //每一秒刷新一次
    m_timer.setInterval(1000);

    QDateTime curDateTIme = QDateTime::currentDateTime();

    m_series = new QSplineSeries(this);
    QPen green(Qt::red);
    green.setWidth(1);
    m_series->setPen(green);

    m_series->append(curDateTIme.toMSecsSinceEpoch(), m_y);

    addSeries(m_series);

    addAxis(m_axisX, Qt::AlignBottom);
    addAxis(m_axisY, Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_axisX->setTickCount(10);
    m_axisX->setRange(curDateTIme.addSecs(0), curDateTIme.addSecs(10));
    m_axisX->setFormat("mm:ss");
    m_axisY->setRange(2, 7);

    m_timer.start();
}

DlgTempChart::~DlgTempChart()
{

}

void DlgTempChart::HandleTimeout()
{
    qreal x = plotArea().width() / m_axisX->tickCount();
    qreal y = (QRandomGenerator::global()->bounded(5) ) / m_axisX->tickCount();
    m_x += y;
    m_y = QRandomGenerator::global()->bounded(5) + 2.5;

    QDateTime curDateTIme = QDateTime::currentDateTime();

    QDateTime temp_AddTimePos = curDateTIme.addSecs(0);

    m_series->append(temp_AddTimePos.toMSecsSinceEpoch(), m_y);

    //toMSecsSinceEpoch(),采用qint64也可以实现判断
    if (QDateTime::currentDateTime().addSecs(0) > ScrolTime.addSecs(9))
    {
        scroll(x, 0);
    }

    if (m_x == 100)
        m_timer.stop();
}
