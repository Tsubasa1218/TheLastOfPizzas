// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM2019_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

	AEnemyAIController();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
public:
	void SetTargetToChase(class ATarget* NewTarget) {
		TargetToChase = NewTarget;
	}
private:
	UPROPERTY()
	TArray<AActor*> Enemies;
	class ATarget* TargetToChase;
	
	
};
