// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GameJam2019GameMode.h"
#include "GameJam2019PlayerController.h"
#include "GameJam2019Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Target.h"
#include "Enemy.h"

AGameJam2019GameMode::AGameJam2019GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGameJam2019PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	NumberOfTargetsToSpawn = 1;
	NumberOfEnemiesToSpawn = 2;
}

void AGameJam2019GameMode::BeginPlay() {
	SpawnTarget();
	SpawnedEnemies.SetNumUninitialized(NumberOfEnemiesToSpawn);
	for (int i = 0; i < NumberOfEnemiesToSpawn; i++)
	{
		SpawnedEnemies[i] = SpawnEnemy();
		SpawnedEnemies[i]->SetTargetToChase(SpawnedTarget);
	}
}

void AGameJam2019GameMode::SpawnTarget() {
	if (TargetToSpawn != NULL) {

		//Check if the world exists, to avoid cashes in the engine
		UWorld* const World = GetWorld();

		if (World != NULL) {
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Owner = this;
			SpawnParameters.Instigator = Instigator;

			//get the spawn location
			FVector SpawnLocation = FVector(FMath::RandRange(-500.f, 500.f), FMath::RandRange(-500.f, 500.f), 200.f);

			//Get a random rotation
			FRotator SpawnRotation = FRotator::ZeroRotator;

			//Spawn the target
			SpawnedTarget = World->SpawnActor<ATarget>(TargetToSpawn, SpawnLocation, SpawnRotation, SpawnParameters);
		}
	}
}


AEnemy* AGameJam2019GameMode::SpawnEnemy() {
	if (EnemyToSpawn != NULL) {

		//Check if the world exists, to avoid cashes in the engine
		UWorld* const World = GetWorld();

		if (World != NULL) {
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Owner = this;
			SpawnParameters.Instigator = Instigator;

			//get the spawn location
			FVector SpawnLocation = FVector(FMath::RandRange(-500.f, 500.f), FMath::RandRange(-500.f, 500.f), 200.f);

			//Get a random rotation
			FRotator SpawnRotation = FRotator::ZeroRotator;

			//Spawn the target
			
			return World->SpawnActor<AEnemy>(EnemyToSpawn, SpawnLocation, SpawnRotation, SpawnParameters);
		}
	}

	return nullptr;
}

