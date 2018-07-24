/*
 * Copyright (C) 2015-2017 Alibaba Group Holding Limited
 */

#include <stdio.h>
#include <aos/aos.h>
#include <km.h>
#include <prov_test_id2.h>

/*
 * used to save id2 prov data,  which is got from id2 prov sdk.
 */
uint8_t id2_prov_data[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x52, 0x65, 0x43, 0x6d,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x0e, 0x01, 0x07,
    0x18, 0x00, 0x00, 0x00, 0x30, 0x30, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46,
    0x46, 0x46, 0x46, 0x32, 0x30, 0x41, 0x31, 0x43, 0x39, 0x39, 0x30, 0x30, 0x52, 0x65, 0x43, 0x6d,
    0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00, 0xde, 0xc5, 0x92, 0xe1,
    0x10, 0x00, 0x00, 0x00, 0xc3, 0x26, 0x7c, 0x66, 0x3b, 0x8b, 0x15, 0x24, 0xec, 0x74, 0x22, 0xb0,
    0xb8, 0x53, 0xfd, 0x90, 0x52, 0x65, 0x43, 0x6d, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0xdd, 0xee, 0x0c, 0x20, 0x00, 0x00, 0x00, 0x4c, 0x3c, 0xa7, 0xcf,
    0x18, 0xa8, 0x55, 0xcb, 0x39, 0x1f, 0x16, 0x62, 0xcb, 0xde, 0x09, 0xc1, 0x91, 0xde, 0x24, 0xf5,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static void app_delayed_action(void *arg)
{
    int ret = 0;

    ret = prov_test_id2(id2_prov_data, sizeof(id2_prov_data));
    if (ret != 0) {
        LOG("id2 prov test failed\n");
        return;
    } else {
        LOG("id2 prov test success\n");
    }

    return;
}

int application_start(int argc, char *argv[])
{
    LOG("application started.");
    aos_post_delayed_action(1000, app_delayed_action, NULL);
    aos_loop_run();

    return 0;
}

