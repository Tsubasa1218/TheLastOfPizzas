// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "Target.h"
#include "Enemy.h"
#include "Runtime/Engine/Public/EngineUtils.h"

AEnemyAIController::AEnemyAIController() {
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyAIController::BeginPlay() {
	Super::BeginPlay();

	// Find Actors by type (needs a UWorld object)
	for (TActorIterator<AEnemy> It(GetWorld()); It; ++It)
	{
		AEnemy* MyActor = *It;
		Enemies.Add(MyActor);
	}
}

void AEnemyAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (TargetToChase) {
		MoveToActor(TargetToChase);
	}
}
