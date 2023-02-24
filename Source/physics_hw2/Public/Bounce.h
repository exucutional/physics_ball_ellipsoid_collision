// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bounce.generated.h"

UCLASS()
class PHYSICS_HW2_API ABounce : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABounce();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere)
	uint32 Speed = 10.0;

	static constexpr float RadiusInit = 50.0;
	FVector LocationInit = { 0.0f, 0.0f, 0.0f };

	FVector Velocity = { 0.0f, 0.0f, 0.0f };

	UPROPERTY(EditAnywhere)
	float RadiusScale = 0.05;
};
