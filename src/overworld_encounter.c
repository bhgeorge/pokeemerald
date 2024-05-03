#include "global.h"

#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_control_avatar.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "overworld_encounter.h"
#include "pokemon.h"
#include "random.h"
#include "script_pokemon_util.h"
#include "wild_encounter.h"

#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/trainer_types.h"

static void HideOverworldMon(struct ObjectEventTemplate *);

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

    if (OVERWORLD_SPAWN_ODDS < Random())
    {
      HideOverworldMon(template);
      continue;
    }

    metatileBehavior = MapGridGetMetatileBehaviorAt(template->x + MAP_OFFSET, template->y + MAP_OFFSET);
    isWaterMon = MetatileBehavior_IsSurfableFishableWater(metatileBehavior);
    // Pre-roll for a wild encounter
    slot = GetLocalWildMonSlot(isWaterMon);

    if (slot.index == WILD_MON_INDEX_NONE || slot.species == SPECIES_NONE)
    {
      HideOverworldMon(template);
      continue;
    }

    template->graphicsId = GetGfxIdForMon(slot.species, 0);
    // Roll for a shiny, we set a script to force
    // the encounter to be shiny when we interact with it
    template->shiny = IsWildMonShinyByRoll();
    // Store the slot, we'll use it to generate the right encounter on interact
    template->trainerRange_berryTreeId = slot.index;
    // This script handles the exclamation and `GetOverworldEncounterData` callback
    template->script = OverworldEncounter_EventScript_StartOverworldEncounter;
  }
}

static void HideOverworldMon(struct ObjectEventTemplate *template)
{
  FlagSet(template->flagId);
}

void GetOverworldEncounterData(void)
{
  u16 metatileBehavior = MapGridGetMetatileBehaviorAt(gObjectEvents[gSelectedObjectEvent].initialCoords.x, gObjectEvents[gSelectedObjectEvent].initialCoords.y);
  bool8 isWaterMon = MetatileBehavior_IsSurfableFishableWater(metatileBehavior);
  const u16 flag = GetObjectEventFlagIdByLocalIdAndMap(gObjectEvents[gSelectedObjectEvent].localId, gObjectEvents[gSelectedObjectEvent].mapNum, gObjectEvents[gSelectedObjectEvent].mapGroup);

  if (gObjectEvents[gSelectedObjectEvent].shiny != 0)
    FlagSet(FLAG_SYS_FORCE_SHINY);

  VarSet(VAR_0x8000, flag);
  OverworldWildEncounter(gObjectEvents[gSelectedObjectEvent].trainerRange_berryTreeId, isWaterMon);
}