#include "global.h"

#include "event_data.h"
#include "item.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/moves.h"

bool8 PlayerHasFieldMove(u16 move)
{
    u16 item;
    switch (move)
    {
    case MOVE_SECRET_POWER:
        item = ITEM_TM43;
        break;
    case MOVE_CUT:
        item = ITEM_HM01;
        break;
    case MOVE_FLY:
        item = ITEM_HM02;
        break;
    case MOVE_SURF:
        item = ITEM_HM03;
        break;
    case MOVE_STRENGTH:
        item = ITEM_HM04;
        break;
    case MOVE_FLASH:
        item = ITEM_HM05;
        break;
    case MOVE_ROCK_SMASH:
        item = ITEM_HM06;
        break;
    case MOVE_WATERFALL:
        item = ITEM_HM07;
        break;
    case MOVE_DIVE:
        item = ITEM_HM08;
        break;
    default:
        return FALSE;
        break;
    }
    return CheckBagHasItem(item, 1);
}

bool8 CanPlayerUseFieldMove(u16 move)
{
  bool8 res = TRUE;

  if (!PlayerHasFieldMove(move))
    return FALSE;

  switch (move)
  {
  case MOVE_CUT:
    res = FlagGet(FLAG_BADGE01_GET);
    break;
  case MOVE_FLASH:
    res = FlagGet(FLAG_BADGE02_GET);
    break;
  case MOVE_ROCK_SMASH:
    res = FlagGet(FLAG_BADGE03_GET);
    break;
  case MOVE_STRENGTH:
    res = FlagGet(FLAG_BADGE04_GET);
    break;
  case MOVE_SURF:
    res = FlagGet(FLAG_BADGE05_GET);
    break;
  case MOVE_FLY:
    res = FlagGet(FLAG_BADGE06_GET);
    break;
  case MOVE_DIVE:
    res = FlagGet(FLAG_BADGE07_GET);
    break;
  case MOVE_WATERFALL:
    res = FlagGet(FLAG_BADGE08_GET);
    break;
  default:
    break;
  }

  return res;
}