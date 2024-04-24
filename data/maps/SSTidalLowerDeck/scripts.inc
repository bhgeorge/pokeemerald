SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_BlackBelt::
	trainerbattle_single TRAINER_HITMON_GIVER, SSTidalLowerDeck_Text_HitmonGiverIntro, SSTidalLowerDeck_Text_HitmonGiverDefeat
	msgbox SSTidalLowerDeck_Text_HitmonGiverPostBattle, MSGBOX_AUTOCLOSE
	goto_if_unset FLAG_RECEIVED_HITMON SSTidalLowerDeckEventScript_ChooseHitmon
	end

SSTidalLowerDeckEventScript_ChooseHitmon::
	msgbox SSTidalLowerDeck_Text_AskGiveHitmon, MSGBOX_DEFAULT
	multichoice 19, 6, MULTI_HITMON, FALSE
	switch VAR_RESULT
	case 0, SSTidalLowerDeck_EventScript_ChooseHitmonlee
	case 1, SSTidalLowerDeck_EventScript_ChooseHitmonchan
	case 2, SSTidalLowerDeck_EventScript_DeclineHitmon
	case MULTI_B_PRESSED, SSTidalLowerDeck_EventScript_DeclineHitmon
	end

SSTidalLowerDeck_EventScript_ChooseHitmonlee::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_HITMONLEE
	goto SSTidalLowerDeck_EventScript_GiveHitmon
	end

SSTidalLowerDeck_EventScript_ChooseHitmonchan::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_HITMONCHAN
	goto SSTidalLowerDeck_EventScript_GiveHitmon
	end

SSTidalLowerDeck_EventScript_DeclineHitmon::
	msgbox SSTidalLowerDeck_Text_DeclineHitmon, MSGBOX_DEFAULT
	release
	end

SSTidalLowerDeck_EventScript_GiveHitmon::
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 25, ITEM_BLACK_BELT
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, SSTidalLowerDeck_EventScript_ReceiveHitmonParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, SSTidalLowerDeck_EventScript_ReceiveHitmonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

SSTidalLowerDeck_EventScript_ReceiveHitmonParty::
	call SSTidalLowerDeck_EventScript_ReceivedHitmonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSTidalLowerDeck_EventScript_TakeCareHitmon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SSTidalLowerDeck_EventScript_TakeCareHitmon
	end

SSTidalLowerDeck_EventScript_ReceiveHitmonPC::
	call SSTidalLowerDeck_EventScript_ReceivedHitmonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSTidalLowerDeck_EventScript_SendHitmonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SSTidalLowerDeck_EventScript_SendHitmonToPC
	end

SSTidalLowerDeck_EventScript_SendHitmonToPC::
	call Common_EventScript_TransferredToPC
	goto SSTidalLowerDeck_EventScript_TakeCareHitmon
	end

SSTidalLowerDeck_EventScript_ReceivedHitmonFanfare::
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
	message SSTidalLowerDeck_Text_PlayerReceivedHitmon
	waitmessage
	waitfanfare
	return

SSTidalLowerDeck_EventScript_TakeCareHitmon::
	msgbox SSTidalLowerDeck_Text_TakeCareHitmon, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_RECEIVED_HITMON
	release
	end

SSTidalLowerDeck_Text_AskGiveHitmon:
	.string "A strong trainer like you should\n"
	.string "have a strong FIGHTING-type POKeMON.\p"
	.string "You can have one as a gift\n"
	.string "from our DOJO.\p"
	.string "Which would you like?$"

SSTidalLowerDeck_Text_PlayerReceivedHitmon:
	.string "{PLAYER} received {STR_VAR_1}!$"

SSTidalLowerDeck_Text_DeclineHitmon:
	.string "If that's what you want...$"

SSTidalLowerDeck_Text_TakeCareHitmon:
	.string "Now go be the best!$"

SSTidalLowerDeck_Text_HitmonGiverIntro:
	.string "I'm travelling to advertise our\n"
	.string "FIGHTING DOJO!\p"
	.string "Do you think you have it takes\n"
	.string "to become a master?$"

SSTidalLowerDeck_Text_HitmonGiverDefeat:
	.string "Very impressive!$"

SSTidalLowerDeck_Text_HitmonGiverPostBattle:
	.string "Please come to SAFFRON CITY to train\n"
	.string "in our DOJO.$"
	.string "We could learn a lot from you.$"

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Arrrgh! I'm fed up and dog-tired of\n"
	.string "cleaning this huge place!\p"
	.string "Let's have a quick battle!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Little bro, I lost!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "We're the CLEANUP BROTHERS!\p"
	.string "The old one dumps the detergent,\n"
	.string "and the young one does the scrubbing!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "This is the bottom of the ship's hull.\n"
	.string "There's plenty of room.\l"
	.string "It'll be alright for a POKéMON battle.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Big bro, I lost!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "We're the CLEANUP BROTHERS!\p"
	.string "The old one dumps the detergent,\n"
	.string "and the young one does the scrubbing!$"

