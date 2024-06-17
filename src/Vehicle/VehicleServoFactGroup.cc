/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include <iostream>

#include "VehicleServoFactGroup.h"
#include "MAVLinkProtocol.h"
#include "Vehicle.h"
#include "QGCGeo.h"

#define DAY_LIGHT_SERVO   11
#define NIGHT_LIGHT_SERVO 3
#define PWM_VALUE         1500

const char* VehicleServoFactGroup::_dayLightFactName   = "dayLight";
const char* VehicleServoFactGroup::_nightLightFactName = "nightLight";

VehicleServoFactGroup::VehicleServoFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/ServoStatusFactGroup.json", parent)
    , _dayLightFact   (0, _dayLightFactName,   FactMetaData::valueTypeBool)
    , _nightLightFact (0, _nightLightFactName, FactMetaData::valueTypeBool)
{
    _addFact(&_dayLightFact,   _dayLightFactName);
    _addFact(&_nightLightFact, _nightLightFactName);

    // _dayLightFact.setRawValue(false);
    // _nightLightFact.setRawValue(false);
}

void VehicleServoFactGroup::handleMessage(Vehicle* /* vehicle */, mavlink_message_t& message)
{
    switch (message.msgid) {
    case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW:
        _handleServoOutputRaw(message);
        break;
    default:
        break;
    }
}

void VehicleServoFactGroup::_handleServoOutputRaw(mavlink_message_t& message)
{
    mavlink_servo_output_raw_t packet;

    mavlink_msg_servo_output_raw_decode(&message, &packet);

    uint16_t _rgChannelvalues[cMaxServoPackets] = {
        packet.servo1_raw,
        packet.servo2_raw,
        packet.servo3_raw,
        packet.servo4_raw,
        packet.servo5_raw,
        packet.servo6_raw,
        packet.servo7_raw,
        packet.servo8_raw,
        packet.servo9_raw,
        packet.servo10_raw,
        packet.servo11_raw,
        packet.servo12_raw,
        packet.servo13_raw,
        packet.servo14_raw,
        packet.servo15_raw,
        packet.servo16_raw
    };
 
    dayLight()   -> setRawValue ((_rgChannelvalues[DAY_LIGHT_SERVO - 1]   > PWM_VALUE) ? true : false);
    nightLight() -> setRawValue ((_rgChannelvalues[NIGHT_LIGHT_SERVO - 1] > PWM_VALUE) ? true : false);
}