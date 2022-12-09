// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// Put other includes above this last one
#include "My_cpp_spawner.generated.h"

UCLASS()
class ROBOTRON_API AMy_cpp_spawner : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* mesh_obj;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* aimer_obj;

	UPROPERTY(EditAnywhere, Category = "my_props")
	TSubclassOf<APawn> spawn_pawn;

	UPROPERTY(EditAnywhere, Category = "my_props")
		float spawn_delay = 1.0f;

	float spawn_time_remaining;

public:	
	// Sets default values for this actor's properties
	AMy_cpp_spawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
