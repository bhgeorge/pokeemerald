Route01_MapScripts::
	.byte 0

Route01_EventScript_RouteSign::
	msgbox Route01_Text_RouteSign, MSGBOX_SIGN
	end

Route01_Text_RouteSign:
	.string "{LEFT_ARROW} UNNAMED PASS\n"
	.string "{RIGHT_ARROW} WAKEBOROUGH$"