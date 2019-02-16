// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "EnemyAIController.h"
#include "Components/VectorFieldComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Target.h"
// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TargetPosition = CreateDefaultSubobject<UVectorFieldComponent>(TEXT("TargetPosition"));
	TargetPosition->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName("headSocket"));

	GetCapsuleComponent()->bGenerateOverlapEvents = true;
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	MinSpeed = 200.f;
	MaxSpeed = 400.f;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	float speed = FMath::FRandRange(MinSpeed, MaxSpeed);
	GetCharacterMovement()->MaxWalkSpeed = speed;
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::SetTargetToChase(class ATarget* NewTarget) {
	
	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(GetController());;
	
	if (EnemyAIController) {
		EnemyAIController->SetTargetToChase(NewTarget);
	}
}


void AEnemy::NotifyActorBeginOverlap(AActor* Other)
{
	Super::NotifyActorBeginOverlap(Other);
	
	if (ATarget* Target = Cast<ATarget>(Other)) {
		Target->WasCollected(this->TargetPosition);
	}
	
}