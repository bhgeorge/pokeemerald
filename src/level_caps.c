#include "global.h"

#include "event_data.h"
#include "level_caps.h"

const u16 sLevelCapFlags[NUM_LEVEL_CAPS] = {FLAG_BADGE01_GET, FLAG_BADGE02_GET, FLAG_BADGE03_GET, FLAG_BADGE04_GET, FLAG_BADGE05_GET, FLAG_BADGE06_GET, FLAG_BADGE07_GET, FLAG_BADGE08_GET};
// This should match the ace of each corresponding gym
const u8 sLevelCapLevels[NUM_LEVEL_CAPS] = {10, 20, 30, 40, 50, 60, 70, 80};

u8 GetLevelCap(void)
{
  u32 i;

  // Check if the player wants level caps
  if (!FlagGet(FLAG_SYS_LEVEL_CAP))
    return MAX_LEVEL;

  // Find the first badge we don't have
  for (i = 0; i < NUM_LEVEL_CAPS; i++)
  {
    if (!FlagGet(sLevelCapFlags[i]))
      break;
  }

  // If we have all badges, it's 100
  if (i == NUM_LEVEL_CAPS)
    return MAX_LEVEL;
  else
    return sLevelCapLevels[i];
}