// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterStatsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SWITCHCHARACTER_API UCharacterStatsComponent : public UActorComponent
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDie);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddLife, const int&, _life);


	UPROPERTY(Editanywhere, BluePrintReadWrite, Category = "Stats|Life", meta = (AllowPrivateAccess)) bool isDead = false;
	UPROPERTY(Editanywhere, BluePrintReadWrite ,Category = "Stats|Life" , meta = (AllowPrivateAccess , UIMin = 0, ClampMin = 0, UIMax = 100, ClampMax = 100)) int life = 100;
	
	
public:	
	
	UPROPERTY(Blueprintassignable , BluePrintCallable)FOnDie onDie;
	FOnAddLife onAddLife;
	
	//FORCEINLINE FOnDie& OnDie() { return onDie; }

	UCharacterStatsComponent();
	//FORCEINLINE int GetLife() const { return life; };

	UFUNCTION(BluePrintPure) int GetLife();

	UFUNCTION(BluePrintPure) bool IsDead();
	// UFUNCTION(BluePrintCallable) void RefEx(UPARAM(ref) int& _life); //UPARAM 

	UFUNCTION(BluePrintCallable) void AddLife(const int& _life);
	UFUNCTION(BluePrintCallable) void SetLife(const int& _life);
	UFUNCTION(BluePrintCallable) void RegenLife();
	UFUNCTION(BluePrintCallable) void SetDamage(int _damage);
};
