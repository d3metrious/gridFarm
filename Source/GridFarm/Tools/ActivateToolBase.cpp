#include "ActivateToolBase.h"
#include "../GridManager.h"
#include "../Data/Structs.h"

// Sets default values
AActivateToolBase::AActivateToolBase()
{
	// Set this empty to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("GridMesh");
	if (Mesh) {
		Mesh->SetupAttachment(RootComponent);
	}
}

// Called when the game starts or when spawned
void AActivateToolBase::BeginPlay()
{
	Super::BeginPlay();
	GridManager = AGridManager::GetInstance();
	if(GridManager){
		GridManager->OnNewCellHighlightedDelegate.AddDynamic(this, NewCellHighlighted);

		//ToolData = GridManager->ToolDataTable->get
	}
}

// Called every frame
void AActivateToolBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActivateToolBase::UpdateTool()
{

}

void AActivateToolBase::NewCellHighlighted(FIntPoint NewCell)
{
	FVector location = GridManager->GetCenterOfArea(NewCell, FIntPoint(1,1) );
							//ToolData->GetRow<FToolObjectData>(const FString("Tool Data"))->ToolSize);
	location.Z = GridManager->GetCellLocation(NewCell).Z;

	Mesh->SetWorldLocation(location);

}

