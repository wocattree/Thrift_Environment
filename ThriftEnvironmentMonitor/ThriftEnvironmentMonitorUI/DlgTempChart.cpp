#include "DlgTempChart.h"
#include <QtCore/QRandomGenerator>

DlgTempChart::DlgTempChart(QGraphicsItem* parent , Qt::WindowFlags wFlags):
    QChart(DlgTempChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axisX(new QDateTimeAxis()),
    m_axisY(new QValueAxis()),
    m_step(0),
    m_x(5),
    m_y(1)
{
    QObject::connect(&m_timer, &QTimer::timeout, this, &DlgTempChart::HandleTimeout);
    m_timer.setInterval(1000); //5ÃëË¢ÐÂÒ»´Î

    m_series = new QSplineSeries(this);
    QPen green(Qt::red);
    green.setWidth(1);
    m_series->setPen(green);
    m_series->append(m_x, m_y);

    addSeries(m_series);

    addAxis(m_axisX, Qt::AlignBottom);
    addAxis(m_axisY, Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_axisX->setTickCount(10);
    m_axisX->setRange(QDateTime::currentDateTime().addSecs(-10 * 1), QDateTime::currentDateTime().addSecs(0));
    m_axisX->setFormat("mm:ss");
    m_axisY->setRange(-20, 40);

    m_timer.start();
}

DlgTempChart::~DlgTempChart()
{

}

void DlgTempChart::HandleTimeout()
{
    qreal x = plotArea().width() / m_axisY->tickCount();
    qreal y = (10 - 0) / 2;
    m_x += y;
    m_y = m_x;
    m_series->append(m_x, m_y);
    scroll(x, 0);
    if (m_x == 100)
        m_timer.stop();

    /*qreal x = plotArea().width() / m_axisX->tickCount();
    qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    m_x += y;
    m_y = QRandomGenerator::global()->bounded(5) + 2.5;
    m_series->append(m_x, m_y);
    scroll(x, 0);
    if (m_x == 100)
        m_timer.stop();
    */
}