/**
i * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Output PWM signals on pins 0 and 1

#include "pico/stdlib.h"
#include "hardware/pwm.h"

int main() {
    /// \tag::setup_pwm[]

    // Tell GPIO 0 and 1 they are allocated to the PWM
    gpio_set_function(2, GPIO_FUNC_PWM);
    gpio_set_function(3, GPIO_FUNC_PWM);

    // Find out which PWM slice is connected to GPIO 0 (it's slice 0)
    uint slice_num = pwm_gpio_to_slice_num(3);

    // Set period
    pwm_set_wrap(slice_num, 24999);
    pwm_set_clkdiv(slice_num, 100.0);
    // Set channel A output high for one cycle before dropping
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 2315);
    // Set initial B output high for three cycles before dropping
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 1330);
    // Set the PWM running
    pwm_set_enabled(slice_num, true);
    /// \end::setup_pwm[]
    sleep_ms(2000);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 1330);
    sleep_ms(5000);
    while(true){
      pwm_set_chan_level(slice_num, PWM_CHAN_A, 1450);
      sleep_ms(2000);
      pwm_set_chan_level(slice_num, PWM_CHAN_A, 1330);
      sleep_ms(2000);
    }
    

    // Note we could also use pwm_set_gpio_level(gpio, x) which looks up the
    // correct slice and channel for a given GPIO.2450
}
