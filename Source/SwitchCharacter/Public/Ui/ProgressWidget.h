// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/ProgressBar.h>
#include "ProgressWidget.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API UProgressWidget : public UUserWidget
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateLifebar, float, _percent);


	UPROPERTY(EditAnywhere, meta = (BindWidget)) TObjectPtr<UProgressBar> healthBar = nullptr;
	

	// UPROPERTY(EditAnywhere) TObjectPtr<URadialSlider> slider;
	FOnUpdateLifebar onLifeBarUpdate;


	FORCEINLINE TObjectPtr<UProgressBar> GetHealthBar() { return healthBar; }


	virtual void InitBinding();


	virtual void NativeConstruct() override;
	

	UFUNCTION() void OnLifeUpdate(const int& _life);

	UFUNCTION() void OnDamageUpdate(const int& _life);

	void OnUpdateLifeColor(float _percent);
};
