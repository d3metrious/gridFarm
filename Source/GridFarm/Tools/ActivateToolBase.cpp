#include "ActivateToolBase.h"
#include "../GridManager.h"

// Sets default values
AActivateToolBase::AActivateToolBase()
{
	// Set this empty to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void AActivateToolBase::BeginPlay()
{
	Super::BeginPlay();
	GridManager = AGridManager::GetInstance();
	if(GridManager)
		GridManager->OnNewCellHighlightedDelegate.AddDynamic(this, NewCellHighlighted);
}

// Called every frame
void AActivateToolBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActivateToolBase::UpdateTool()
{

}

void AActivateToolBase::NewCellHighlighted(FIntPoint* NewCell)
{
	GridManager->GetCellLocation();

}

