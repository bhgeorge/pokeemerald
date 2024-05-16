.set LOCALID_NURSE, 1

Foxbourne_Pokecenter_MapScripts::
	.byte 0

Foxbourne_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end