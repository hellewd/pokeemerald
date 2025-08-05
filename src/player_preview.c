#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "region_map.h"
#include "strings.h"
#include "malloc.h"
#include "sprite.h"
#include "decompress.h"
#include "constants/flags.h"

static const u16 sSamuelPal[] = INCBIN_U16("graphics/preview_player/samuel.gbapal");
static const u8 sSamuel[] = INCBIN_U8("graphics/preview_player/samuel.4bpp");

#define SAMUEL_TAG 1111

// general
static const struct OamData gSpriteOamData64x64 =
    {
        .y = 0,
        .affineMode = 0,
        .objMode = 0,
        .mosaic = 0,
        .bpp = 0,
        .shape = 0,
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(64x64),
        .tileNum = 0,
        .priority = 1,
        .paletteNum = 0,
        .affineParam = 0,
};

// samuel
static const struct SpriteSheet spriteSheetSamuel =
    {
        .data = sSamuel,
        .size = 2048, // TAMAÑO DEL GRÁFICO  (64*64)/2 (ancho*alto)/2
        .tag = SAMUEL_TAG,
};

static const struct SpritePalette spritePaletteSamuel =
    {
        .data = sSamuelPal,
        .tag = SAMUEL_TAG,
};

static void SpriteCallbackSamuel(struct Sprite *sprite)
{
    if (FlagGet(FLAG_SAMUEL_PREVIEW) == FALSE)
    {
        DestroySpriteAndFreeResources(sprite);
    }
}

static const struct SpriteTemplate spriteTemplateSamuel =
    {
        .tileTag = SAMUEL_TAG,
        .paletteTag = SAMUEL_TAG,
        .oam = &gSpriteOamData64x64,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackSamuel,
};

void LoadSamuelPreview()
{
    if (FlagGet(FLAG_SAMUEL_PREVIEW))
    {
        LoadSpriteSheet(&spriteSheetSamuel);
        LoadSpritePalette(&spritePaletteSamuel);
        CreateSprite(&spriteTemplateSamuel, 32, 140, 0);
    }
}
