/* The parts of akikoplus.device GFOpenPlay uses for films (0.2.0): ACMedia, the host decoding the film
 * (VA-API on the x86 appliance's Radeon, the CPU or the Pi 5's HEVC block on the Pis) and the picture
 * on acscreen's overlay plane, or, where there is no plane, frames GFOpenPlay pulls at its window's size
 * and draws. The same layouts and numbers as amicradle's machines/devices/cards/akikoplus/guest/include/
 * devices/akikoplus.h and its hostlib/acmedia/acmedia.h (ACM_INFO's head).
 * MIT, Copyright (c) 2026 AmiCradle Team. */
#ifndef OP_ACMEDIA_H
#define OP_ACMEDIA_H

#include <exec/types.h>
#include <exec/io.h>
#include <utility/tagitem.h>

#define OP_AKIKOPLUS_NAME "akikoplus.device"

struct OpAkikoMedia {
    struct IOStdReq iam_Req;
    ULONG iam_Session;
    struct TagItem *iam_Tags;
    LONG  iam_Result;
    LONG  iam_Pts;
    UBYTE iam_Reserved[4];
    LONG  iam_Fault;
};

#define APMCMD_OPEN       (CMD_NONSTD + 2)
#define APMCMD_SEEK       (CMD_NONSTD + 3)
#define APMCMD_CONTROL    (CMD_NONSTD + 4)
#define APMCMD_INFO       (CMD_NONSTD + 5)
#define APMCMD_FRAME      (CMD_NONSTD + 9)
#define APMSF_EXACT 0x10
#define APMCTL_SETRECT   8

#define APMA_Dummy        (TAG_USER + 0x41500000)
#define APMA_Name         (APMA_Dummy + 1)
#define APMA_Left         (APMA_Dummy + 5)
#define APMA_Top          (APMA_Dummy + 6)
#define APMA_Width        (APMA_Dummy + 7)
#define APMA_Height       (APMA_Dummy + 8)
#define APMA_ControlA     (APMA_Dummy + 14)
#define APMA_ControlB     (APMA_Dummy + 15)
#define APMA_ControlC     (APMA_Dummy + 16)
#define APMA_ControlD     (APMA_Dummy + 17)
#define APMA_FrameFormat  (APMA_Dummy + 18)
#define APMA_FramePitch   (APMA_Dummy + 19)
#define APMPIX_ARGB32 3

#define APMERR_NOTAVAIL 1
#define APMERR_AGAIN    12

/* APMCMD_INFO's block: 12 longs, then 12 a stream */
#define OPA_INFO_HEAD   12
#define OPA_IH_DURATION 2
#define OPA_IH_STATE    3
#define OPA_IH_POSITION 4
#define OPA_IH_VIDEO    5
#define OPA_IH_AUDIO    6
#define OPA_IH_VPATH    7
#define OPA_IH_VROUTE   8
#define OPA_IH_SIZE     10
#define OPA_STREAM      12
#define OPA_ST_RATE     8               /* a sound stream's samples a second */
#define OPA_STATE_ENDED 4
#define OPA_STATE_ERROR 5
#define OPA_ROUTE_PLANE 1
#define OPA_PATH_VAAPI  3

#endif
