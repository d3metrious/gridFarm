#include "PlaceableBase.h"

// Sets default values
APlaceableBase::APlaceableBase()
{
	// Set this empty to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlaceableBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlaceableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
