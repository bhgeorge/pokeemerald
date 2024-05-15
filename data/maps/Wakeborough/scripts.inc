Wakeborough_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Wakeborough_OnTransition
	.byte 0

Wakeborough_OnTransition:
	@ setflag FLAG_VISITED_WAKEBOROUGH
	end