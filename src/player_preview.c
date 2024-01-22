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
#include "sprite.h"
#include "strings.h"
#include "script.h"
#include "malloc.h"
#include "sprite.h"
#include "decompress.h"
#include "constants/flags.h"

static const u16 sSamuelPal[] = INCBIN_U16("graphics/preview_player/samuel.gbapal");
static const u8 sSamuel[] = INCBIN_U8("graphics/preview_player/samuel.4bpp");

static const u16 sRowanPal[] = INCBIN_U16("graphics/preview_player/rowan.gbapal");
static const u8 sRowan[] = INCBIN_U8("graphics/preview_player/rowan.4bpp");

static const u16 sSophiaPal[] = INCBIN_U16("graphics/preview_player/sophia.gbapal");
static const u8 sSophia[] = INCBIN_U8("graphics/preview_player/sophia.4bpp");

#define SAMUEL_TAG 1111
#define ROWAN_TAG 1112
#define SOPHIA_TAG 1113

//general
static const struct OamData gSpriteOamData32x32 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0, 
    .mosaic = 0, 
    .bpp = 0,
    .shape = 0, 
    .x = 0, 
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1, 
    .paletteNum = 0, 
    .affineParam = 0, 
};

//samuel
static const struct SpriteSheet spriteSheetSamuel =
{
    .data = sSamuel,
    .size = 512, //TAMAÑO DEL GRÁFICO  (32*32)/2 (ancho*alto)/2
    .tag = SAMUEL_TAG, 
};

static const struct SpritePalette spritePaletteSamuel =
{
    .data = sSamuelPal,
    .tag = SAMUEL_TAG,
};

static void SpriteCallbackSamuel(struct Sprite *sprite){
    if(FlagGet(FLAG_SAMUEL_PREVIEW) == FALSE){
        DestroySpriteAndFreeResources(sprite);
    }
}

static const struct SpriteTemplate spriteTemplateSamuel =
{
    .tileTag = SAMUEL_TAG, 
    .paletteTag = SAMUEL_TAG, 
    .oam = &gSpriteOamData32x32,
    .anims = gDummySpriteAnimTable, 
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackSamuel, 
};

void LoadSamuelPreview()
{
    if(FlagGet(FLAG_SAMUEL_PREVIEW))
    {
    LoadSpriteSheet(&spriteSheetSamuel);
    LoadSpritePalette(&spritePaletteSamuel);
    CreateSprite(&spriteTemplateSamuel, 16,144, 0);
    }
}

//Rowan
static const struct SpriteSheet spriteSheetRowan =
{
    .data = sRowan,
    .size = 512, //TAMAÑO DEL GRÁFICO  (32*32)/2 (ancho*alto)/2
    .tag = ROWAN_TAG, 
};

static const struct SpritePalette spritePaletteRowan =
{
    .data = sRowanPal,
    .tag = ROWAN_TAG,
};

static void SpriteCallbackRowan(struct Sprite *sprite){
    if(FlagGet(FLAG_ROWAN_PREVIEW) == FALSE){
        DestroySpriteAndFreeResources(sprite);
    }
}

static const struct SpriteTemplate spriteTemplateRowan =
{
    .tileTag = ROWAN_TAG, 
    .paletteTag = ROWAN_TAG, 
    .oam = &gSpriteOamData32x32,
    .anims = gDummySpriteAnimTable, 
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackRowan, 
};

void LoadRowanPreview()
{
    if(FlagGet(FLAG_ROWAN_PREVIEW))
    {
    LoadSpriteSheet(&spriteSheetRowan);
    LoadSpritePalette(&spritePaletteRowan);
    CreateSprite(&spriteTemplateRowan, 16,144, 0);
    }
}

//sophia
static const struct SpriteSheet spriteSheetSophia =
{
    .data = sSophia,
    .size = 512, //TAMAÑO DEL GRÁFICO  (32*32)/2 (ancho*alto)/2
    .tag = SOPHIA_TAG, 
};

static const struct SpritePalette spritePaletteSophia =
{
    .data = sSophiaPal,
    .tag = SOPHIA_TAG,
};

static void SpriteCallbackSophia(struct Sprite *sprite){
    if(FlagGet(FLAG_SOPHIA_PREVIEW) == FALSE){
        DestroySpriteAndFreeResources(sprite);
    }
}

static const struct SpriteTemplate spriteTemplateSophia =
{
    .tileTag = SOPHIA_TAG, 
    .paletteTag = SOPHIA_TAG, 
    .oam = &gSpriteOamData32x32,
    .anims = gDummySpriteAnimTable, 
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackSophia, 
};

void LoadSophiaPreview()
{
    if(FlagGet(FLAG_SOPHIA_PREVIEW))
    {
    LoadSpriteSheet(&spriteSheetSophia);
    LoadSpritePalette(&spritePaletteSophia);
    CreateSprite(&spriteTemplateSophia, 16,144, 0);
    }
}
