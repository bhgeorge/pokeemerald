.set LOCALID_SNORLAX, 1
.set LOCALID_DOME_FOSSIL, 2

Fortree_Jungle_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Fortree_Jungle_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Fortree_Jungle_OnResume
	.byte 0

Fortree_Jungle_OnTransition:
	call_if_set FLAG_CAUGHT_SNORLAX, Fortree_Jungle_EventScript_HideSnorlax
	call_if_unset FLAG_CAUGHT_SNORLAX, Fortree_Jungle_EventScript_TryShowSnorlax
	end

Fortree_Jungle_EventScript_HideSnorlax::
	setflag FLAG_HIDE_SNORLAX
	return

Fortree_Jungle_EventScript_TryShowSnorlax::
	goto_if_set FLAG_DEFEATED_SNORLAX, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_SNORLAX
	return

Fortree_Jungle_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Fortree_Jungle_EventScript_TryRemoveSnorlax
	end

Fortree_Jungle_EventScript_TryRemoveSnorlax::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_SNORLAX
	return

Fortree_Jungle_EventScript_Snorlax::
	lock
	checkitem ITEM_BLUE_FLUTE
	goto_if_eq VAR_RESULT, TRUE, Fortree_Jungle_EventScript_SnorlaxAskFlute
	msgbox Fortree_Jungle_Text_SnorlaxNoFlute, MSGBOX_DEFAULT
	waitmessage
	release
	end

Fortree_Jungle_EventScript_SnorlaxAskFlute::
	msgbox Fortree_Jungle_Text_SnorlaxUseFlute, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, Fortree_Jungle_EventScript_SnorlaxNoFluteRet
	case MULTI_B_PRESSED, Fortree_Jungle_EventScript_SnorlaxNoFluteRet
	case YES, Fortree_Jungle_EventScript_SnorlaxFlute
	release
	end

Fortree_Jungle_EventScript_SnorlaxNoFluteRet::
	release
	end

Fortree_Jungle_EventScript_SnorlaxFlute::
	playfanfare MUS_RG_POKE_FLUTE
	waitfanfare
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SNORLAX, 55
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Fortree_Jungle_EventScript_DefeatedSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Fortree_Jungle_EventScript_RanFromSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Fortree_Jungle_EventScript_RanFromSnorlax
	setflag FLAG_CAUGHT_SNORLAX
	release
	end

Fortree_Jungle_EventScript_DefeatedSnorlax::
	setflag FLAG_DEFEATED_SNORLAX
	setvar VAR_0x8004, SPECIES_SNORLAX
	goto Common_EventScript_LegendaryRanAway
	end

Fortree_Jungle_EventScript_RanFromSnorlax::
	setvar VAR_0x8004, SPECIES_SNORLAX
	goto Common_EventScript_LegendaryRanAway
	end

Fortree_Jungle_EventScript_DomeFossil::
	finditem ITEM_DOME_FOSSIL
	end

Fortree_Jungle_EventScipt_AdamantMint::
	finditem ITEM_ADAMANT_MINT
	end

Fortree_Jungle_EventScript_BoldMint::
	finditem ITEM_BOLD_MINT
	end

Fortree_Jungle_Text_SnorlaxNoFlute:
	.string "There's a huge sleeping POKéMON here.\p"
	.string "If only there was something that\n"
	.string "could wake it.$"

Fortree_Jungle_Text_SnorlaxUseFlute:
	.string "Try and wake the POKéMON with\n"
	.string "the BLUE FLUTE?$"
