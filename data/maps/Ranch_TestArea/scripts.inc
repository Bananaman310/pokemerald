Ranch_TestArea_MapScripts::
	.byte 0

	RanchTestArea_EventScript_GivePokemonDemo::
		lock
		faceplayer
		msgbox Text_TakeDratini, MSGBOX_DEFAULT
		getpartysize
		compare VAR_RESULT, 6
		goto_if_eq Script_PlayerHasFullParty
		setflag FLAG_SYS_POKEMON_GET
		givemon SPECIES_CATERPIE, 5, ITEM_DRAGON_FANG
		playfanfare MUS_OBTAIN_ITEM
		msgbox Text_ReceivedDratini, MSGBOX_DEFAULT
		waitfanfare
		release
		end

	Script_PlayerHasFullParty::
		msgbox Text_PlayerHasFullParty, MSGBOX_DEFAULT
		release
		end

	Text_TakeDratini:
		.string "Please, take this Pokemon.$"

	Text_ReceivedDratini:
		.string "{PLAYER} received a Pokemon!$"

	Text_PlayerHasFullParty:
		.string "Ah, your party is full.$"
