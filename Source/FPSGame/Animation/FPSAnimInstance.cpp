// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAnimInstance.h"

#include "FPSGame/Player/MalCharacter.h"


void UFPSAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	Player = Cast<AMalCharacter>(TryGetPawnOwner());
}

void UFPSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!Player)
	{
		return;
	}

	Speed = Player->GetVelocity().Size2D();
	FVector MoveDir = Player->GetVelocity();
	MoveDir.Normalize();
	Direction = CalculateDirection(MoveDir, FRotator(0, Player->GetControlRotation().Yaw, 0));
}
