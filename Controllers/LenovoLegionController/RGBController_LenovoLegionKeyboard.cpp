/*-------------------------------------------------------------------*\
|  RGBController_LenovoLegionKeyboard.cpp                             |
|                                                                     |
|  Driver for Lenovo Legion laptop keyboards                          |
|                                                                     |
|  Ella Fox <tinyfluffs> 03/01/2021                                     |
|                                                                     |
\*-------------------------------------------------------------------*/
#include "RGBController_LenovoLegionKeyboard.h"
#include "LenovoLegionKeyboardController.h"
#include "LogManager.h"

RGBController_LenovoLegionKeyboard::RGBController_LenovoLegionKeyboard(LenovoLegionKeyboardController *controller_ptr) {
    controller = controller_ptr;

    vendor = "Lenovo";
    version = "Gen5/Gen6";
    type = DEVICE_TYPE_KEYBOARD;
    description = "Lenovo Legion Keyboard Backlight";
    location = controller->GetLocation();
    serial = controller->GetSerial();

    mode Direct;
    Direct.name = "Direct";
    Direct.flags = MODE_FLAG_HAS_BRIGHTNESS;
    Direct.color_mode = MODE_COLORS_MODE_SPECIFIC;
    Direct.colors_min = 1;
    Direct.colors_max = 1;
    Direct.colors.resize(1);
    modes.push_back(Direct);

    SetupZones();
}

RGBController_LenovoLegionKeyboard::~RGBController_LenovoLegionKeyboard() {
    delete controller;
}

void RGBController_LenovoLegionKeyboard::SetupZones() {
    zone new_zone;
    new_zone.name = "1";
    new_zone.type = ZONE_TYPE_LINEAR;
    new_zone.leds_min = 1;
    new_zone.leds_count = 1;
    zones.push_back(new_zone);
}

void RGBController_LenovoLegionKeyboard::ResizeZone(int zone, int new_size) {
    /*---------------------------------------------------------*\
    | This device does not support resizing zones               |
    \*---------------------------------------------------------*/
}

void RGBController_LenovoLegionKeyboard::DeviceUpdateLEDs() {
    LOG_DEBUG("DeviceUpdateLEDs");
}

void RGBController_LenovoLegionKeyboard::UpdateZoneLEDs(int zone) {
    LOG_DEBUG("UpdateZoneLEDs");
}

void RGBController_LenovoLegionKeyboard::UpdateSingleLED(int led) {
    LOG_DEBUG("UpdateSingleLED");
}

void RGBController_LenovoLegionKeyboard::SetCustomMode() {
    active_mode = 0;
    LOG_DEBUG("SetCustomMode");
}

void RGBController_LenovoLegionKeyboard::DeviceUpdateMode() {
}
