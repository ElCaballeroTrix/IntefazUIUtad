// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoCounter.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "../TP_WeaponComponent.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
void UAmmoCounter::Show()
{
	//AUTAD_UI_FPSCharacter* character = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	AUTAD_UI_FPSCharacter* character = Cast<AUTAD_UI_FPSCharacter>(GetOwningPlayer()->GetCharacter());
	if (character) {
		UTP_WeaponComponent* weapon = character->GetAttachedWeaponComponent();
		character->OnTotalBulletsChanged.BindUObject(this, &UAmmoCounter::UpdateTotalAmmo);
		if (weapon) {
			weapon->OnCurrentNumBulletsChanged.BindUObject(this, &UAmmoCounter::UpdateCurrentAmmo);
		}
	}
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UAmmoCounter::Hide()
{
	AUTAD_UI_FPSCharacter* character = Cast<AUTAD_UI_FPSCharacter>(GetOwningPlayer()->GetCharacter());
	if (character) {
		UTP_WeaponComponent* weapon = character->GetAttachedWeaponComponent();
		character->OnTotalBulletsChanged.Unbind();
		if (weapon) {
			weapon->OnCurrentNumBulletsChanged.Unbind();
		}
	}
	SetVisibility(ESlateVisibility::Hidden);
}

void UAmmoCounter::UpdateCurrentAmmo(int NewCurrentAmmo)
{
	CurrentAmmo->SetText(FText::FromString(FString::Printf(TEXT("%d"), NewCurrentAmmo)));
}

void UAmmoCounter::UpdateTotalAmmo(int NewTotalAmmo)
{
	TotalAmmo->SetText(FText::FromString(FString::Printf(TEXT("%d"), NewTotalAmmo)));
}
