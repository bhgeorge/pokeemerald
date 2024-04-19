Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadyRestStop_EventScript_Leaf::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_CHARMANDER, Route111_OldLadyRestStop_EventScript_GiveCharmander
	msgbox Route111_OldLadyRestStop_Text_HowIsCharmander, MSGBOX_DEFAULT
	release
	end

Route111_OldLadyRestStop_EventScript_GiveCharmander::
	msgbox Route111_OldLadyRestStop_Text_AskGiveCharmander, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route111_OldLadyRestStop_EventScript_DeclineCharmander
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHARMANDER
	givemon SPECIES_CHARMANDER, 5, ITEM_NONE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route111_OldLadyRestStop_EventScript_ReceiveCharmanderParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route111_OldLadyRestStop_EventScript_ReceiveCharmanderPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route111_OldLadyRestStop_EventScript_DeclineCharmander::
	msgbox Route111_OldLadyRestStop_Text_DeclineCharmander, MSGBOX_DEFAULT
	release
	end

Route111_OldLadyRestStop_EventScript_ReceiveCharmanderParty::
	call Route111_OldLadyRestStop_EventScript_ReceivedCharmanderFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route111_OldLadyRestStop_EventScript_TakeCareCharmander
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route111_OldLadyRestStop_EventScript_TakeCareCharmander
	end

Route111_OldLadyRestStop_EventScript_ReceiveCharmanderPC::
	call Route111_OldLadyRestStop_EventScript_ReceivedCharmanderFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route111_OldLadyRestStop_EventScript_SendCharmanderToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route111_OldLadyRestStop_EventScript_SendCharmanderToPC
	end

Route111_OldLadyRestStop_EventScript_SendCharmanderToPC::
	call Common_EventScript_TransferredToPC
	goto Route111_OldLadyRestStop_EventScript_TakeCareCharmander
	end

Route111_OldLadyRestStop_EventScript_ReceivedCharmanderFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route111_OldLadyRestStop_Text_PlayerReceivedCharmander
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	return

Route111_OldLadyRestStop_EventScript_TakeCareCharmander::
	msgbox Route111_OldLadyRestStop_Text_TakeCareCharmander, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_RECEIVED_CHARMANDER
	release
	end

Route111_OldLadyRestStop_Text_AskGiveCharmander:
	.string "You must be on quite the adventure\n"
	.string "to be this far from LITTLEROOT.\p"
	.string "This CHARMANDER is the adventurous\n"
	.string "type too!\p"
	.string "Could you take it with you?$"

Route111_OldLadyRestStop_Text_PlayerReceivedCharmander:
	.string "{PLAYER} received CHARMANDER!$"

Route111_OldLadyRestStop_Text_DeclineCharmander:
	.string "If you change your mind, I'll be\n"
	.string "right here.$"

Route111_OldLadyRestStop_Text_TakeCareCharmander:
	.string "Good luck out there CHARMANDER!$"

Route111_OldLadyRestStop_Text_HowIsCharmander:
	.string "How is CHARMANDER doing?$"

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Oh, dear, dear.\n"
	.string "Aren't your POKéMON exhausted?\p"
	.string "If you'd like, rest up here.\n"
	.string "That's a fine idea! You should do that.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "That's right.\n"
	.string "Take your time and rest up!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Oh, dear, dear.\n"
	.string "Are your POKéMON still tired?\p"
	.string "You should take another rest here.\n"
	.string "That's a fine idea. You should do that.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Is that so?\n"
	.string "You don't need to be shy about it.$"

