// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "FPSCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API UFPSCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	virtual float GetMaxSpeed() const override;
	UFPSCharacterMovementComponent();

protected:
	UPROPERTY(EditAnywhere, Category="AFPSCharacterMovement")
	float NormalMaxWalkSpeed;
	UPROPERTY(EditAnywhere, Category="AFPSCharacterMovement")
	float NormalMaxRunSpeed;

	UPROPERTY(EditAnywhere, Category="AFPSCharacterMovement")
	float RifleMaxWalkSpeed;
	UPROPERTY(EditAnywhere, Category="AFPSCharacterMovement")
	float RifleMaxRunSpeed;

protected:
	float GetPlayerCurrentSpeed() const;
};

