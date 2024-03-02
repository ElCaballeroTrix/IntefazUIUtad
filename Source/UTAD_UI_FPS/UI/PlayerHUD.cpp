// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "Crosshair.h"
#include "AmmoCounter.h"
#include "PlayerHealthBar.h"
#include "ReloadBar.h"
#include "PlayerSkillPoints.h"
#include "PlayerHitMarker.h"

void UPlayerHUD::ShowNoWeapon()
{
	PlayerHealthBarWidget->Show();
	AmmoCounterWidget->Hide();
	CrosshairWidget->Hide();
	ReloadBarWidget->Hide();
	MinimapWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UPlayerHUD::ShowAll()
{
	PlayerHealthBarWidget->Show();
	AmmoCounterWidget->Show();
	CrosshairWidget->Show();
	ReloadBarWidget->Show();
	PlayerSkillPointsWidget->Show();
	MinimapWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UPlayerHUD::Hide()
{
	PlayerHealthBarWidget->Hide();
	AmmoCounterWidget->Hide();
	CrosshairWidget->Hide();
	ReloadBarWidget->Hide();
	PlayerSkillPointsWidget->Hide();
	MinimapWidget->SetVisibility(ESlateVisibility::Hidden);
}
