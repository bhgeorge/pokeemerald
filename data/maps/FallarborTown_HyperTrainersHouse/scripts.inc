FallarborTown_HyperTrainersHouse_MapScripts::
	.byte 0

FallarborTown_HyperTrainersHouse_EventScript_HyperTrainer::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, FallarborTown_HyperTrainersHouse_EventScript_AskHyperTrain
	msgbox FallarborTown_HyperTrainersHouse_Text_ImTheHyperTrainer, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_HyperTrainersHouse_EventScript_AskHyperTrain
	end

FallarborTown_HyperTrainersHouse_EventScript_HyperTrainerGranddaughter::
	msgbox FallarborTown_HyperTrainersHouse_Text_HyperTrainerGranddaughter, MSGBOX_NPC
	end

FallarborTown_HyperTrainersHouse_EventScript_AskHyperTrain::
	checkitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_HyperTrainersHouse_EventScript_ComeBackWithBottleCap
	msgbox FallarborTown_HyperTrainersHouse_Text_ThatsABottleCapWantMeToTrain, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_HyperTrainersHouse_EventScript_ComeBackWithBottleCap
	goto FallarborTown_HyperTrainersHouse_EventScript_ChooseMon
	end

FallarborTown_HyperTrainersHouse_EventScript_ChooseMon::
	special ChooseMonForHyperTrainer
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_HyperTrainersHouse_EventScript_ComeBackWithBottleCap
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_HyperTrainersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, FallarborTown_HyperTrainersHouse_EventScript_NoUntrainedIVMon
	goto FallarborTown_HyperTrainersHouse_EventScript_ChooseIV
	end

FallarborTown_HyperTrainersHouse_EventScript_ChooseIV::
	msgbox FallarborTown_HyperTrainersHouse_Text_TrainWhichIV, MSGBOX_DEFAULT
	multichoice 20, 0, MULTI_STAT_OPTIONS, FALSE
	switch VAR_RESULT
	case 6, FallarborTown_HyperTrainersHouse_EventScript_ChooseMon
	case MULTI_B_PRESSED, FallarborTown_HyperTrainersHouse_EventScript_ChooseMon
	callnative PerformHyperTraining
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_HyperTrainersHouse_EventScript_IVAlreadyTrained
	goto FallarborTown_HyperTrainersHouse_EventScript_HyperTrainingComplete
	end

FallarborTown_HyperTrainersHouse_EventScript_IVAlreadyTrained::
	msgbox FallarborTown_HyperTrainersHouse_Text_IVAlreadyTrained, MSGBOX_DEFAULT
	goto FallarborTown_HyperTrainersHouse_EventScript_ChooseIV
	end

FallarborTown_HyperTrainersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_HyperTrainersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_HyperTrainersHouse_EventScript_ChooseMon
	end

FallarborTown_HyperTrainersHouse_EventScript_NoUntrainedIVMon::
	msgbox FallarborTown_HyperTrainersHouse_Text_NoUntrainedIVMon, MSGBOX_DEFAULT
	goto FallarborTown_HyperTrainersHouse_EventScript_ChooseMon
	end

FallarborTown_HyperTrainersHouse_EventScript_HyperTrainingComplete::
	msgbox FallarborTown_HyperTrainersHouse_Text_HandedOverBottleCap, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	fadescreen FADE_TO_BLACK
	closemessage
	playse SE_M_BELLY_DRUM
	waitse
	playse SE_BANG
	waitse
	playse SE_M_DOUBLE_TEAM
	waitse
	fadescreen FADE_FROM_BLACK
	msgbox FallarborTown_HyperTrainersHouse_Text_HyperTrainingComplete, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_HyperTrainersHouse_EventScript_ComeBackWithBottleCap::
	msgbox FallarborTown_HyperTrainersHouse_Text_ComeBackWithBottleCap, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_HyperTrainersHouse_Text_ImTheHyperTrainer:
	.string "I can help your POKéMON unleash their\n"
	.string "true potential with my hyper training!\p"
	.string "But first I'll need a shiny BOTTLE CAP.$"

FallarborTown_HyperTrainersHouse_Text_ThatsABottleCapWantMeToTrain:
	.string "Oooh! Fantastic! You've got a shiny new\n"
	.string "BOTTLE CAP for me!\p"
	.string "Would you like me to hyper train one of\n"
	.string "your POKéMON?$"

FallarborTown_HyperTrainersHouse_Text_CantTeachEgg:
	.string "Well... you'll have to wait for this EGG\n"
	.string "to hatch before I can train it.$"

FallarborTown_HyperTrainersHouse_Text_NoUntrainedIVMon:
	.string "This POKéMON is already perfect!\n"
	.string "I can't train it any further.$"

FallarborTown_HyperTrainersHouse_Text_TrainWhichIV:
	.string "What would you like me to train?$"

FallarborTown_HyperTrainersHouse_Text_IVAlreadyTrained:
	.string "Hrmm, looks like this has already\n"
	.string "reached its full potential.$"

FallarborTown_HyperTrainersHouse_Text_HandedOverBottleCap:
	.string "{PLAYER} handed over one BOTTLE CAP\n"
	.string "in exchange.$"

FallarborTown_HyperTrainersHouse_Text_HyperTrainingComplete:
	.string "Hooray! Your POKéMON's true\n"
	.string "potential has been unleashed!\p"
	.string "If you want more training, come back\n"
	.string "with another BOTTLE CAP.$"

FallarborTown_HyperTrainersHouse_Text_ComeBackWithBottleCap:
	.string "If your POKéMON need my hyper training\n"
	.string "come back with a BOTTLE CAP.$"

FallarborTown_HyperTrainersHouse_Text_HyperTrainerGranddaughter:
	.string "My grandma is a great POKéMON trainer...\p"
	.string "But I'm not sure why she's so obsessed\n"
	.string "with old BOTTLE CAPs.$"

