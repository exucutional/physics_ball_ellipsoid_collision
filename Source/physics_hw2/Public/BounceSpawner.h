// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chaos/Vector.h"
#include "GenericPlatform/GenericPlatform.h"
#include "BounceSpawner.generated.h"

UCLASS()
class PHYSICS_HW2_API ABounceSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABounceSpawner();

	UFUNCTION()
	void SpawnBounce();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UBoxComponent* SpawnVolume;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	static constexpr int SpawnSize = 1000;
	static constexpr float RadiusInit = 50.0;
};
