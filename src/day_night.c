#include "global.h"
#include "main.h"
#include "day_night.h"
#include "palette.h"
#include "start_menu.h"
#include "overworld.h"
#include "battle_main.h"
#include "rtc.h"
#include "constants/map_types.h"
#include "constants/rgb.h"

/* Timelapses */
enum
{
    TIME_MIDNIGHT,
    TIME_DAWN,
    TIME_DAY,
    TIME_SUNSET,
    TIME_NIGHTFALL,
    TIME_NIGHT
};

/* End hours for each of the timelapses */
#define MIDNIGHT_END_HOUR   7       //00 - 07
#define DAWN_END_HOUR       8       //07 - 08
#define DAY_END_HOUR        19      //08 - 19
#define SUNSET_END_HOUR     20      //19 - 20
#define NIGHTFALL_END_HOUR  21      //20 - 21
#define NIGHT_END_HOUR      0       //21 - 00

/* Start and end hour of the lightning system.
 * This system is generally used for building's windows. */
#define LIGHTNING_START_HOUR    NIGHTFALL_END_HOUR
#define LIGHTNING_END_HOUR      MIDNIGHT_END_HOUR

/* This array contains the colors used for the windows or
 * other tiles that have to be illuminated at night.
 * You can add or remove light slots as you whish, each entry
 * requires the paletteNum and the colourNum of each color slot,
 * as well as the RGB 15 bit color that's gonna be used as
 * "light color".
 */

// TODO: Make this dynamic per map
const struct LightingColor gLightingColors[] =
{
    // General
    {
        .paletteNum = 1,
        .colorNum = 10,
        .lightColor = RGB2(26, 25, 18),
    },
    // // Littleroot
    // { 
    //     .paletteNum = 6,
    //     .colorNum = 10,
    //     .lightColor = RGB2(25, 25, 19),
    // },
    // {
    //     .paletteNum = 6,
    //     .colorNum = 9,
    //     .lightColor = RGB2(24, 24, 16),
    // },
    // {
    //     .paletteNum = 8,
    //     .colorNum = 10,
    //     .lightColor = RGB2(25, 25, 19),
    // },
    // {
    //     .paletteNum = 8,
    //     .colorNum = 9,
    //     .lightColor = RGB2(24, 24, 16),
    // },
};

/* Maptypes that are not affected by DayNight */
const u8 gDayNightMapExceptions[] =
{
    MAP_TYPE_NONE,
    MAP_TYPE_INDOOR,
    MAP_TYPE_UNDERGROUND,
    MAP_TYPE_SECRET_BASE,
};

/* Configure each palette slot to be affected or not by DayNight *
 * while you are in the overworld.                          */
const struct DayNightPalExceptions gOWPalExceptions = 
{
    .pal = {
        DNS_PAL_ACTIVE,     //0
        DNS_PAL_ACTIVE,     //1
        DNS_PAL_ACTIVE,     //2
        DNS_PAL_ACTIVE,     //3
        DNS_PAL_ACTIVE,     //4
        DNS_PAL_ACTIVE,     //5
        DNS_PAL_ACTIVE,     //6
        DNS_PAL_ACTIVE,     //7
        DNS_PAL_ACTIVE,     //8
        DNS_PAL_ACTIVE,     //9
        DNS_PAL_ACTIVE,     //10
        DNS_PAL_ACTIVE,     //11
        DNS_PAL_ACTIVE,     //12
        DNS_PAL_EXCEPTION,  //13
        DNS_PAL_EXCEPTION,  //14
        DNS_PAL_EXCEPTION,  //15
        DNS_PAL_ACTIVE,     //16
        DNS_PAL_ACTIVE,     //17
        DNS_PAL_ACTIVE,     //18
        DNS_PAL_ACTIVE,     //19
        DNS_PAL_ACTIVE,     //20
        DNS_PAL_ACTIVE,     //21
        DNS_PAL_ACTIVE,     //22
        DNS_PAL_ACTIVE,     //23
        DNS_PAL_ACTIVE,     //24
        DNS_PAL_ACTIVE,     //25
        DNS_PAL_ACTIVE,     //26
        DNS_PAL_ACTIVE,     //27
        DNS_PAL_ACTIVE,     //28
        DNS_PAL_ACTIVE,     //29
        DNS_PAL_ACTIVE,     //30
        DNS_PAL_ACTIVE,     //31
    }
};

/* Configure each palette slot to be affected or not by DayNight *
 * while in combat.                                         */
const struct DayNightPalExceptions gCombatPalExceptions =  
{
    .pal = {
        DNS_PAL_EXCEPTION,  //0
        DNS_PAL_EXCEPTION,  //1
        DNS_PAL_ACTIVE,     //2
        DNS_PAL_ACTIVE,     //3
        DNS_PAL_ACTIVE,     //4
        DNS_PAL_EXCEPTION,  //5
        DNS_PAL_ACTIVE,     //6
        DNS_PAL_ACTIVE,     //7
        DNS_PAL_ACTIVE,     //8
        DNS_PAL_ACTIVE,     //9
        DNS_PAL_ACTIVE,     //10
        DNS_PAL_ACTIVE,     //11
        DNS_PAL_ACTIVE,     //12
        DNS_PAL_ACTIVE,     //13
        DNS_PAL_ACTIVE,     //14
        DNS_PAL_ACTIVE,     //15
        DNS_PAL_EXCEPTION,  //16
        DNS_PAL_EXCEPTION,  //17
        DNS_PAL_EXCEPTION,  //18
        DNS_PAL_EXCEPTION,  //19
        DNS_PAL_EXCEPTION,  //20
        DNS_PAL_EXCEPTION,  //21
        DNS_PAL_EXCEPTION,  //22
        DNS_PAL_EXCEPTION,  //23
        DNS_PAL_EXCEPTION,  //24
        DNS_PAL_EXCEPTION,  //25
        DNS_PAL_EXCEPTION,  //26
        DNS_PAL_EXCEPTION,  //27
        DNS_PAL_EXCEPTION,  //28
        DNS_PAL_EXCEPTION,  //29
        DNS_PAL_EXCEPTION,  //30
        DNS_PAL_EXCEPTION,  //31
    }
};
  /*******************************************************/
 /*************    DNS Colour Filters     ***************/
/*******************************************************/
/* DNS filters are actual 15bit RGB colours.            *
 * This colours R - G - B channels are substracted from *
 * the original colour in the palette buffer during the *
 * transfer from the buffer to the palette RAM.         *
 *                                                      *
 *  [BUFFER] -> (Value - Filter) -> [PAL_RAM]           *
 *                                                      *
 * This means that you shouln't use too high values for *
 * RGB channels in the filters. Otherwie, the channels  *
 * will easily reach 0, giving you plain colours.       *
 * I Suggest to not use channels with a value above 16. *
 *                                                      *
 * Feel free to experiment with your own filters.       *
 * ******************************************************
 * DNS Alternative Filtering System                     *
 * I've created and alternative filtering system, which *
 * substracts the level of each channel porportionally. *
 * I personally prefer this alternative method, since   *
 * the filters are blended "softer".                    *
 * This is more noticeable with the darker filters.     *
 */

// MIDNIGHT - From 00:00 to 07:00 the last filter is used.
const u16 gMidnightFilter = RGB2(15, 15, 8);

// DAWN - From 07:00 to 08:00 filters
const u16 gDawnFilter = RGB2(2, 2, 9);

// DAY - 8:00 to 19:00
const u16 gDayFilter = RGB2(0, 0, 0);   //0000

//SUNSET - From 19:00 to 20:00
const u16 gSunsetFilter = RGB2(0, 5, 10);

// NIGHTFALL -  From 20:00 to 21:00
const u16 gNightfallFilter = RGB2(2, 14, 3);

// Filter used at night. From 21:00 to 24:00
const u16 gNightFilter = RGB2(14, 14, 6);   //19CE

/*************   SpritePalette Dns exceptions by TAG   **************
 * If you are using any dynamic sprite palette allocation system,   *
 * you will most likely want to use this system to avoid certain    *
 * palette tags to be "banned" from dns, as the palettes may get    *
 * loaded in different slots each time.                             */
const u16 gPaletteTagExceptions[] =
{
    0xD6FF, //TAG_HEALTHBOX_PAL
    0xD704, //TAG_HEALTHBAR_PAL
    0xD710, //TAG_STATUS_SUMMARY_BAR_PAL
    0xD712, //TAG_STATUS_SUMMARY_BALLS_PAL
};


//Functions
static u16 DayNightApplyFilterToColor(u16 color, u16 filter);
static u16 DayNightApplyProportionalFilterToColor(u16 color, u16 filter);
static void DoDayNightLightning();
static u16 GetDayNightFilter();
static bool8 IsMapDayNightException();
static bool8 IsSpritePaletteTagDayNightException(u8 palNum);
static bool8 IsOverworld();
static bool8 IsCombat();
static bool8 IsLightActive();

//DayNight palette buffer in EWRAM
ALIGNED(4) EWRAM_DATA static u16 sDayNightPaletteDmaBuffer[512] = {0};

//Called from TransferPlttBuffer
void DayNightTransferPlttBuffer(void *src, void *dest)
{
    if ((IsOverworld() || IsCombat()) && !IsMapDayNightException()) 
    {
        DmaCopy16(3, sDayNightPaletteDmaBuffer, dest, PLTT_SIZE);
    }
    else
    {
        DmaCopy16(3, src, dest, PLTT_SIZE);
    }
}

/* Applies filter to palette colors, stores new palettes in EWRAM buffer.   *
 * It must be called from CB2 if the DNS wants to be used (similar to        *
 * TransferPlttBuffer)  in VBlank callbacks                                  */
void DayNightApplyFilters()
{
    u8 palNum, colNum;
    u16 color, rgbFilter;
    struct DayNightPalExceptions palExceptionFlags;

    rgbFilter = GetDayNightFilter();

    palExceptionFlags = gMain.inBattle ? gCombatPalExceptions : gOWPalExceptions;   //Init pal exception slots

    for (palNum = 0; palNum < 32; palNum++)
        if (palExceptionFlags.pal[palNum] && (palNum < 15 || !IsSpritePaletteTagDayNightException(palNum - 16)))
            for (colNum = 0; colNum < 16; colNum++) //Transfer filtered palette to buffer
                sDayNightPaletteDmaBuffer[palNum * 16 + colNum] = DayNightApplyProportionalFilterToColor(gPlttBufferFaded[palNum * 16 + colNum], rgbFilter);
        else
            for (colNum = 0; colNum < 16; colNum++)  //Transfers palette to buffer without filtering
                sDayNightPaletteDmaBuffer[palNum * 16 + colNum] = gPlttBufferFaded[palNum * 16 + colNum];      

    if (!IsMapDayNightException() && IsLightActive() && !gMain.inBattle)
        DoDayNightLightning();
}

u8 GetTimeOfDay()
{
  u8 hour = gLocalTime.hours;

  if (hour > MIDNIGHT_END_HOUR && hour <= SUNSET_END_HOUR)
    return TIME_OF_DAY_DAY;

  return TIME_OF_DAY_NIGHT;
}

//Applies filter to a color. Filters RGB channels are substracted from color RGB channels.
//Based on Andrea's DNS filtering system 
static u16 DayNightApplyFilterToColor(u16 color, u16 filter)
{
    u16 red, green, blue;

    red = (color & 0x1F) - (filter & 0x1F);
    green = ((color & 0x3E0) - (filter & 0x3E0)) >> 5;
    blue = ((color & 0x7C00) - (filter & 0x7C00)) >> 10;

    return RGB2(red <= 31 ? red : 0, green <= 31 ? green : 0, blue <= 31 ? blue : 0);
}

/*Alternative way to apply filter. Works similar to the first one, but colors are substracted PROPORTIONALLY.
This system is great if you want to avoid colors with low rgb channels getting donw to 0 too fast.
That's something that can easily happen with above Andrea's filtering system.*/
static u16 DayNightApplyProportionalFilterToColor(u16 color, u16 filter)
{
    u32 red, green, blue;

    red = (color & 0x1F) * (0x1F - (filter & 0x1F)) >> 5;
    green = ((color & 0x3E0) >> 5) * ((0x3E0 - (filter & 0x3E0)) >> 5) >> 5;
    blue = ((color & 0x7C00) >> 10) * ((0x7C00 - (filter & 0x7C00)) >> 10) >> 5;

    return RGB2(red <= 31 ? red : 0, green <= 31 ? green : 0, blue <= 31 ? blue : 0);  
}

//returns the filter to use depending on RTC time.
static u16 GetDayNightFilter()
{
    u8 hour = gLocalTime.hours;    
    u8 minutes = gLocalTime.minutes;   

    switch(GetDayNightTimeLapse(hour))
    {
        case TIME_MIDNIGHT:
          return gMidnightFilter;

        case TIME_DAWN:
            return gDawnFilter;

        case TIME_DAY:
            return gDayFilter;

        case TIME_SUNSET: 
            return gSunsetFilter;

        case TIME_NIGHTFALL:
            return gNightfallFilter;

        case TIME_NIGHT:
            return gNightFilter;
    }

    return 0;
}

static void DoDayNightLightning()
{
    u8 i;

    for (i = 0; i < sizeof(gLightingColors)/sizeof(gLightingColors[0]); i++)
    {
        u16 colorSlot = gLightingColors[i].paletteNum * 16 + gLightingColors[i].colorNum;

        if (gPaletteFade.active || gPlttBufferUnfaded[colorSlot] != 0x0000)
        {
            sDayNightPaletteDmaBuffer[colorSlot] = gPlttBufferFaded[colorSlot];
            gPlttBufferUnfaded[colorSlot] = gLightingColors[i].lightColor;
        }
        else
        {
            sDayNightPaletteDmaBuffer[colorSlot] = gLightingColors[i].lightColor;
        }
    }
}

//Returns Dns time lapse
u8 GetDayNightTimeLapse(u8 hour)
{
    if (hour < MIDNIGHT_END_HOUR)
        return TIME_MIDNIGHT;
    else if (hour < DAWN_END_HOUR)
        return TIME_DAWN;
    else if (hour < DAY_END_HOUR)
        return TIME_DAY;
    else if (hour < SUNSET_END_HOUR)
        return TIME_SUNSET;
    else if (hour < NIGHTFALL_END_HOUR)
        return TIME_NIGHTFALL;
    else 
        return TIME_NIGHT;
}

//Checks if current map is affected by dns
static bool8 IsMapDayNightException()
{
    u8 i;
    for (i=0; i < sizeof(gDayNightMapExceptions)/sizeof(gDayNightMapExceptions[0]); i++)
        if (gMapHeader.mapType == gDayNightMapExceptions[i])
            return TRUE;
    return FALSE;
}

//Returns true if the palette should not be affected by DNS filtering
static bool8 IsSpritePaletteTagDayNightException(u8 palNum)
{
    u8 i;

    for (i = 0; i < sizeof(gPaletteTagExceptions)/sizeof(gPaletteTagExceptions[0]); i++)
        if (GetSpritePaletteTagByPaletteNum(palNum) == gPaletteTagExceptions[i])
            return TRUE;
    return FALSE;
}

//Returns true if overworld is running
static bool8 IsOverworld()
{
    if (gMain.callback2 == CB2_Overworld || gMain.callback2 ==CB2_OverworldBasic)
        return TRUE;
    else
        return FALSE;
}

//Returns true if combat is running
static bool8 IsCombat()
{
    if (gMain.callback2 == BattleMainCB2)
        return TRUE;
    else
        return FALSE;
}

static bool8 IsLightActive()
{
    if (gLocalTime.hours >= LIGHTNING_START_HOUR || gLocalTime.hours < LIGHTNING_END_HOUR)
        return TRUE;
    return FALSE;
}