#pragma once

#include "CoreMinimal.h"
#include "PlaceableBase.generated.h"

UCLASS()
class GRIDFARM_API APlaceableBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this empty's properties
	APlaceableBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
