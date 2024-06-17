/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


#pragma once

#include "QGCLoggingCategory.h"
#include "QGCMAVLink.h"
#include <QString>
#include <QMap>

class Vehicle;

class ServoControl : public QObject
{
Q_OBJECT

public:
    ServoControl(QObject* parent, Vehicle* vehicle);

    Q_INVOKABLE void setDayLightEnabled(bool, int);
    Q_INVOKABLE void setNightLightEnabled(bool, int);

    void dayLightEnable(int);
    void dayLightDisable(int);
    void nightLightEnable(int);
    void nightLightDisable(int);
private:
    Vehicle* _vehicle;
};

