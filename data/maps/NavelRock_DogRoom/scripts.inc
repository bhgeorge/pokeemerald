.set LOCALID_RAIKOU, 1
.set LOCALID_ENTEI, 2
.set LOCALID_SUICUNE, 3

NavelRock_DogRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_DogRoom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_DogRoom_OnResume
	.byte 0

NavelRock_DogRoom_OnTransition:
	call_if_set FLAG_CAUGHT_RAIKOU, NavelRock_DogRoom_EventScript_HideRaikou
	call_if_unset FLAG_CAUGHT_RAIKOU, NavelRock_DogRoom_EventScript_TryShowRaikou
	call_if_set FLAG_CAUGHT_RAIKOU, NavelRock_DogRoom_EventScript_HideEntei
	call_if_unset FLAG_CAUGHT_RAIKOU, NavelRock_DogRoom_EventScript_TryShowEntei
	call_if_set FLAG_CAUGHT_RAIKOU, NavelRock_DogRoom_EventScript_HideSuicune
	call_if_unset FLAG_CAUGHT_RAIKOU, NavelRock_DogRoom_EventScript_TryShowSuicune
	end

NavelRock_DogRoom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_DogRoom_EventScript_TryRemoveRaikou
	end

NavelRock_DogRoom_EventScript_HideRaikou::
	setflag FLAG_HIDE_RAIKOU
	return

NavelRock_DogRoom_EventScript_TryShowRaikou::
	goto_if_set FLAG_DEFEATED_RAIKOU, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_RAIKOU
	return

NavelRock_DogRoom_EventScript_TryRemoveRaikou::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_RAIKOU
	return

NavelRock_DogRoom_EventScript_Raikou::
	lock
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAIKOU, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_DogRoom_EventScript_DefeatedRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_DogRoom_EventScript_RanFromRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_DogRoom_EventScript_RanFromRaikou
	setflag FLAG_CAUGHT_RAIKOU
	release
	end

NavelRock_DogRoom_EventScript_DefeatedRaikou::
	setflag FLAG_DEFEATED_RAIKOU
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryRanAway
	end

NavelRock_DogRoom_EventScript_RanFromRaikou::
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryRanAway
	end

NavelRock_DogRoom_EventScript_HideEntei::
	setflag FLAG_HIDE_ENTEI
	return

NavelRock_DogRoom_EventScript_TryShowEntei::
	goto_if_set FLAG_DEFEATED_ENTEI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_ENTEI
	return

NavelRock_DogRoom_EventScript_TryRemoveEntei::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ENTEI
	return

NavelRock_DogRoom_EventScript_Entei::
	lock
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ENTEI, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_DogRoom_EventScript_DefeatedEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_DogRoom_EventScript_RanFromEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_DogRoom_EventScript_RanFromEntei
	setflag FLAG_CAUGHT_ENTEI
	release
	end

NavelRock_DogRoom_EventScript_DefeatedEntei::
	setflag FLAG_DEFEATED_ENTEI
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryRanAway
	end

NavelRock_DogRoom_EventScript_RanFromEntei::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryRanAway
	end

NavelRock_DogRoom_EventScript_HideSuicune::
	setflag FLAG_HIDE_SUICUNE
	return

NavelRock_DogRoom_EventScript_TryShowSuicune::
	goto_if_set FLAG_DEFEATED_SUICUNE, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_SUICUNE
	return

NavelRock_DogRoom_EventScript_TryRemoveSuicune::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_SUICUNE
	return

NavelRock_DogRoom_EventScript_Suicune::
	lock
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_DogRoom_EventScript_DefeatedSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_DogRoom_EventScript_RanFromSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_DogRoom_EventScript_RanFromSuicune
	setflag FLAG_CAUGHT_SUICUNE
	release
	end

NavelRock_DogRoom_EventScript_DefeatedSuicune::
	setflag FLAG_DEFEATED_SUICUNE
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryRanAway
	end

NavelRock_DogRoom_EventScript_RanFromSuicune::
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryRanAway
	end
