#include "GridManager.h"
#include <Math/UnrealMathUtility.h>
#include "Data/Enums.h"
#include "Traits/Indexable.h"
#include "GridFarmGameModeBase.h"

DEFINE_LOG_CATEGORY(CustomLog);

AGridManager* AGridManager::Instance = nullptr;
// Sets default values
AGridManager::AGridManager()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	GridMesh = CreateDefaultSubobject<UStaticMeshComponent>("GridMesh");
	if (GridMesh) {
		GridMesh->SetupAttachment(RootComponent);
	}

	SoilMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>("Soil Mesh");
	if(SoilMeshComponent){
		SoilMeshComponent->SetupAttachment(Root);
		SoilMeshComponent->SetMobility(EComponentMobility::Static);
		SoilMeshComponent->SetCollisionProfileName("NoCollision");
	}

}

void AGridManager::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	FVector newScale = FVector((GridSize.X * (GridCellSize / 100)), (GridSize.Y * (GridCellSize / 100)), 1);
	GridMesh->SetRelativeScale3D(newScale);
	UE_LOG(CustomLog, Display, TEXT("New mesh scale is %s"), *newScale.ToString());

}

// Called when the game starts or when spawned
void AGridManager::BeginPlay()
{
	Super::BeginPlay();
	AGridManager::Instance = this;
	playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	
	UMaterialInstanceDynamic* DynamicGridMaterial = UMaterialInstanceDynamic::Create(GridMaterial, this);
	DynamicGridMaterial->SetScalarParameterValue("CellSize", GridCellSize);
	GridMesh->SetMaterial(0,DynamicGridMaterial);

	if (SoilTypes.IsEmpty()) {
		FSoilConfig defaultSoil;
		SoilTypes.Add(defaultSoil);
	}

	CreateSoil();

}

// Called every frame
void AGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateGridValues();
}


void AGridManager::UpdateGridValues()
{
	FHitResult hitResult(ForceInit);
	playerController->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), false, hitResult);
	HitLocationVisibility = hitResult.Location;
	HitActor = hitResult.GetActor();
	playerController->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Camera), false, hitResult);
	HitLocationCamera = hitResult.Location;

	HitCell = GetCellFromWorldLocation(hitResult.Location);



}

FIntPoint AGridManager::GetCellFromWorldLocation(const FVector &Location)
{
	return FIntPoint(GetCellAxis(Location.X), GetCellAxis(Location.Y));
}

int AGridManager::GetCellAxis(const float &Value)
{
	float relativeLocation = Value / GridCellSize;
	return (FMath::Abs(round(relativeLocation)) * FMath::Sign(round(relativeLocation)));
}

void AGridManager::CreateSoil()
{
	const auto Mechanism = UMachine::ObtainMechanism(GetWorld());

	FCellData newCellData;
	int i=0;
	for (int x = -GridSize.X; x < GridSize.X; x++)
	{
		for (int y = -GridSize.Y; y < GridSize.Y; y++)
		{
			i++;
			UE_LOG(CustomLog, Display, TEXT("New mesh index %d"), i);

			int soilTypeIndex = GetWeightedRandomSoilIndex();

			auto soil = Mechanism->SpawnSubject(SoilTypes[soilTypeIndex].SoilRecord);
			newCellData.SoilHandle = soil;
			

			FTransform meshTransform(FVector(x*GridCellSize,y*GridCellSize,0));

			soil.SetTrait(FIndexable(
				SoilMeshComponent->AddInstance(meshTransform, false)));

		
			CellMap.Add({x,y}, newCellData);
		}
	}	 
}

int AGridManager::GetWeightedRandomSoilIndex()
{
	auto index = UGridLibrary::GetRandomIndexFromArray(SoilTypes);
	return (SoilTypes[index].SpawnChance > FMath::RandRange(0, 100)) ? index : 0;
}

