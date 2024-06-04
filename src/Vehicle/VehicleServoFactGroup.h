/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "FactGroup.h"
#include "QGCMAVLink.h"

class VehicleServoFactGroup : public FactGroup
{
    Q_OBJECT

public:
    static const int cMaxServoPackets = 16;

    VehicleServoFactGroup(QObject* parent = nullptr);

    Q_PROPERTY(Fact* dayLight   READ dayLight   CONSTANT)
    Q_PROPERTY(Fact* nightLight READ nightLight CONSTANT)

    Fact* dayLight         () { return &_dayLightFact; }
    Fact* nightLight       () { return &_nightLightFact; }

    // Overrides from FactGroup
    virtual void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    static const char* _dayLightFactName;
    static const char* _nightLightFactName;

protected:
    void _handleServoOutputRaw(mavlink_message_t& message);

    Fact _dayLightFact;
    Fact _nightLightFact;
};
