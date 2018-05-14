#include "HealthComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"

UHealthComponent::UHealthComponent()
	:
	Stamina(100.f),
	UseStaminaSpeed(0.3f)
{
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UHealthComponent::StarnUseStamina()
{
	if (StaminaUse == true)
	{
		GetWorld()->GetTimerManager().SetTimer(UseStaminaTimer, this, &UHealthComponent::StarnUseStamina, UseStaminaSpeed, true, UseStaminaSpeed);
		Stamina -= 10;
		if (Stamina <= 0)
		{
			StaminaEnded = true;
			StopUseStamina();
		}
	}
}

void UHealthComponent::StopUseStamina()
{
	StaminaUse = false;
	GetWorld()->GetTimerManager().ClearTimer(UseStaminaTimer);
	StarnRegenStamina();
}

void UHealthComponent::StarnRegenStamina()
{
	GetWorld()->GetTimerManager().SetTimer(RegenStaminaTimer, this, &UHealthComponent::StarnRegenStamina, RegenStaminaSpeed, true, RegenStaminaSpeed);
	Stamina += 10;
	if (Stamina >= 100)
	{
		StopRegenStamina();
	}
}

void UHealthComponent::StopRegenStamina()
{
	GetWorld()->GetTimerManager().ClearTimer(RegenStaminaTimer);
}