// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillSlot.generated.h"

class USkillTree;
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
	FSlateBrush skillImage;
	UPROPERTY(EditAnyWhere)
	FSlateBrush borderImage;
	UPROPERTY(EditAnyWhere)
	FSlateBrush unlockedBrushImage;
	UPROPERTY(EditAnyWhere)
	FSlateBrush unlockedBrushBorder;
	UPROPERTY(EditAnyWhere)
	TArray<USkillSlot*> neighbors;
	UPROPERTY(EditAnyWhere)
	bool canBeUnlocked = false;
	bool acquired = false;
	USkillTree* skillTree;
	//Sound
	UPROPERTY(EditAnyWhere)
	class USoundBase* hoveredSound;
	UPROPERTY(EditAnyWhere)
	class USoundBase* clickedSound;
	UPROPERTY(EditAnyWhere)
	class USoundBase* errorSound;
	//----

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
	void SetSkillTree(USkillTree* newSkillTree);

};
