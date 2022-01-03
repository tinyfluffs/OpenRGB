/*-------------------------------------------------------------------*\
|  LenovoLegionKeyboardController.h                                   |
|                                                                     |
|  Driver for Lenovo Legion laptop keyboards                          |
|                                                                     |
|  Ella Fox <tinyfluffs> 03/01/2021                                     |
|                                                                     |
\*-------------------------------------------------------------------*/

#pragma once

#include "RGBController.h"

#include <string>
#include <hidapi/hidapi.h>

class LenovoLegionKeyboardController
{
public:
	LenovoLegionKeyboardController(hid_device* dev_handle, char *path);
    ~LenovoLegionKeyboardController();

    std::string     GetSerial();
    std::string     GetLocation();

private:
    std::string     location;
    hid_device*     dev;
};
