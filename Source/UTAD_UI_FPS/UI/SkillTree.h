// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillTree.generated.h"

class USkillSlot;
/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API USkillTree : public UUserWidget
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	UPanelWidget* SkillTreeCanvas;
	TArray<USkillSlot*> skillSlots;

	UFUNCTION()
	void ShowSkillText();
	UFUNCTION()
	void HideSkillText();
protected:
	virtual void NativeConstruct() override;
};
