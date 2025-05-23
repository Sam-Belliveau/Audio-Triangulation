#pragma once

#include <components/constants.h>
#include <components/buffer.h>

#include <stdbool.h>

#define BUFFER_HALF (BUFFER_SIZE >> 1)
#define BUFFER_HALF_SIZE_BITS (BUFFER_SIZE_BITS - 1)

#define SAMPLE_POWER(sample) ((int64_t)(sample) * (sample))

struct rolling_buffer_t
{
    int head;
    
    power_t incoming_power;
    power_t incoming_total;
    
    power_t outgoing_power;
    power_t outgoing_total;

    bool is_full;
    sample_t buffer[BUFFER_SIZE];
};

void rolling_buffer_init(struct rolling_buffer_t *buf);
void rolling_buffer_push(struct rolling_buffer_t *buf, sample_t sample);
void rolling_buffer_write_out(const struct rolling_buffer_t *buf, struct buffer_t *dst);

power_t rolling_buffer_get_incoming_power(const struct rolling_buffer_t *buf);
power_t rolling_buffer_get_outgoing_power(const struct rolling_buffer_t *buf);
