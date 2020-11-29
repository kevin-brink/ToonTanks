// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"


// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireCondition()
{
	// IF Player == null || is Dead THEN bail

	// IF Player is in range THEN Fire

	UE_LOG(LogTemp, Warning, TEXT("Fire Condition Check"));
}