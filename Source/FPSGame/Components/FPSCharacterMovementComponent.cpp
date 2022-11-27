// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacterMovementComponent.h"

#include "FPSGame/Player/MalCharacter.h"

float UFPSCharacterMovementComponent::GetMaxSpeed() const
{
	return GetPlayerCurrentSpeed();
}

UFPSCharacterMovementComponent::UFPSCharacterMovementComponent()
{
	NormalMaxWalkSpeed = 320;
	NormalMaxRunSpeed = 640;

	RifleMaxWalkSpeed = 400;
	RifleMaxRunSpeed = 800;
	
}

float UFPSCharacterMovementComponent::GetPlayerCurrentSpeed() const
{
	AMalCharacter* Player = Cast<AMalCharacter>(GetOwner());

	if (!Player)
	{
		return Super::GetMaxSpeed();
	}
	float Speed = 0;
	switch (Player->GetCurrentState())
	{
	case EMalState::EMS_Normal:
		if (Player->IsSpring())
		{
			Speed = NormalMaxRunSpeed;
		}
		else
		{
			Speed = NormalMaxWalkSpeed;
		}
		break;
	case EMalState::EMS_Rifle:
		if (Player->IsSpring())
		{
			Speed = RifleMaxRunSpeed;
		}
		else
		{
			Speed = RifleMaxWalkSpeed;
		}
		break;
	default:
		break;
	}
	return Speed;
}
