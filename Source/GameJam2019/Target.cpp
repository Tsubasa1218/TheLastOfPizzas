// Fill out your copyright notice in the Description page of Project Settings.

#include "Target.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Public/TimerManager.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent; 

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(BoxComponent);

	bCanPickUp = true;
	EnablingTime = 3.f;
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
}

//void ATarget::NotifyActorBeginOverlap(AActor * Other)
//{
//	TArray<AActor*> OverlapActors;
//	BoxComponent->GetOverlappingActors(OverlapActors);
//
//	if (OverlapActors.Num() > 0) {
//
//	}
//}



void ATarget::SetCanPickUp()
{
	bCanPickUp = true;
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATarget::WasCollected(USceneComponent * ComponentToAttach)
{
	
	if (bCanPickUp) {
		bCanPickUp = false;
		RootComponent->AttachToComponent(ComponentToAttach, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
		UE_LOG(LogClass, Log, TEXT("Collecting!!!"));
		GetWorldTimerManager().SetTimer(PickUpEnableTimerHandle, this, &ATarget::SetCanPickUp, EnablingTime, false);
	}	
}
