// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillTree.h"
#include "SkillSlot.h"
#include "Components/PanelWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"


void USkillTree::NativeConstruct()
{
	Super::NativeConstruct();

	for (UWidget* widget : Movement_Tree->GetAllChildren())
	{
		USkillSlot* skillSlot = Cast<USkillSlot>(widget);
		if (skillSlot) {
			skillSlot->SetSkillTree(this);
			skillSlots.Add(skillSlot);
		}
	}
	for (UWidget* widget : Health_Tree->GetAllChildren())
	{
		USkillSlot* skillSlot = Cast<USkillSlot>(widget);
		if (skillSlot) {
			skillSlot->SetSkillTree(this);
			skillSlots.Add(skillSlot);
		}
	}
	for (UWidget* widget : Strength_Tree->GetAllChildren())
	{
		USkillSlot* skillSlot = Cast<USkillSlot>(widget);
		if (skillSlot) {
			skillSlot->SetSkillTree(this);
			skillSlots.Add(skillSlot);
		}
	}
	//Confirm panel
	P_ConfirmPanel->SetVisibility(ESlateVisibility::Hidden);
	B_Confirm->OnClicked.AddDynamic(this, &USkillTree::ConfirmNewAbility);
	B_Cancel->OnClicked.AddDynamic(this, &USkillTree::CancelNewAbility);
}

void USkillTree::Show()
{
	SetVisibility(ESlateVisibility::Visible);
}

void USkillTree::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void USkillTree::ShowSkillText(FString name, FString description)
{
	FString skillText = "Skill Name: ";
	skillText.Append(name);
	skillText.Append("\n");
	skillText.Append("Skill Description: ");
	skillText.Append(description);
	T_SkillText->SetText(FText::FromString(skillText));
}
void USkillTree::HideSkillText()
{
	FString emptyText = "";
	T_SkillText->SetText(FText::FromString(emptyText));
}

void USkillTree::OpenConfirmPanel(USkillSlot* newSkill)
{
	P_ConfirmPanel->SetVisibility(ESlateVisibility::Visible);
	skillToBeObtained = newSkill;
}

void USkillTree::ConfirmNewAbility()
{
	skillToBeObtained->UnlockSkill();
	P_ConfirmPanel->SetVisibility(ESlateVisibility::Hidden);
	HideSkillText();
}

void USkillTree::CancelNewAbility()
{
	P_ConfirmPanel->SetVisibility(ESlateVisibility::Hidden);
	skillToBeObtained->SetInConfirmPanel(false);
	skillToBeObtained = nullptr;
	HideSkillText();
}
