.set LOCALID_SS_TIDAL, 1
.set LOCALID_SAILOR, 2

OldLabIsland_Exterior_MapScripts::
	.byte 0

OldLabIsland_Exterior_EventScript_Sailor::
	lock
	faceplayer
	msgbox OldLabIsland_Exterior_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldLabIsland_Exterior_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_OLD_LAB_ISLAND_EXTERIOR
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

OldLabIsland_Exterior_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end
