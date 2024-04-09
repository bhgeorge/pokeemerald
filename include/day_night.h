#ifndef GUARD_DAY_NIGHT_H
#define GUARD_DAY_NIGHT_H

#define DNS_PAL_EXCEPTION   FALSE
#define DNS_PAL_ACTIVE      TRUE

#define TIME_OF_DAY_DAY   0
#define TIME_OF_DAY_NIGHT 1

struct LightingColor {
    u8 paletteNum;
    u8 colorNum;
    u16 lightColor;
};

struct DayNightPalExceptions {
    bool8 pal[32];
};

void DayNightTransferPlttBuffer(void *src, void *dest);
void DayNightApplyFilters();
u8 GetTimeOfDay();
u8 GetDayNightTimeLapse(u8 hour);

#endif // GUARD_DAY_NIGHT_H