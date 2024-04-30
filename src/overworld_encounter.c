#include "global.h"

#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_control_avatar.h"
#include "fieldmap.h"
#include "overworld_encounter.h"
#include "metatile_behavior.h"
#include "script_pokemon_util.h"
#include "wild_encounter.h"

#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/trainer_types.h"

// TODO: Offload this to a more global structure
static const u16 sGfxIds[] =
{
  [SPECIES_WURMPLE] = OBJ_EVENT_GFX_WINGULL,
  [SPECIES_ZIGZAGOON] = OBJ_EVENT_GFX_ZIGZAGOON_1,
  [SPECIES_POOCHYENA] = OBJ_EVENT_GFX_POOCHYENA,
  [SPECIES_MARILL] = OBJ_EVENT_GFX_AZURILL,
  [SPECIES_GOLDEEN] = OBJ_EVENT_GFX_AZUMARILL
};

void TrySpawnOverworldMons(void)
{
  struct ObjectEventTemplate *template;
  const struct MapHeader *mapHeader;

  u32 i;
  u32 count;
  
  struct WildPokemonSlot slot;
  bool8 isWaterMon;
  u16 metatileBehavior;

  count = gMapHeader.events->objectEventCount;

  for (i = 0; i < count; i++)
  {
    template = &gSaveBlock1Ptr->objectEventTemplates[i];

    if (!template || template->trainerType != TRAINER_TYPE_OVERWORLD_MON)
      continue;
  
    metatileBehavior = MapGridGetMetatileBehaviorAt(template->x + MAP_OFFSET, template->y + MAP_OFFSET);
    isWaterMon = MetatileBehavior_IsSurfableFishableWater(metatileBehavior);
    // Pre-roll for a wild encounter
    slot = GetLocalWildMonSlot(isWaterMon);

    if (slot.index == WILD_MON_INDEX_NONE || slot.species == SPECIES_NONE)
      continue;

    template->graphicsId = sGfxIds[slot.species];
    template->trainerRange_berryTreeId = slot.index;
    template->script = OverworldEncounter_EventScript_StartOverworldEncounter;
  }
}

void GetOverworldEncounterData(void)
{
  u16 metatileBehavior = MapGridGetMetatileBehaviorAt(gObjectEvents[gSelectedObjectEvent].initialCoords.x, gObjectEvents[gSelectedObjectEvent].initialCoords.y);
  bool8 isWaterMon = MetatileBehavior_IsSurfableFishableWater(metatileBehavior);
  const u16 flag = GetObjectEventFlagIdByLocalIdAndMap(gObjectEvents[gSelectedObjectEvent].localId, gObjectEvents[gSelectedObjectEvent].mapNum, gObjectEvents[gSelectedObjectEvent].mapGroup);
  
  VarSet(VAR_0x8000, flag);
  OverworldWildMonEncounter(gObjectEvents[gSelectedObjectEvent].trainerRange_berryTreeId, isWaterMon);
}