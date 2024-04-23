FortreeJungle_HouseLeft_MapScripts::
	.byte 0

FortreeJungle_HouseLeft_EventScript_Eugene::
	lock
	faceplayer
	goto_if_set FLAG_ENABLE_SHIP_NAVEL_ROCK, FortreeJungle_HouseLeft_EventScript_CheckTradeComplete
	msgbox FortreeJungle_HouseLeft_Text_WillYouTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeJungle_HouseLeft_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeJungle_HouseLeft_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	specialvar VAR_RESULT, GetTradeSpecies
	goto_if_ne VAR_RESULT, SPECIES_UNOWN, FortreeJungle_HouseLeft_EventScript_NotRequestedMon
	special GiveUnownToEugene
	goto FortreeJungle_HouseLeft_EventScript_GiveMysticTicket
	release
	end

FortreeJungle_HouseLeft_EventScript_GiveMysticTicket::
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK @ set this early to use for Eugene state
	checkitemspace ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, FortreeJungle_HouseLeft_EventScript_NoBagSpace
	msgbox FortreeJungle_HouseLeft_Text_HaveMysticTicket, MSGBOX_DEFAULT
	waitmessage
	waitbuttonpress
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	waitmessage
	release
	end

FortreeJungle_HouseLeft_EventScript_NoBagSpace::
	msgbox FortreeCity_HouseLeft_Text_NoBagSpace, MSGBOX_DEFAULT
	waitmessage
	release
	end

FortreeJungle_HouseLeft_EventScript_EugeneChikorita::
	lock
	playmoncry SPECIES_CHIKORITA, CRY_MODE_NORMAL
	waitmoncry
	release
	end

FortreeJungle_HouseLeft_EventScript_DeclineTrade::
	msgbox FortreeJungle_HouseLeft_Text_PleaseBringUnown, MSGBOX_DEFAULT
	release
	end

FortreeJungle_HouseLeft_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeJungle_HouseLeft_Text_NotRequestedMon, MSGBOX_DEFAULT
	release
	end

FortreeJungle_HouseLeft_EventScript_CheckTradeComplete::
	goto_if_set FLAG_RECEIVED_MYSTIC_TICKET, FortreeJungle_HouseLeft_EventScript_TradeComplete
	goto FortreeJungle_HouseLeft_EventScript_GiveMysticTicket
	release
	end

FortreeJungle_HouseLeft_EventScript_TradeComplete::
	msgbox FortreeJungle_HouseLeft_Text_WithMyUnown, MSGBOX_DEFAULT
	release
	end

FortreeJungle_HouseLeft_Text_WillYouTrade:
	.string "EUGENE: This jungle is more\n"
	.string "dangerous than I had imagined.\p"
	.string "I don't know if I'll be able to find\n"
	.string "and UNOWN on my own.\p"
	.string "You seem like a resourceful chap,\n"
	.string "could you bring me an UNOWN?$"

FortreeJungle_HouseLeft_Text_NotRequestedMon:
	.string "Umm, I don't believe that\n"
	.string "is an UNOWN.$"

FortreeJungle_HouseLeft_Text_PleaseBringUnown:
	.string "Please bring me an UNOWN\n"
	.string "that I can study!$"

FortreeCity_HouseLeft_Text_NoBagSpace:
	.string "Oh, I'm sorry, {PLAYER}.\n"
	.string "Your BAG's KEY ITEMS POCKET is full.\p"
	.string "Please store something on your PC,\n"
	.string "then come back for this.$"

FortreeJungle_HouseLeft_Text_WithMyUnown:
	.string "This precious UNOWN is fascinating!\n"
	.string "Thank you for bringing it to me.$"

FortreeJungle_HouseLeft_Text_HaveMysticTicket:
	.string "EUGENE: Incredible!\n"
	.string "How can I ever thank you?\p"
	.string "Here, you can have my MYSTIC TICKET.\p"
	.string "It appears to be for use at the\n"
	.string "LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"
