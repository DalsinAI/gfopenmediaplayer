/* GFOpenPlay's unit-free media time conversions. MIT, 2026 AmiCradle Team. */
#include "op_media_control.h"

static uint32_t scale_ms(uint32_t units, uint32_t rate)
{
    uint64_t ms;
    if (!rate) return 0;
    ms = (uint64_t)units * 1000u / rate;
    return ms > UINT32_MAX ? UINT32_MAX : (uint32_t)ms;
}

uint32_t op_video_position_ms(uint32_t frame, uint32_t fps) { return scale_ms(frame, fps); }
uint32_t op_video_duration_ms(uint32_t frames, uint32_t fps) { return scale_ms(frames, fps); }
uint32_t op_sound_position_ms(uint32_t sample, uint32_t rate) { return scale_ms(sample, rate); }
uint32_t op_sound_duration_ms(uint32_t samples, uint32_t rate) { return scale_ms(samples, rate); }

uint32_t op_video_seek_frame(uint32_t position_ms, uint32_t frames, uint32_t fps)
{
    uint64_t at;
    if (!frames || !fps) return 0;
    at = (uint64_t)position_ms * fps / 1000u;
    return at >= frames ? frames - 1 : (uint32_t)at;
}
