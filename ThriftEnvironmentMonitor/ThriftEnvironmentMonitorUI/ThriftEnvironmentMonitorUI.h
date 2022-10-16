#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ThriftEnvironmentMonitorUI.h"
#include "Logs.h"


class ThriftEnvironmentMonitorUI : public QMainWindow
{
    Q_OBJECT

public:
    ThriftEnvironmentMonitorUI(QWidget *parent = nullptr);
    ~ThriftEnvironmentMonitorUI();

private:
    Ui::ThriftEnvironmentMonitorUIClass ui;
};
