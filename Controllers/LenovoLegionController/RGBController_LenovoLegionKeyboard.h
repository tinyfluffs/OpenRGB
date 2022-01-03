/*-------------------------------------------------------------------*\
|  RGBController_LenovoLegionKeyboard.h                               |
|                                                                     |
|  Driver for Lenovo Legion laptop keyboards                          |
|                                                                     |
|  Ella Fox <tinyfluffs> 03/01/2021                                     |
|                                                                     |
\*-------------------------------------------------------------------*/
#pragma once

#include "RGBController.h"
#include "LenovoLegionKeyboardController.h"

class RGBController_LenovoLegionKeyboard : public RGBController {
public:
    RGBController_LenovoLegionKeyboard(LenovoLegionKeyboardController *controller_ptr);

    ~RGBController_LenovoLegionKeyboard();

    void SetupZones();

    void ResizeZone(int zone, int new_size);

    void DeviceUpdateLEDs();

    void UpdateZoneLEDs(int zone);

    void UpdateSingleLED(int led);

    void SetCustomMode();

    void DeviceUpdateMode();

private:
    LenovoLegionKeyboardController *controller;
};
