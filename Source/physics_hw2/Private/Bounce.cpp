// Fill out your copyright notice in the Description page of Project Settings.


#include "Bounce.h"

// Sets default values
ABounce::ABounce()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(SphereVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetWorldScale3D(FVector(RadiusScale));
	}
}

// Called when the game starts or when spawned
void ABounce::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABounce::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	FVector Delta = Velocity * DeltaTime * 20.0f;
	NewLocation += Delta;
	FVector LocalLocation = NewLocation - LocationInit;
	//float RunningTime = GetGameTimeSinceCreation();
	//float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	//NewLocation.X += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	FVector Ellipsoid = { RadiusInit * 7.0f, RadiusInit * 5.0f, RadiusInit * 5.0f };
	float EllipsoidEqX = LocalLocation.X / Ellipsoid.X;
	float EllipsoidEqY = LocalLocation.Y / Ellipsoid.Y;
	float EllipsoidEqZ = LocalLocation.Z / Ellipsoid.Z;
	if (EllipsoidEqX * EllipsoidEqX + EllipsoidEqY * EllipsoidEqY + EllipsoidEqZ * EllipsoidEqZ >= 1)
	{
		FVector Normal = {
			LocalLocation.X / (Ellipsoid.X * Ellipsoid.X),
			LocalLocation.Y / (Ellipsoid.Y * Ellipsoid.Y),
			LocalLocation.Z / (Ellipsoid.Z * Ellipsoid.Z)
		};
		Normal.Normalize();
		NewLocation -= Delta;
		Velocity -= 2 * Velocity.Dot(Normal) * Normal;
	}
	SetActorLocation(NewLocation);
}

