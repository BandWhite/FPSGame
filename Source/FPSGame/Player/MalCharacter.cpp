// Fill out your copyright notice in the Description page of Project Settings.


#include "MalCharacter.h"

#include "Camera/CameraComponent.h"
#include "FPSGame/Components/FPSCharacterMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMalCharacter::AMalCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UFPSCharacterMovementComponent>(
		ACharacter::CharacterMovementComponentName))
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(CameraBoom);

	CurrentState = EMalState::EMS_Rifle;
}

// Called when the game starts or when spawned
void AMalCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMalCharacter::MoveForward(float Value)
{
	// AddMovementInput(GetActorForwardVector() * Value);

	FVector Dir = FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X);
	AddMovementInput(Dir * Value);
}

void AMalCharacter::MoveRight(float Value)
{
	// AddMovementInput(GetActorRightVector() * Value);
	FVector Dir = FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y);
	AddMovementInput(Dir * Value);
}

void AMalCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AMalCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AMalCharacter::DoSpringBegin()
{
	bSpring = true;
}

void AMalCharacter::DoSpringEnd()
{
	bSpring = false;
}

// Called every frame
void AMalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMalCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMalCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMalCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMalCharacter::Turn);
	PlayerInputComponent->BindAction(TEXT("DoSpring"), IE_Pressed, this, &AMalCharacter::DoSpringBegin);
	PlayerInputComponent->BindAction(TEXT("DoSpring"), IE_Released, this, &AMalCharacter::DoSpringEnd);
}

bool AMalCharacter::IsSpring()
{
	FVector MoveDir = GetVelocity();
	MoveDir.Normalize();
	return FVector::DotProduct(GetActorForwardVector(), MoveDir) > 0.9 && bSpring;
}

EMalState AMalCharacter::GetCurrentState()
{
	return CurrentState;
}
