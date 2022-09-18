#pragma once
#include <QChart>
#include <QTimer>
#include <QSplineSeries>
#include <QValueAxis>

class DlgTempChart : public QChart
{
    Q_OBJECT
public:
    DlgTempChart(QGraphicsItem* parent = nullptr, Qt::WindowFlags = {});
    virtual ~DlgTempChart();
public slots:
    void HandleTimeout();
private:
    QTimer m_timer;
    QSplineSeries* m_series;
    QStringList m_titles;
    QValueAxis* m_axisX;
    QValueAxis* m_axisY;
    qreal m_step;
    qreal m_x;
    qreal m_y;
};