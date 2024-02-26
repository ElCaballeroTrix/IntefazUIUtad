// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerSkillPoints.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UPlayerSkillPoints : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
public:
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UTextBlock* T_SkillPoints;

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	void UpdatePlayerSkillPoints(int playerSkillPoints);

};
