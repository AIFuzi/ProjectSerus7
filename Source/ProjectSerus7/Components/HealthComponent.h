// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSERUS7_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FTimerHandle UseStaminaTimer;
	FTimerHandle RegenStaminaTimer;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
		float Stamina;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
		float UseStaminaSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
		float RegenStaminaSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
		bool StaminaUse = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
		bool StaminaEnded;

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		void StarnUseStamina();

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		void StopUseStamina();

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		void StarnRegenStamina();

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		void StopRegenStamina();

};
