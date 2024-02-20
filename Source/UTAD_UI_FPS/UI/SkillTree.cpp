// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillTree.h"
#include "SkillSlot.h"
#include "Components/PanelWidget.h"
#include "Components/Button.h"


void USkillTree::NativeConstruct()
{
	Super::NativeConstruct();

	for (UWidget* widget : SkillTreeCanvas->GetAllChildren())
	{
		USkillSlot* skillSlot = Cast<USkillSlot>(widget);
		if (skillSlot) {
			skillSlots.Add(skillSlot);
		}
	}
}

void USkillTree::ShowSkillText()
{

}
void USkillTree::HideSkillText()
{

}
