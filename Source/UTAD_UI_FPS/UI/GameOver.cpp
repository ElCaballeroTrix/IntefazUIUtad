// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOver.h"
#include "Components/Button.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

void UGameOver::NativeConstruct()
{
	Super::NativeConstruct();
	B_TryAgain->OnClicked.AddDynamic(this, &UGameOver::TryAgain);
	B_Exit->OnClicked.AddDynamic(this, &UGameOver::Exit);
}

void UGameOver::Show()
{
	PlaySound(gameOverSound);
	APlayerController* playerController = GetOwningPlayer<APlayerController>();
	playerController->SetInputMode(FInputModeUIOnly());
	playerController->bShowMouseCursor = true;
	playerController->Pause();
	B_TryAgain->SetFocus();
}

void UGameOver::TryAgain()
{
	APlayerController* playerController = GetOwningPlayer<APlayerController>();
	playerController->RestartLevel();
	playerController->SetInputMode(FInputModeGameOnly());
	playerController->bShowMouseCursor = false;
}

void UGameOver::Exit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), NULL, EQuitPreference::Quit, true);
}
