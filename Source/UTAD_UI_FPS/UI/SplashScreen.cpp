// Fill out your copyright notice in the Description page of Project Settings.


#include "SplashScreen.h"
#include "Kismet/GameplayStatics.h"

void USplashScreen::NativeConstruct()
{
	Super::NativeConstruct();

	playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	playerController->SetInputMode(FInputModeGameAndUI());
	playerController->Pause();
}

void USplashScreen::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	time += InDeltaTime;
	if (time > 3.0f) {
		playerController->SetInputMode(FInputModeGameOnly());
		playerController->Pause();
		RemoveFromViewport();
	}
}
