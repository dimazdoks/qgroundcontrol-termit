/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


#include<iostream>
#include "Vehicle.h"
#include "ServoControl.h"

#define SERVO_PWM_ON  2000
#define SERVO_PWM_OFF 1000

#define DAY_LIGHT_SERVO   3
#define NIGHT_LIGHT_SERVO 11


ServoControl::ServoControl(QObject *parent, Vehicle *vehicle)
        : QObject(parent), _vehicle(vehicle)
{
    connect(_vehicle, &Vehicle::servoChannelsChanged, this, &ServoControl::_servoChannelsChanged);
}

void ServoControl::_servoChannelsChanged(int pwmServoValues[cMaxServoPackets]) {
    setDayLight(pwmServoValues[DAY_LIGHT_SERVO - 1]);
    setNightLight(pwmServoValues[NIGHT_LIGHT_SERVO - 1]);
}

void ServoControl::setDayLight(int pwmValue) {
    _dayLightState = pwmValue > 1500 ? true : false;
}

void ServoControl::setNightLight(int pwmValue) {
    _nightLightState = pwmValue > 1500 ? true : false;
}

bool ServoControl::dayLightState()
{
    return _dayLightState;
}

bool ServoControl::nightLightState()
{
    return _nightLightState;
}

void ServoControl::toggleDayLight(int _defaultComponentId) {
    if (dayLightState()) {
        dayLightDisable(_defaultComponentId);
    } else {
        dayLightEnable(_defaultComponentId);
    }
};

void ServoControl::toggleNightLight(int _defaultComponentId) {
    if (nightLightState()) {
        nightLightDisable(_defaultComponentId);
    } else {
        nightLightEnable(_defaultComponentId);
    }
};

// ----------------------------------------------------------------------------
void ServoControl::dayLightEnable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        DAY_LIGHT_SERVO,
        SERVO_PWM_ON
    );                
};

// ----------------------------------------------------------------------------
void ServoControl::dayLightDisable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        DAY_LIGHT_SERVO,
        SERVO_PWM_OFF
    );                
};

// ----------------------------------------------------------------------------
void ServoControl::nightLightEnable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        NIGHT_LIGHT_SERVO,
        SERVO_PWM_ON
    );                
};

// ----------------------------------------------------------------------------
void ServoControl::nightLightDisable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        NIGHT_LIGHT_SERVO,
        SERVO_PWM_OFF
    );                
};
