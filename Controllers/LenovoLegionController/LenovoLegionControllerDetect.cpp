/*-------------------------------------------------------------------*\
|  LenovoLegionControllerDetect.h                                     |
|                                                                     |
|  Driver for Lenovo Legion laptops                                   |
|                                                                     |
|  Ella Fox <tinyfluffs> 03/01/2021                                     |
|                                                                     |
\*-------------------------------------------------------------------*/
#include <hidapi/hidapi.h>
#include "Detector.h"
#include "RGBController.h"

#include "RGBController_LenovoLegionKeyboard.h"
#include <vector>
#include <libusb-1.0/libusb.h>

#define LENOVO_LEGION_KBD_VID 0x048D
#define LENOVO_LEGION_GEN5_KBD_PID 0xC955
#define LENOVO_LEGION_GEN6_KBD_PID 0xC965

void DetectLenovoLegionKeyboardControllers(hid_device_info *info, const std::string &name) {
    hid_device *dev = hid_open_path(info->path);

    if (dev) {
        LenovoLegionKeyboardController *controller = new LenovoLegionKeyboardController(dev, info->path);
        RGBController_LenovoLegionKeyboard *rgb_controller = new RGBController_LenovoLegionKeyboard(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

REGISTER_HID_DETECTOR_I("Lenovo Legion Keyboard", DetectLenovoLegionKeyboardControllers, LENOVO_LEGION_KBD_VID, LENOVO_LEGION_GEN5_KBD_PID, 1);
REGISTER_HID_DETECTOR_I("Lenovo Legion Keyboard", DetectLenovoLegionKeyboardControllers, LENOVO_LEGION_KBD_VID, LENOVO_LEGION_GEN6_KBD_PID, 1);
