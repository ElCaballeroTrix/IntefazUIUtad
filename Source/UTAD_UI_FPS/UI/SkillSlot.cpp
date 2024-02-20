// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillSlot.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Color.h"

void USkillSlot::NativeConstruct()
{
	Super::NativeConstruct();

	T_SkillPoints->SetText(FText::FromString(FString::Printf(TEXT("%d"), skillPointsNeeded)));
	B_SkillButton->OnClicked.AddDynamic(this, &USkillSlot::UnlockSkill);
	B_SkillButton->OnHovered.AddDynamic(this, &USkillSlot::ShowSkillText);
	B_SkillButton->OnUnhovered.AddDynamic(this, &USkillSlot::HideSkillText);
	//I_SkillBorder->ColorAndOpacityDelegate.AddDynamic(this, &USkillSlot::ChangeColor);
}

void USkillSlot::UnlockSkill()
{
	AUTAD_UI_FPSCharacter* player = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	int playerSkillPoints = player->GetSkillPoints();
	if (!acquired && playerSkillPoints >= skillPointsNeeded) {
		I_SkillBorder->SetBrush(unlockedBrushBorder);
		I_SkillImage->SetBrush(unlockedBrushImage);
		acquired = true;
		playerSkillPoints -= skillPointsNeeded;
		player->SetSkillPoints(playerSkillPoints);
	}
}

void USkillSlot::ShowSkillText()
{

}
void USkillSlot::HideSkillText()
{

}

void USkillSlot::ChangeColor(FLinearColor color)
{

}


