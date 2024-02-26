// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillSlot.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Color.h"
#include "SkillTree.h"

void USkillSlot::NativeConstruct()
{
	Super::NativeConstruct();

	T_SkillPoints->SetText(FText::FromString(FString::Printf(TEXT("%d"), skillPointsNeeded)));
	B_SkillButton->OnClicked.AddDynamic(this, &USkillSlot::UnlockSkill);
	B_SkillButton->OnHovered.AddDynamic(this, &USkillSlot::ShowSkillText);
	B_SkillButton->OnUnhovered.AddDynamic(this, &USkillSlot::HideSkillText);
	I_SkillImage->SetBrush(skillImage);
	I_SkillBorder->SetBrush(borderImage);
	if (!canBeUnlocked) {
		I_SkillBorder->SetColorAndOpacity(FLinearColor::Red);
		I_SkillImage->SetColorAndOpacity(FLinearColor::Red);
	}
}

void USkillSlot::UnlockSkill()
{
	AUTAD_UI_FPSCharacter* player = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	int playerSkillPoints = player->GetSkillPoints();
	if (!canBeUnlocked) {
		PlaySound(errorSound);
		return;
	}
	if (!acquired && playerSkillPoints < skillPointsNeeded) {
		PlaySound(errorSound);
		return;
	}
	if(!acquired && playerSkillPoints >= skillPointsNeeded) {
		acquired = true;
		I_SkillBorder->SetColorAndOpacity(FLinearColor::White);
		I_SkillImage->SetColorAndOpacity(FLinearColor::White);
		I_SkillBorder->SetBrush(unlockedBrushBorder);
		I_SkillImage->SetBrush(unlockedBrushImage);
		
		playerSkillPoints -= skillPointsNeeded;
		player->AddSkillPoints(-skillPointsNeeded);
		//B_SkillButton->SetIsEnabled(false);
		PlaySound(clickedSound);
		for (USkillSlot* neighbor : neighbors)
		{
			neighbor->canBeUnlocked = true;
			neighbor->I_SkillBorder->SetColorAndOpacity(FLinearColor::White);
			neighbor->I_SkillImage->SetColorAndOpacity(FLinearColor::White);
		}
	}
}

void USkillSlot::ShowSkillText()
{
	skillTree->ShowSkillText(name, description);
	PlaySound(hoveredSound);
	if (!acquired && canBeUnlocked) {
		I_SkillBorder->SetColorAndOpacity(FLinearColor::Green);
		I_SkillImage->SetColorAndOpacity(FLinearColor::Green);
	}
}
void USkillSlot::HideSkillText()
{
	skillTree->HideSkillText();
	if (!acquired && canBeUnlocked) {
		I_SkillBorder->SetColorAndOpacity(FLinearColor::White);
		I_SkillImage->SetColorAndOpacity(FLinearColor::White);	
	}
}

void USkillSlot::SetSkillTree(USkillTree* newSkillTree)
{
	skillTree = newSkillTree;
}

void USkillSlot::ChangeColor(FLinearColor color)
{

}


