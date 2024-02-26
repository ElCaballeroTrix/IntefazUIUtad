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
public:
	void Show();
	void Hide();
	UFUNCTION()
	void ShowSkillText(FString name, FString description);
	UFUNCTION()
	void HideSkillText();
private:
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	UPanelWidget* SkillTreeCanvas;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UTextBlock* T_SkillText;
	TArray<USkillSlot*> skillSlots;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	UPanelWidget* Movement_Tree;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	UPanelWidget* Health_Tree;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	UPanelWidget* Strength_Tree;
protected:
	virtual void NativeConstruct() override;
};
