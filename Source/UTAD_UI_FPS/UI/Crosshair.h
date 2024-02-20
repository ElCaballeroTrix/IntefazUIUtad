// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Crosshair.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UCrosshair : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
public:

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();
private:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* I_Crosshair;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	FSlateColor enemyColor;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	FSlateColor normalColor;
};
