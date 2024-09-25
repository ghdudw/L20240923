// Copyright Epic Games, Inc. All Rights Reserved.

#include "L20240923GameMode.h"
#include "L20240923Character.h"
#include "UObject/ConstructorHelpers.h"

AL20240923GameMode::AL20240923GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
