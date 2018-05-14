// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h" 
#include "Components/HealthComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class PROJECTSERUS7_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Val);
	void MoveRight(float Val);	
	
	void StartCrouch();
	bool IsCrouch = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//PLayer mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Character")
		USkeletalMeshComponent* PlayerMesh;

	//Weapon mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Character")
		USkeletalMeshComponent* WeaponMesh;

	//PlayerCamera
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Character")
		UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Character")
		FName WeaponSocket = TEXT("GripPoint");

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Input")
		bool IsSprint;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Character")
		UHealthComponent* HealthComponent;

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		void StartSprint();

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		void StopSprint();

};
