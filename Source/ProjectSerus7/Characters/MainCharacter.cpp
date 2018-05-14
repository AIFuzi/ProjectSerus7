#include "MainCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"


AMainCharacter::AMainCharacter()
{
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPS_Camera"));
	Camera->AttachTo(RootComponent);

	PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ArmMesh"));
	PlayerMesh->AttachTo(Camera);

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	WeaponMesh->AttachTo(PlayerMesh, WeaponSocket, EAttachLocation::SnapToTarget, true);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));


	
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	//Mouse input
	PlayerInputComponent->BindAxis("Turn", this, &AMainCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMainCharacter::AddControllerPitchInput);
	//Keyboard input
	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
	//Jump
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	//Sprint
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMainCharacter::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMainCharacter::StopSprint);
	//Crouch
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMainCharacter::StartCrouch);
	//PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AMainCharacter::StopCrouch);


}

void AMainCharacter::MoveForward(float Val)
{
	AddMovementInput(GetActorForwardVector(), Val);
}

void AMainCharacter::MoveRight(float Val)
{
	AddMovementInput(GetActorRightVector(), Val);
}

void AMainCharacter::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 1200.f;
	IsSprint = true;
}

void AMainCharacter::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	IsSprint = false;
}

void AMainCharacter::StartCrouch()
{
	//ACharacter::Crouch();
	if (IsSprint == false)
	{
		if (IsCrouch == true)
		{
			ACharacter::Crouch();
			IsCrouch = false;
		}
		else
		{
			ACharacter::UnCrouch();
			IsCrouch = true;
		}
	}
}
