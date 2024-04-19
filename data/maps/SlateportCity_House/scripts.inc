SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

CeruleanCity_House3_EventScript_Dontae::
	lock
	faceplayer
	goto_if_set FLAG_TRADED_JYNX, CeruleanCity_House3_EventScript_AlreadyTraded
	setvar VAR_0x8008, INGAME_TRADE_JYNX
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox Trade_Text_DoYouHaveMonWouldYouTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, CeruleanCity_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, CeruleanCity_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Trade_Text_Thanks, MSGBOX_DEFAULT
	setflag FLAG_TRADED_JYNX
	release
	end

CeruleanCity_House3_EventScript_DeclineTrade::
	msgbox Trade_Text_WellIfYouDontWantTo
	release
	end

CeruleanCity_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_ThisIsntMon
	release
	end

CeruleanCity_House3_EventScript_AlreadyTraded::
	msgbox Trade_Text_HasTradedMonGrownStronger
	release
	end

Trade_Text_WellIfYouDontWantTo::
	.string "Well, if you don't want to…$"

Trade_Text_ThisIsntMon::
	.string "Hmmm?\n"
	.string "This isn't a {STR_VAR_1}.\p"
	.string "Think of me if you get one.$"

Trade_Text_DoYouHaveMonWouldYouTradeForMon::
	.string "Hello, there! Do you happen to\n"
	.string "have a {STR_VAR_1}?\p"
	.string "Would you agree to a trade for\n"
	.string "my {STR_VAR_2}?$"

Trade_Text_HasTradedMonGrownStronger::
	.string "The {STR_VAR_2} that I traded you,\n"
	.string "has it grown stronger?$"

Trade_Text_Thanks::
	.string "Thanks!$"

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "My POKéMON has a HASTY nature.\p"
	.string "It has higher SPEED compared to\n"
	.string "my other POKéMON.\p"
	.string "Maybe their nature has something to\n"
	.string "do with the stat gains of POKéMON.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "You're a TRAINER, aren't you?\p"
	.string "Since you came to SLATEPORT CITY,\n"
	.string "you must be going to the BATTLE TENT.$"

