// 利用双向拨动开关实现的旋转编码器驱动示例
//

#include "Arduino.h"
#include "bidi_switch_knob.h"

#define ROTARY_ENC_PIN_A 8
#define ROTARY_ENC_PIN_B 7

static knob_handle_t s_knob = 0;

static void _knob_right_cb(void *arg, void *data)
{
    Serial.printf("KONB: KONB_RIGHT,count_value:%d\n", iot_knob_get_count_value(s_knob));
}

static void _knob_left_cb(void *arg, void *data)
{
    Serial.printf("KONB: KONB_LEFT,count_value:%d\n", iot_knob_get_count_value(s_knob));
}

int rotary_read(void)
{
    if (NULL == s_knob)
        return 0;
    else
        return iot_knob_get_count_value(s_knob);
}

void clear_rotary_count(void)
{
    if (NULL != s_knob)
        iot_knob_clear_count_value(s_knob);
}

void rotary_init(void)
{
    knob_config_t cfg = {
        .gpio_encoder_a = ROTARY_ENC_PIN_A,
        .gpio_encoder_b = ROTARY_ENC_PIN_B};
    s_knob = iot_knob_create(&cfg);
    if (NULL == s_knob)
    {
        Serial.printf("knob create failed\n");
        return;
    }

    iot_knob_register_cb(s_knob, KNOB_LEFT, _knob_left_cb, NULL);
    iot_knob_register_cb(s_knob, KNOB_RIGHT, _knob_right_cb, NULL);
}

void setup()
{
    Serial.begin(115200);

    rotary_init();
}

void loop()
{
    vTaskDelay(1000);
}
