#include "ActivateToolBase.h"
#include "../Data/Structs.h"

// Sets default values
AActivateToolBase::AActivateToolBase()
{
	// Set this empty to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	if (Mesh) {
		Mesh->SetupAttachment(RootComponent);
		Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Mesh->SetMobility(EComponentMobility::Movable);
		}
}

// Called when the game starts or when spawned
void AActivateToolBase::BeginPlay()
{
	Super::BeginPlay();
	GridManager = AGridManager::GetInstance();
	if(GridManager){
		GridManager->OnNewCellHighlightedDelegate.AddUniqueDynamic(this, &ThisClass::NewCellHighlighted);

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

void AActivateToolBase::NewCellHighlighted()
{
	if (Mesh){
		FIntPoint toolSize = (ToolData.GetRow<FToolObjectData>(FString("Tool Data")))->ToolSize;
		Mesh->SetWorldLocation(GridManager->GetCurrentToolLocation(toolSize));
	}
}

