Route02_MapScripts::
	.byte 0

@ -- SIGN --

Route02_EventScript_RouteSign::
	msgbox Route02_Text_RouteSign, MSGBOX_SIGN
	end

Route02_Text_RouteSign:
	.string "UNNAMED TUNNEL$"

@ -- TRAINER YOUNGSTER (Calvin) --

Route02_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route02_Text_CalvinIntro, Route02_Text_CalvinDefeated
	msgbox Route02_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
	end

Route02_Text_CalvinIntro:
	.string "If you have POKéMON with you, then\n"
	.string "you're an official POKéMON TRAINER!\l"
	.string "You can't say no to my challenge!$"

Route02_Text_CalvinDefeated:
	.string "Arrgh, I lost…\n"
	.string "I should have trained mine more…$"

Route02_Text_CalvinPostBattle:
	.string "Listen, you. If you're strong,\n"
	.string "you should have told me before!$"

@ -- TRAINER LASS (Tiana) --

Route02_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route02_Text_TianaIntro, Route02_Text_TianaDefeated
	msgbox Route02_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route02_Text_TianaIntro:
	.string "I'm going to keep winning and aim\n"
	.string "to be the best TRAINER.\p"
	.string "Help me further my career!$"

Route02_Text_TianaDefeated:
	.string "I ended up furthering your career…$"

Route02_Text_TianaPostBattle:
	.string "To keep winning my way up, I see that\n"
	.string "I have to catch more POKéMON.$"

@ -- TRAINER BUGCATCHER (Rick) --

Route02_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route02_Text_RickIntro, Route02_Text_RickDefeated
	msgbox Route02_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route02_Text_RickIntro:
	.string "Hahah! Our eyes met!\n"
	.string "I'll take you on with my BUG POKéMON!$"

Route02_Text_RickDefeated:
	.string "Ow! Down and out!$"

Route02_Text_RickPostBattle:
	.string "If you lock eyes with a TRAINER,\n"
	.string "you have to challenge! It's a rule!$"
