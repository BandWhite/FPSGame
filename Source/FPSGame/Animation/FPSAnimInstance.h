// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FPSAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API UFPSAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
protected:
	virtual void NativeBeginPlay() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadOnly)
	float Speed;
	UPROPERTY()
	class AMalCharacter* Player;

	UPROPERTY(BlueprintReadOnly)
	float Direction;
};
