#include <stdint.h>
#include <stdio.h>
#include "../app/op_media_control.h"

static int cases, fails;
#define CHECK(x) do { cases++; if (!(x)) { fails++; printf("FAIL line %d: %s\n", __LINE__, #x); } } while (0)

int main(void)
{
    CHECK(op_video_position_ms(75, 25) == 3000);
    CHECK(op_video_duration_ms(250, 25) == 10000);
    CHECK(op_video_position_ms(1, 0) == 0);
    CHECK(op_sound_position_ms(48000, 48000) == 1000);
    CHECK(op_sound_duration_ms(441000, 44100) == 10000);
    CHECK(op_sound_duration_ms(UINT32_MAX, 1) == UINT32_MAX);
    CHECK(op_video_seek_frame(0, 250, 25) == 0);
    CHECK(op_video_seek_frame(3999, 250, 25) == 99);
    CHECK(op_video_seek_frame(10000, 250, 25) == 249);
    CHECK(op_video_seek_frame(UINT32_MAX, UINT32_MAX, UINT32_MAX) == UINT32_MAX - 1);
    CHECK(op_video_seek_frame(1000, 0, 25) == 0);
    CHECK(op_video_seek_frame(1000, 25, 0) == 0);
    printf("%d/%d media-control cases pass\n", cases - fails, cases);
    return fails != 0;
}
