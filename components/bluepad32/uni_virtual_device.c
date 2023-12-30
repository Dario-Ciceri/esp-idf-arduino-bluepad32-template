// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Ricardo Quesada
// http://retro.moe/unijoysticle2

#include "uni_virtual_device.h"

#include "uni_property.h"

#include "sdkconfig.h"

static bool virtual_device_enabled;

void uni_virtual_device_set_enabled(bool enabled) {
    uni_property_value_t val;

    if (enabled != virtual_device_enabled) {
        virtual_device_enabled = enabled;

        val.u8 = enabled;
        uni_property_set(UNI_PROPERTY_KEY_VIRTUAL_DEVICE_ENABLED, UNI_PROPERTY_TYPE_U8, val);
    }
}

bool uni_virtual_device_is_enabled(void) {
    return virtual_device_enabled;
}

void uni_virtual_device_init(void) {
    uni_property_value_t def;
    uni_property_value_t val;

#ifdef CONFIG_BLUEPAD32_ENABLE_VIRTUAL_DEVICE_BY_DEFAULT
    def.u8 = 1;
#else
    def.u8 = 0;
#endif  // CONFIG_BLUEPAD32_ENABLE_VIRTUAL_DEVICE_BY_DEFAULT
    val = uni_property_get(UNI_PROPERTY_KEY_VIRTUAL_DEVICE_ENABLED, UNI_PROPERTY_TYPE_U8, def);
    virtual_device_enabled = val.u8;
}