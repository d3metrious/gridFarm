#pragma once

#include "CoreMinimal.h"
#include "../GridManager.h"
#include "ActivateToolBase.generated.h"

UCLASS()
class GRIDFARM_API AActivateToolBase : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Grid, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AGridManager* GridManager;
public:
	
	UPROPERTY()
	USceneComponent* Root;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDataTableRowHandle ToolData;

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

	UFUNCTION()
	void NewCellHighlighted();


};
