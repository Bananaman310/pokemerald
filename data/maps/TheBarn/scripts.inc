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
