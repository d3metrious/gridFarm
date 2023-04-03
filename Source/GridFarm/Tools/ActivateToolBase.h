#pragma once

#include "CoreMinimal.h"
#include "ActivateToolBase.generated.h"

UCLASS()
class GRIDFARM_API AActivateToolBase : public AActor
{
	GENERATED_BODY()

	AGridManager* GridManager;

public:
	// Sets default values for this empty's properties
	AActivateToolBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void UpdateTool();

	void NewCellHighlighted(FIntPoint* NewCell);


};
