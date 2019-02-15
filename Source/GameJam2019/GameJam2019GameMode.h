// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameJam2019GameMode.generated.h"


UCLASS(minimalapi)
class AGameJam2019GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameJam2019GameMode();
	virtual void BeginPlay();
	UPROPERTY(EditAnywhere, Category = Target)
		int NumberOfTargetsToSpawn;

	UPROPERTY(EditAnywhere, Category = Enemy)
		int NumberOfEnemiesToSpawn;
private:

	UPROPERTY(EditAnywhere, Category = "Target", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ATarget> TargetToSpawn;
	class ATarget* SpawnedTarget;
	void SpawnTarget();

	UPROPERTY(EditAnywhere, Category = "Enemy", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AEnemy> EnemyToSpawn;
	class AEnemy* SpawnEnemy();
	TArray<class AEnemy*> SpawnedEnemies;
};



