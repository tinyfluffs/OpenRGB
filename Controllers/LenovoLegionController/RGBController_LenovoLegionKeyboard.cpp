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

RGBController_LenovoLegionKeyboard::RGBController_LenovoLegionKeyboard(LenovoLegionKeyboardController *controller_ptr) {
    controller  = controller_ptr;

    name        = "Lenovo Legion Keyboard";
    vendor      = "Lenovo";
    type        = DEVICE_TYPE_KEYBOARD;
    description = "Lenovo Legion Keyboard";
    location    = controller->GetLocation();
    serial      = controller->GetSerial();

    mode Direct;
    Direct.name       = "Direct";
    Direct.flags      = MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    Direct.color_mode = MODE_COLORS_MODE_SPECIFIC;
    modes.push_back(Direct);

    SetupZones();
}

RGBController_LenovoLegionKeyboard::~RGBController_LenovoLegionKeyboard() {
	delete controller;
}

void RGBController_LenovoLegionKeyboard::SetupZones() {
}

void RGBController_LenovoLegionKeyboard::ResizeZone(int zone, int new_size) {
}

void RGBController_LenovoLegionKeyboard::DeviceUpdateLEDs() {
}

void RGBController_LenovoLegionKeyboard::UpdateZoneLEDs(int zone) {
}

void RGBController_LenovoLegionKeyboard::UpdateSingleLED(int led) {
}

void RGBController_LenovoLegionKeyboard::SetCustomMode() {
}

void RGBController_LenovoLegionKeyboard::DeviceUpdateMode() {
}
