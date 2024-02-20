// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillSlot.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API USkillSlot : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnyWhere)
	FString name = "Name";
	UPROPERTY(EditAnyWhere)
	FString description = "Description";
	UPROPERTY(EditAnyWhere)
	int skillPointsNeeded = 1;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UButton* B_SkillButton;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UImage* I_SkillBorder;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UImage* I_SkillImage;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UTextBlock* T_SkillPoints;
	UPROPERTY(EditAnyWhere)
	FSlateBrush unlockedBrushImage;
	UPROPERTY(EditAnyWhere)
	FSlateBrush unlockedBrushBorder;
	bool canBeUnlocked = false;
	bool acquired = false;

	UFUNCTION()
	void ChangeColor(FLinearColor color);
	UFUNCTION()
	void ShowSkillText();
	UFUNCTION()
	void HideSkillText();
protected:
	virtual void NativeConstruct() override;
public:
	UFUNCTION()
	void UnlockSkill();

};
