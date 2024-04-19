VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	goto_if_unset FLAG_RECEIVED_BULBASAUR VerdanturfTown_FriendshipRatersHouse_EventScript_GiveBulbasaur
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	goto_if_unset FLAG_RECEIVED_BULBASAUR VerdanturfTown_FriendshipRatersHouse_EventScript_GiveBulbasaur
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GiveBulbasaur::
	msgbox VerdanturfTown_Text_AskGiveBulbasaur, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VerdanturfTown_FriendshipRatersHouse_EventScript_DeclineBulbasaur
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BULBASAUR
	givemon SPECIES_BULBASAUR, 5, ITEM_NONE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VerdanturfTown_FriendshipRatersHouse_EventScript_ReceiveBulbasaurParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VerdanturfTown_FriendshipRatersHouse_EventScript_ReceiveBulbasaurPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DeclineBulbasaur::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DeclineBulbasaur, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_ReceiveBulbasaurParty::
	call VerdanturfTown_FriendshipRatersHouse_EventScript_ReceivedBulbasaurFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VerdanturfTown_FriendshipRatersHouse_EventScript_TakeCareBulbasaur
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VerdanturfTown_FriendshipRatersHouse_EventScript_TakeCareBulbasaur
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_ReceiveBulbasaurPC::
	call VerdanturfTown_FriendshipRatersHouse_EventScript_ReceivedBulbasaurFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VerdanturfTown_FriendshipRatersHouse_EventScript_SendBulbasaurToPC
	call Common_EventScript_NameReceivedBoxMon
	goto VerdanturfTown_FriendshipRatersHouse_EventScript_SendBulbasaurToPC
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_SendBulbasaurToPC::
	call Common_EventScript_TransferredToPC
	goto VerdanturfTown_FriendshipRatersHouse_EventScript_TakeCareBulbasaur
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_ReceivedBulbasaurFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message VerdanturfTown_FriendshipRatersHouse_Text_PlayerReceivedBulbasaur
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	return

VerdanturfTown_FriendshipRatersHouse_EventScript_TakeCareBulbasaur::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_TakeCareBulbasaur, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_RECEIVED_BULBASAUR
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_Text_AskGiveBulbasaur:
	.string "I've been looking for a trainer as\n"
	.string "kind as you to raise this BULBASAUR.\p"
	.string "It need a good home, could you\n"
	.string "possibly take it with you?$"

VerdanturfTown_FriendshipRatersHouse_Text_PlayerReceivedBulbasaur:
	.string "{PLAYER} received BULBASAUR!$"

VerdanturfTown_FriendshipRatersHouse_Text_DeclineBulbasaur:
	.string "Oh, that's ok. I'm sure I'll find it\n"
	.string "a good home.$"

VerdanturfTown_FriendshipRatersHouse_Text_TakeCareBulbasaur:
	.string "Take care BULBASAUR!\p"
	.string "I'm sure you'll be so happy.$"

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Let me see your POKéMON.\n"
	.string "I'll check to see how much it likes you.\p"
	.string "Oh.\n"
	.string "Your POKéMON…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "It adores you.\n"
	.string "It can't possibly love you any more.\l"
	.string "I even feel happy seeing it.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "It seems to be very happy.\n"
	.string "It obviously likes you a whole lot.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "It likes you quite a lot.\n"
	.string "It seems to want to be babied a little.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "It's getting used to you.\n"
	.string "It seems to believe in you.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "It's not very used to you yet.\n"
	.string "It neither loves nor hates you.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "It's very wary.\n"
	.string "It has scary viciousness in its eyes.\l"
	.string "It doesn't like you much at all.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "This is a little hard for me to say…\p"
	.string "Your POKéMON simply detests you.\n"
	.string "Doesn't that make you uncomfortable?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pika pika!$"

