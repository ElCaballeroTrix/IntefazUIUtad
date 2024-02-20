// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSkillPoints.h"

void UPlayerSkillPoints::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}


void UPlayerSkillPoints::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}