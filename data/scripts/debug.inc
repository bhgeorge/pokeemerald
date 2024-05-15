Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_QuickStart::
	lockall
	setflag FLAG_SYS_POKEMON_GET
	givemon SPECIES_NIDORAN_F, 5, ITEM_NONE
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	closemessage
	release
	end

Debug_Script_1::
	lock
	closemessage
	release
	end

Debug_Script_2::
	lock
	closemessage
	release
	end

Debug_Script_3::
	end

Debug_Script_4::
	end

Debug_Script_5::
	end

Debug_Script_6::
	end

Debug_Script_7::
	end

Debug_Script_8::
	end
