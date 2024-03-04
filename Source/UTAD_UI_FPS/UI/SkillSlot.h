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
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UProgressBar* P_HoldingProgress;
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
	bool inConfirmPanel = false;
	bool playerIsHoldingButton = false;
	float time = 0.0f;
	//Sound
	UPROPERTY(EditAnyWhere)
	class USoundBase* hoveredSound;
	UPROPERTY(EditAnyWhere)
	class USoundBase* clickedSound;
	UPROPERTY(EditAnyWhere)
	class USoundBase* errorSound;
	//----

	//Connects with Skill Tree passes name and description
	UFUNCTION()
	void ShowSkillText();
	//Connects with Skill Tree and hides name and description
	UFUNCTION()
	void HideSkillText();
	//Sets player is Holding Button to true
	UFUNCTION()
	void ClickedSkill();
	//Sets player is Holding Button to false and connects with skill tree to show confirmation panel
	UFUNCTION()
	void ReleaseSkill();
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
public:
	//Unlocks Skill if able to
	void UnlockSkill();
	void SetSkillTree(USkillTree* newSkillTree);
	void SetInConfirmPanel(bool _inConfirmPanel);

};
