// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHitMarker.h"
#include "Components/Image.h"

void UPlayerHitMarker::NativeConstruct()
{
	Super::NativeConstruct();
	I_Blood->SetRenderOpacity(0);
}

void UPlayerHitMarker::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (gotHit) {
		time += InDeltaTime;
		float imageOpacity = I_Blood->GetRenderOpacity() + opacityValue;
		imageOpacity = FMath::Clamp(imageOpacity, 0.0f, 1.0f);
		I_Blood->SetRenderOpacity(imageOpacity);
		if (time >= 1.0f) {
			time = 0.0f;
			gotHit = false;
			opacityValue = FMath::Abs(opacityValue);
			I_Blood->SetRenderOpacity(0.0f);
		}
		//After half a second, it starts changing the opacity in reverse
		if (time >= 0.5f && opacityValue > 0.0f) {
			opacityValue *= -1;
		}
	}
	
}

void UPlayerHitMarker::GotHit()
{
	opacityValue = FMath::Abs(opacityValue);
	I_Blood->SetRenderOpacity(0);
	time = 0.0f;
	gotHit = true;
}
