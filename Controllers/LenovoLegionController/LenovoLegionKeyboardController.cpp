/*-------------------------------------------------------------------*\
|  LenovoLegionKeyboardController.cpp                                 |
|                                                                     |
|  Driver for Lenovo Legion laptop keyboards                          |
|                                                                     |
|  Ella Fox <tinyfluffs> 03/01/2021                                     |
|                                                                     |
\*-------------------------------------------------------------------*/


#include "LenovoLegionKeyboardController.h"

LenovoLegionKeyboardController::LenovoLegionKeyboardController(hid_device *dev_handle, char *path) {
    dev         = dev_handle;
    location    = path;
}

LenovoLegionKeyboardController::~LenovoLegionKeyboardController() {
	hid_close(dev);
}

std::string LenovoLegionKeyboardController::GetSerial() {
    wchar_t serial_string[128];
    int ret = hid_get_serial_number_string(dev, serial_string, 128);

    if(ret != 0)
    {
        return("");
    }

    std::wstring return_wstring = serial_string;
    std::string return_string(return_wstring.begin(), return_wstring.end());

    return(return_string);
}

std::string LenovoLegionKeyboardController::GetLocation() {
	return("HID: " + location);
}
