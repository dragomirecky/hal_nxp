/*
 * Copyright 2023-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include <stdint.h>

#if defined(CONFIG_NXP_MONOLITHIC_NBU)
__attribute__ ((__section__(".fw_cpu2"), used))
const uint8_t fw_cpu2[] = {
    #include <rw61x_cpu2_fw.bin.inc>
};

/*
 * The NXP connectivity framework (fwk_platform_coex.c) references
 * fw_cpu2_ble / fw_cpu2_combo when gPlatformMonolithicApp_d == 1.
 * Provide aliases so the framework finds the monolithic blob that
 * Zephyr already linked above.
 */
extern const uint32_t fw_cpu2_ble[]  __attribute__((alias("fw_cpu2")));
extern const uint32_t fw_cpu2_combo[] __attribute__((alias("fw_cpu2")));
#endif