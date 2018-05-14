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

	//void CalculateStamina(bool Use);
	//void UseStamina(bool Use);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
	//	float Stamina;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
	//	float StaminaSpeed;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
	//	bool StaminaUse;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
	//	bool StaminaEnded;

	//UFUNCTION(BlueprintCallable, Category = "Sprint")
	//	void CalculateStamina();

	//UFUNCTION(BlueprintCallable, Category = "Sprint")
	//	void UseStamina();

};
