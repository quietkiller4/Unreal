// Fill out your copyright notice in the Description page of Project Settings.


#include "My_cpp_spawner.h"

// Sets default values
AMy_cpp_spawner::AMy_cpp_spawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set up our components
	mesh_obj = CreateDefaultSubobject<UStaticMeshComponent>("MainMesh");

	aimer_obj = CreateDefaultSubobject<USceneComponent>("Aimer");
	aimer_obj->SetupAttachment(mesh_obj);
	aimer_obj->AddWorldOffset(FVector(400, 0, 0));
	
}

// Called when the game starts or when spawned
void AMy_cpp_spawner::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("The Spawner is alive"));

	spawn_time_remaining = spawn_delay;
}

// Called every frame
void AMy_cpp_spawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	spawn_time_remaining -= DeltaTime;
	if (spawn_time_remaining <= 0)
	{
		spawn_time_remaining = spawn_delay;

		// Actually spawn
		GetWorld()->SpawnActor<APawn>(spawn_pawn, aimer_obj->GetComponentTransform());
	}
}

