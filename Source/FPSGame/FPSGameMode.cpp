// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameMode.h"

#include "Player/MalCharacter.h"

AFPSGameMode::AFPSGameMode()
{
	static ConstructorHelpers::FClassFinder<AMalCharacter> HeroClass(
		TEXT("Blueprint'/Game/FPS/Blueprints/Player/BP_MalColm.BP_MalColm_C'"));
	DefaultPawnClass = HeroClass.Class;
}
