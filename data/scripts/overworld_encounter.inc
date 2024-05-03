OverworldEncounter_EventScript_StartOverworldEncounter::
  lock
  faceplayer
  playse SE_PIN
  applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
  waitmovement 0
  applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
  special GetOverworldEncounterData
  setflag FLAG_SYS_CTRL_OBJ_DELETE
  dowildbattle
  clearflag FLAG_SYS_CTRL_OBJ_DELETE
  setflag VAR_0x8000 @Stored in GetOverworldEncounterData
  goto Common_EventScript_RemoveStaticPokemon
  release
  end
