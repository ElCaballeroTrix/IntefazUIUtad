// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHealthBar.h"
#include "Kismet/GameplayStatics.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Components/ProgressBar.h"
#include "Math/Color.h"
#include "Styling/SlateColor.h"
#include "Animation/WidgetAnimation.h"

#define BLINK_ANIMATION_TIME 1.f
#define BLINK_THRESHOLD 0.25f

void UPlayerHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (bIsLowHealth) {
		BlinkTimer += InDeltaTime;
		bool close = FMath::IsNearlyEqual(BlinkTimer, BLINK_THRESHOLD,0.1);
		bool close1 = FMath::IsNearlyEqual(BlinkTimer, BLINK_THRESHOLD * 2, 0.1);
		bool close2 = FMath::IsNearlyEqual(BlinkTimer, BLINK_THRESHOLD * 3, 0.1);
		if (close || close1 || close2) {
			LowHealthBlink();
		}
		if (BlinkTimer >= BLINK_ANIMATION_TIME) {
			LowHealthBlink();
			BlinkTimer = 0.f;
		}

	}
}

void UPlayerHealthBar::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UPlayerHealthBar::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerHealthBar::UpdatePlayerHealthBar(int NewHealth, int MaxHealth)
{
	float percent = static_cast<float>(NewHealth) / MaxHealth;
	percent = FMath::Clamp(percent, 0, MaxHealth);
	if (percent <= 0.25) { //If health is below 25% => animation
		bIsLowHealth = true;
		LowHealthBlink();
	}
	P_PlayerHealthBar->SetPercent(percent);	
}

void UPlayerHealthBar::LowHealthBlink()
{
	bBlinkTurningRed = !bBlinkTurningRed;
	FProgressBarStyle progressbarStyle = P_PlayerHealthBar->GetWidgetStyle();
	FSlateBrush brush = progressbarStyle.FillImage;
	if (bBlinkTurningRed) {
		brush.TintColor = redColor;
	}
	else {
		brush.TintColor = greenColor;
	}
	progressbarStyle.SetFillImage(brush);
	P_PlayerHealthBar->SetWidgetStyle(progressbarStyle);
}
