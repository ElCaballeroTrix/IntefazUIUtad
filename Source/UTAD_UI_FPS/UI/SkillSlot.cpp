// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillSlot.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Color.h"
#include "SkillTree.h"

void USkillSlot::NativeConstruct()
{
	Super::NativeConstruct();

	T_SkillPoints->SetText(FText::FromString(FString::Printf(TEXT("%d"), skillPointsNeeded)));
	B_SkillButton->OnPressed.AddDynamic(this, &USkillSlot::ClickedSkill);
	B_SkillButton->OnHovered.AddDynamic(this, &USkillSlot::ShowSkillText);
	B_SkillButton->OnUnhovered.AddDynamic(this, &USkillSlot::HideSkillText);
	B_SkillButton->OnReleased.AddDynamic(this, &USkillSlot::ReleaseSkill);
	I_SkillImage->SetBrush(skillImage);
	I_SkillBorder->SetBrush(borderImage);
	if (!canBeUnlocked) {
		I_SkillBorder->SetColorAndOpacity(FLinearColor::Red);
		I_SkillImage->SetColorAndOpacity(FLinearColor::Red);
	}
}

void USkillSlot::UnlockSkill()
{
	inConfirmPanel = false;
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
	if (!inConfirmPanel) {
		skillTree->HideSkillText();
	}
	if (!acquired && canBeUnlocked) {
		I_SkillBorder->SetColorAndOpacity(FLinearColor::White);
		I_SkillImage->SetColorAndOpacity(FLinearColor::White);	
	}
}

void USkillSlot::SetInConfirmPanel(bool _inConfirmPanel)
{
	inConfirmPanel = _inConfirmPanel;
}

void USkillSlot::ClickedSkill()
{
	playerIsHoldingButton = true;
}

void USkillSlot::ReleaseSkill()
{
	if (!acquired && canBeUnlocked && playerIsHoldingButton) {
		inConfirmPanel = true;
		skillTree->OpenConfirmPanel(this);
	}
	playerIsHoldingButton = false;
	time = 0.0f;
	P_HoldingProgress->SetPercent(0.0f);
}
void USkillSlot::SetSkillTree(USkillTree* newSkillTree)
{
	skillTree = newSkillTree;
}

void USkillSlot::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (playerIsHoldingButton) {
		time += InDeltaTime;
		P_HoldingProgress->SetPercent(FMath::Lerp(P_HoldingProgress->GetPercent(), 1.0f, 0.02f));
		if (time >= 2.0f) {
			UnlockSkill();
			time = 0.0f;
			playerIsHoldingButton = false;
			P_HoldingProgress->SetPercent(0.0f);
		}
	}
}


