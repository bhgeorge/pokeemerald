#include "global.h"
#include "main.h"
#include "event_data.h"
#include "pokemon.h"

static const s32 fieldIdDict[] =
{
    MON_DATA_HYPER_TRAINED_HP,
    MON_DATA_HYPER_TRAINED_ATK,
    MON_DATA_HYPER_TRAINED_DEF,
    MON_DATA_HYPER_TRAINED_SPATK,
    MON_DATA_HYPER_TRAINED_SPDEF,
    MON_DATA_HYPER_TRAINED_SPEED,
};

static bool8 CheckIsHyperTrained(struct Pokemon *mon, s32 fieldId)
{
    return GetMonData(mon, fieldId);
}

// Script arguments: 
// The Pokémon to teach is in VAR_0x8004
// The IV to train is in VAR_0x8005
bool8 IsIVHyperTrainable(void)
{
    if (!CheckIsHyperTrained(&gPlayerParty[gSpecialVar_0x8004], gSpecialVar_0x8005))
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

// Script arguments: 
// The Pokémon to teach is in VAR_0x8004
// The IV to train is in gSpecialVar_Result
bool8 PerformHyperTraining(void)
{
    s32 fieldId = fieldIdDict[gSpecialVar_Result];
    bool8 isTrainable = !CheckIsHyperTrained(&gPlayerParty[gSpecialVar_0x8004], fieldId);

    if (isTrainable)
    {
        u8 value = TRUE;
        SetMonData(&gPlayerParty[gSpecialVar_0x8004], fieldId, &value);
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}