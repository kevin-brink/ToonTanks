// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"


// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
		return;

	RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition()
{
	// IF Player == null || is Dead THEN bail
	if (!PlayerPawn || !PlayerPawn->GetIsPlayerAlive())
		return;

	// IF Player is in range THEN Fire
	if (ReturnDistanceToPlayer() <= FireRange)
		Fire();
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn)
		return 0.0f;

	return FVector::Dist(PlayerPawn->GetActorLocation(), this->GetActorLocation());
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}