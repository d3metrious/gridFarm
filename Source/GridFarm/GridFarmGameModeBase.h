// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MechanicalGameModeBase.h"
#include "Traits/Soil.h"
#include "GridManager.h"
#include "GridFarmGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GRIDFARM_API AGridFarmGameModeBase : public AMechanicalGameModeBase

{
	GENERATED_BODY()

	
public:

	UPROPERTY(EditAnywhere, Category = Performance)
	int32 ThreadsCount = 4;

	UPROPERTY(EditAnywhere, Category = Performance)
	int32 BaseBatchSize = 128;




	void Tick(float DeltaTime) override;

protected:
	
	void UpdateSoil();


	void BeginPlay() override;
	

public:


};
 