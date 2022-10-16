#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ThriftEnvironmentMonitorUI.h"
#include "Logs.h"


class ThriftEnvironmentMonitorUI : public QMainWindow
{
    Q_OBJECT

public:
    QImage img;

public:
    ThriftEnvironmentMonitorUI(QWidget *parent = nullptr);
    ~ThriftEnvironmentMonitorUI();

    //设置控件图片
    void SetLabelImg(const char* FilePath, QLabel* label);

private:
    Ui::ThriftEnvironmentMonitorUIClass ui;
};
