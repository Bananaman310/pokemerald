TheBarn_MapScripts::
	.byte 0


	TheBarn_EventScript_RaiseBreedingLevel::
		lock
		faceplayer
		goto_if_set FLAG_BREED_LEVEL_2, TheBarn_EventScript_RaiseToLevel3
		goto_if_set FLAG_BREED_LEVEL_3, TheBarn_EventScript_ResetToLevel1
		setflag FLAG_BREED_LEVEL_2
		clearflag FLAG_BREED_LEVEL_3
		msgbox TheBarn_Text_Set_To_2, MSGBOX_DEFAULT
		playfanfare MUS_OBTAIN_ITEM
		waitfanfare
		release
		end

	TheBarn_EventScript_RaiseToLevel3::
		setflag FLAG_BREED_LEVEL_3
		clearflag FLAG_BREED_LEVEL_2
		msgbox TheBarn_Text_Set_To_3, MSGBOX_DEFAULT
		playfanfare MUS_OBTAIN_ITEM
		waitfanfare
		release
		end


	TheBarn_EventScript_ResetToLevel1::
		clearflag FLAG_BREED_LEVEL_2
		clearflag FLAG_BREED_LEVEL_3
		msgbox TheBarn_Text_Reset_To_1, MSGBOX_DEFAULT
		playfanfare MUS_OBTAIN_ITEM
		waitfanfare
		release
		end

	TheBarn_EventScript_SwitchDaycare::
		lock
		faceplayer
		goto_if_eq VAR_CURRENT_DAYCARE, 0, TheBarn_EventScript_SwitchToBarn
		setvar VAR_CURRENT_DAYCARE, 0
		buffernumberstring STR_VAR_1, VAR_CURRENT_DAYCARE
		msgbox TheBarn_Text_Change_To_Daycare, MSGBOX_DEFAULT
		release
		end

	TheBarn_EventScript_SwitchToBarn::
		setvar VAR_CURRENT_DAYCARE, 1
		buffernumberstring STR_VAR_1, VAR_CURRENT_DAYCARE
		msgbox TheBarn_Text_Change_To_Barn, MSGBOX_DEFAULT
		release
		end

	TheBarn_EventScript_SwitchParty::
		lock
		faceplayer
		msgbox TheBarn_Text_SwitchParty, MSGBOX_NPC
		special SwitchToOffParty
		goto_if_set FLAG_FIRST_PARTY_SWITCH, TheBarn_EventScript_FinishPartySwitch
		setflag FLAG_FIRST_PARTY_SWITCH
		msgbox TheBarn_Text_GiveWeedle, MSGBOX_NPC
		givemon SPECIES_WEEDLE, 5
		goto TheBarn_EventScript_FinishPartySwitch
	
	TheBarn_EventScript_FinishPartySwitch::
		msgbox TheBarn_Text_SwitchPartyDone, MSGBOX_NPC
		release
		end
	


	TheBarn_Text_Reset_To_1:
		.string "IVs at level one.$"

	TheBarn_Text_Set_To_2:
		.string "IVs at level two.$"

	TheBarn_Text_Set_To_3:
		.string "IVs at level three.$"

	TheBarn_Text_Change_To_Barn:
		.string "Current DaycareVal: {STR_VAR_1}\n"
		.string "Active Daycare: Barn.$"

	TheBarn_Text_Change_To_Daycare:
		.string "Current DaycareVal: {STR_VAR_1}\n"
		.string "Active Daycare: Daycare.$"

	TheBarn_Text_SwitchParty:
		.string "Oh you want to switch parties?$"
	
	TheBarn_Text_GiveWeedle:
		.string "Oh you switched for the 1st time.\n"
		.string "Better take this pokemon.$"

	TheBarn_Text_SwitchPartyDone:
		.string "Better take this pokemon.$"


	

		