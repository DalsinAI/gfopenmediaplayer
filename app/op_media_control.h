/* GFOpenPlay's unit-free media time conversions. MIT, 2026 AmiCradle Team. */
#ifndef OP_MEDIA_CONTROL_H
#define OP_MEDIA_CONTROL_H

#include <stdint.h>

uint32_t op_video_position_ms(uint32_t frame, uint32_t fps);
uint32_t op_video_duration_ms(uint32_t frames, uint32_t fps);
uint32_t op_sound_position_ms(uint32_t sample, uint32_t rate);
uint32_t op_sound_duration_ms(uint32_t samples, uint32_t rate);
uint32_t op_video_seek_frame(uint32_t position_ms, uint32_t frames, uint32_t fps);

#endif
