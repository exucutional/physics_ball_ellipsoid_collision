// Fill out your copyright notice in the Description page of Project Settings.


#include "BounceSpawner.h"
#include "Components/BoxComponent.h"
#include "Bounce.h"

// Sets default values
ABounceSpawner::ABounceSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	SpawnVolume->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABounceSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnBounce();
}

void ABounceSpawner::SpawnBounce()
{
	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();
	SpawnLocation.Z -= RadiusInit*0.1;
	FRandomStream rand;
	rand.GenerateNewSeed();
	for (int i = 0; i < SpawnSize; ++i)
	{
		ABounce* Bounce = GetWorld()->SpawnActor<ABounce>(SpawnLocation, SpawnRotation);
		FVector RandomVelocity = rand.GetUnitVector();
		Bounce->Velocity = RandomVelocity * 3.0f;
		Bounce->LocationInit = SpawnLocation;
	}
}

// Called every frame
void ABounceSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

