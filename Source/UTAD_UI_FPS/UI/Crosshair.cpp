// Fill out your copyright notice in the Description page of Project Settings.


#include "Crosshair.h"
#include "../UTAD_UI_FPS_Enemy.h"
#include "Components/Image.h"
#include "Styling/SlateColor.h"

void UCrosshair::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UWorld* world = GetWorld();
	FHitResult outHit;
	APlayerCameraManager* playerCamera = world->GetFirstPlayerController()->PlayerCameraManager;
	FVector start = playerCamera->GetCameraLocation();
	FVector end = start + (playerCamera->GetActorForwardVector() * 2000.0f);
	FCollisionQueryParams collisionParams;
	bool hit = world->LineTraceSingleByChannel(
		outHit,
		start,
		end,
		ECC_Visibility,
		collisionParams
	);
	FSlateBrush crossHairBrush = I_Crosshair->GetBrush();
	if (hit && outHit.bBlockingHit) {
		AUTAD_UI_FPS_Enemy* enemy = Cast<AUTAD_UI_FPS_Enemy>(outHit.GetActor());
		if (enemy) {
			crossHairBrush.TintColor = enemyColor;
		}
		else {
			crossHairBrush.TintColor = normalColor;
		}
	}
	else {
		crossHairBrush.TintColor = normalColor;
	}
	I_Crosshair->SetBrush(crossHairBrush);

	//Fire Animation
	if (bulletFired) {
		timeBulletFired += InDeltaTime;
		I_Crosshair->SetRenderTransformAngle(I_Crosshair->GetRenderTransformAngle() + angleImageRotation);
		if (timeBulletFired >= 1.0f) {
			timeBulletFired = 0.0f;
			bulletFired = false;
			I_Crosshair->SetRenderTransformAngle(0);
		}
		if (timeBulletFired >= 0.5f && angleImageRotation > 0.0f) {
			angleImageRotation *= -1;
		}
	}
}

void UCrosshair::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UCrosshair::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UCrosshair::SetBulletFired(bool _bulletFired)
{
	bulletFired = _bulletFired;
	timeBulletFired = 0.0f;
	I_Crosshair->SetRenderTransformAngle(0);
	angleImageRotation = FMath::Abs(angleImageRotation);
}
