.set LOCALID_LAPRAS, 1

OldLabIsland_Cave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldLabIsland_Cave_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, OldLabIsland_Cave_OnResume
	.byte 0

OldLabIsland_Cave_OnTransition:
	call_if_set FLAG_CAUGHT_LAPRAS, OldLabIsland_Cave_EventScript_HideLapras
	call_if_unset FLAG_CAUGHT_LAPRAS, OldLabIsland_Cave_EventScript_TryShowLapras
	end

OldLabIsland_Cave_EventScript_HideLapras::
	setflag FLAG_HIDE_LAPRAS
	return

OldLabIsland_Cave_EventScript_TryShowLapras::
	goto_if_set FLAG_DEFEATED_LAPRAS, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_LAPRAS
	return

OldLabIsland_Cave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, OldLabIsland_Cave_EventScript_TryRemoveLapras
	end

OldLabIsland_Cave_EventScript_TryRemoveLapras::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_LAPRAS
	return

OldLabIsland_Cave_EventScript_Lapras::
	lock
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_LAPRAS, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, OldLabIsland_Cave_EventScript_DefeatedLapras
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, OldLabIsland_Cave_EventScript_RanFromLapras
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, OldLabIsland_Cave_EventScript_RanFromLapras
	setflag FLAG_CAUGHT_LAPRAS
	release
	end

OldLabIsland_Cave_EventScript_DefeatedLapras::
	setflag FLAG_DEFEATED_LAPRAS
	setvar VAR_0x8004, SPECIES_LAPRAS
	goto Common_EventScript_LegendaryRanAway
	end

OldLabIsland_Cave_EventScript_RanFromLapras::
	setvar VAR_0x8004, SPECIES_LAPRAS
	goto Common_EventScript_LegendaryRanAway
	end

OldLabIsland_Cave_EventScript_ModestMint::
	finditem ITEM_MODEST_MINT
	end

OldLabIsland_Cave_EventScript_LinkStone::
	finditem ITEM_LINK_STONE
	end
