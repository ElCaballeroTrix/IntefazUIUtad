// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHealthBar.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UPlayerHealthBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlateColor redColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlateColor greenColor;

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();
	void UpdatePlayerHealthBar(int NewHealth, int MaxHealth);
protected:

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* P_PlayerHealthBar;
	float BlinkTimer = 0.f;
	float BlinkThresholdTimer = 0.f;
	float ProgressBarScale = 1.0f;
	float ScaleValueToAdd = 0.005f;
	bool bIsLowHealth = false;
	bool bBlinkTurningRed = false;

	void LowHealthBlink();
};
