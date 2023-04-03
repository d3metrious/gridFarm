// Copyright Epic Games, Inc. All Rights Reserved.


#include "GridFarmGameModeBase.h"
#include "Traits/Indexable.h"
#include "Kismet/GameplayStatics.h"

void AGridFarmGameModeBase::Tick(float DeltaTime)
{
	ThreadsCount++;
	Super::Tick(DeltaTime);
	if(ThreadsCount>10){
		ThreadsCount=0;
		UpdateSoil();
	}
	
}

void AGridFarmGameModeBase::UpdateSoil()
{
	const auto Mechanism = GetMechanism();
	static const auto Filter = FFilter::Make<FSoil>();

	Mechanism->OperateConcurrently(
	[=] (FSoil& Soil,
		FIndexable& Indexable) 
		{	
			const int ChangeAmount = FMath::RandRange(-5,5);

			Soil.Water =FMath::Clamp(Soil.Water + ChangeAmount,0,100);
			// Too slow
			//const auto GridManager = AGridManager::GetInstance();

			//GridManager->SoilMeshComponent->SetCustomDataValue(Indexable.Index, 1, Soil.Water/100, true);

		},1, BaseBatchSize);


}

void AGridFarmGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

