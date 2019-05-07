/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <assert.h>
#include <stddef.h>
#include <inttypes.h>
#include "os/mynewt.h"

#include <hal/hal_bsp.h>
#include <hal/hal_system.h>
#include <hal/hal_flash.h>
#include <console/console.h>

#define BOOT_AREA_DESC_MAX  (256)
#define AREA_DESC_MAX       (BOOT_AREA_DESC_MAX)

//  First word contains initial MSP value
//  Second word contains address of entry point (Reset_Handler)
static uint32_t img_start[2] = {
    0x20005000,           //  _estack = (ORIGIN (RAM) + LENGTH (RAM))
    0x8000000 +  0x412c,  //  TODO
};

int
main(void)
{
    //  This is a stub bootloader for Blue Pill.  We jump straight into the application.
    //  This simple bootloader allows the application to take up more ROM space.
    hal_bsp_init();

    //  Previously: flash_map_init();
    //  Previously: rc = boot_go(&rsp);

    //  First word contains initial MSP value
    //  Second word contains address of entry point (Reset_Handler)
    hal_system_start((void *) img_start);

    return 0;
}
