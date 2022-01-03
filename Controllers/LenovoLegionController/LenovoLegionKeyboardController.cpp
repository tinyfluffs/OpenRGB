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
}

std::string LenovoLegionKeyboardController::GetSerial() {
}

std::string LenovoLegionKeyboardController::GetLocation() {
}
