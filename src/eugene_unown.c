#include "global.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"

void GiveUnownToEugene(void)
{
  u8 monId = GetCursorSelectionMonId();

  ZeroMonData(&gPlayerParty[monId]);
  CompactPartySlots();
  CalculatePlayerPartyCount();
}