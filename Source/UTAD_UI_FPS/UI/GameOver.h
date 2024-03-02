// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOver.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UGameOver : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* B_TryAgain;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* B_Exit;
	UPROPERTY(EditAnyWhere)
	class USoundBase* gameOverSound;

	void Show();
	UFUNCTION()
	void TryAgain();
	UFUNCTION()
	void Exit();
protected:
	virtual void NativeConstruct() override;
private:
	

};
