#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_environmentMonitorWidget.h"
#include "../Common/Logs.h"


class environmentMonitorWidget : public QMainWindow
{
    Q_OBJECT

public:
    QImage img;

public:
    environmentMonitorWidget(QWidget *parent = nullptr);
    ~environmentMonitorWidget();

    //设置控件图片
    void SetLabelImg(const char* FilePath, QLabel* label);

private:
    Ui::ThriftEnvironmentMonitorUIClass ui;
};
