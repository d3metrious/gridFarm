#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include <Components/InstancedStaticMeshComponent.h>
#include "Materials/MaterialInstanceDynamic.h"
#include "GridLibrary.h"
#include <Engine/DataTable.h>
#include "GridManager.generated.h"

class UStaticMeshComponent;
DECLARE_LOG_CATEGORY_EXTERN(CustomLog, Log, All);


USTRUCT(BlueprintType)
struct GRIDFARM_API FCellData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSubjectHandle SoilHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSubjectHandle CropHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentISMIndex;
};

USTRUCT(BlueprintType)
struct GRIDFARM_API FSoilConfig {

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = Soil)
	FSubjectRecord SoilRecord;

	UPROPERTY(EditAnywhere, Category = Soil)
	int SpawnChance = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Soil)
	UMaterialInterface* Material;

};


 



UCLASS()
class GRIDFARM_API AGridManager : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AGridManager();


	void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	static AGridManager* Instance;

	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Grid, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> GridMesh; 

	UPROPERTY(transient)
	TObjectPtr<APlayerController> playerController;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Active, Meta = (AllowPrivateAccess))
	FVector HitLocationVisibility;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Active, Meta = (AllowPrivateAccess))
	TObjectPtr<AActor> HitActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Active, Meta = (AllowPrivateAccess))
	FVector HitLocationCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Active, Meta = (AllowPrivateAccess))
	FIntPoint HitCell;

protected:
	UPROPERTY(EditAnywhere)
	UMaterialInterface* GridMaterial;


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Grid)
	TObjectPtr<UInstancedStaticMeshComponent> SoilMeshComponent;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintReadWrite, Category = Config)
	int GridCellSize = 100;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintReadWrite, Category = Config)
	FIntPoint GridSize = {32,32};

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Config)
	TArray<FSoilConfig> SoilTypes;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Session)
	TMap<FIntPoint, FCellData> CellMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	class UDataTable* ToolDataTable;

	
protected:

	void UpdateGridValues();

	FIntPoint GetCellFromWorldLocation(const FVector &Location);

	int GetCellAxis(const float &Value);

	void CreateSoil();

	int GetWeightedRandomSoilIndex();

public:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNewCellSignature, FIntPoint, NewCell);
	UFUNCTION(BlueprintCallable)
	virtual void NewCellHighlighted(FIntPoint NewCell);

	UPROPERTY(BlueprintAssignable)
	FNewCellSignature OnNewCellHighlightedDelegate;


	UFUNCTION(BlueprintCallable)
	void EnablePlantTool(const FName &ToolRow);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static AGridManager* GetInstance()
	{
		return Instance;
	}


	FVector2D GetCellCenter(const FIntPoint& Cell);

	FVector2D GetCenterOfArea(const FIntPoint &Cell, const FIntPoint SizeY);

	FVector GetCellLocation(const FIntPoint &Cell);

	FVector GetCurrentToolLocation();

	//
	




};



