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
    static const int cMaxServoPackets = 16;

    ServoControl(QObject* parent, Vehicle* vehicle);

    Q_INVOKABLE void toggleDayLight(int);
    Q_INVOKABLE void toggleNightLight(int);

    void setDayLight(int);
    void setNightLight(int);

    bool dayLightState();
    bool nightLightState();

    bool _dayLightState = false;
    bool _nightLightState = false;

    void dayLightEnable(int);
    void dayLightDisable(int);
    void nightLightEnable(int);
    void nightLightDisable(int);
private:
    Vehicle* _vehicle;
private slots:
    void _servoChannelsChanged(int pwmServoValues[cMaxServoPackets]);
};

