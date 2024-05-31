/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

import QtQuick          2.11
import QtQuick.Layouts  1.11

import QGroundControl                       1.0
import QGroundControl.Controls              1.0
import QGroundControl.MultiVehicleManager   1.0
import QGroundControl.ScreenTools           1.0
import QGroundControl.Palette               1.0

// Joystick Indicator
Item {
    id:             _root
    width:          nightLightRow.width * 1.1
    anchors.top:    parent.top
    anchors.bottom: parent.bottom

    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle

    property bool showIndicator:    true
    property bool nightLightState: _activeVehicle.nightLightState


    Row {
        id:             nightLightRow
        anchors.top:    parent.top
        anchors.bottom: parent.bottom
        spacing:        ScreenTools.defaultFontPixelWidth

        QGCColoredImage {
            width:              height
            anchors.top:        parent.top
            anchors.bottom:     parent.bottom
            sourceSize.height:  height
            source:             "/qmlimages/NightLight.png"
            fillMode:           Image.PreserveAspectFit
            color: {
                if (nightLightState) {
                    return "yellow"
                }

                return qgcPal.buttonText
            }
        }
    }

    MouseArea {
        anchors.fill:   parent
        onClicked: {
            globals.guidedControllerFlyView.executeAction(
                globals.guidedControllerFlyView.nightLightToggle,
                null,
                null,
                null
            )
        }
    }
}