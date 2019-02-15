// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class GAMEJAM2019_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Timer, meta = (AllowPrivateAccess = "true"))
	float EnablingTime;

	bool bCanPickUp;
	FTimerHandle PickUpEnableTimerHandle;

	void SetCanPickUp();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void WasCollected(USceneComponent* ComponentToAttach);
	constexpr bool isPickable() { return bCanPickUp; }
};
