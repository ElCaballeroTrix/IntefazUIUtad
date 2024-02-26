// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSkillPoints.h"
#include "Components/TextBlock.h"

void UPlayerSkillPoints::NativeConstruct()
{
	Super::NativeConstruct();
}

void UPlayerSkillPoints::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}


void UPlayerSkillPoints::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerSkillPoints::UpdatePlayerSkillPoints(int playerSkillPoints)
{
	T_SkillPoints->SetText(FText::FromString(FString::Printf(TEXT("%d"), playerSkillPoints)));
}

