#include "HealthComponent.h"
#include "GameFramework/Actor.h"

UHealthComponent::UHealthComponent()
	//:
	//Stamina(100),
	//StaminaSpeed(-2)
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


//void UHealthComponent::CalculateStamina()
//{
//	if ((StaminaUse == true) && (Stamina > 0.f))
//	{
//		Stamina = (Stamina *= StaminaSpeed);
//	}
//	else 
//	{
//
//	}
//}
