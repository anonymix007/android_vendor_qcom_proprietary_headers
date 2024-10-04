#ifndef __VUI_DMGR_AUDIO_INTF__
#define __VUI_DMGR_AUDIO_INTF__

#include <PalDefs.h>

#include <stdint.h>

typedef int32_t (*voiceuiDmgrCallback)(int32_t, void *, size_t);

typedef int (*vui_dmgr_init_t)(voiceuiDmgrCallback);
typedef void (*vui_dmgr_deinit_t)(void);

typedef struct {
    uint32_t data1;
    uint16_t data2;
    uint16_t data3;
    uint16_t data4;
    uint8_t data5[6];
} vui_dmgr_uuid_t;

typedef struct {
    pal_stream_type_t stream_type;
    vui_dmgr_uuid_t vendor_uuid;
} vui_dmgr_usecases_t;

typedef struct {
    int num_usecases;
    vui_dmgr_usecases_t usecases[64];
} vui_dmgr_param_restart_usecases_t;

static_assert(sizeof(vui_dmgr_param_restart_usecases_t) == 1284);

enum {
    VUI_DMGR_PARAM_ID_RESTART_USECASES = 0,
};

#endif /* __VUI_DMGR_AUDIO_INTF__ */
