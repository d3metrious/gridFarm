#pragma once

#include "CoreMinimal.h"
#include "Fertilizer.generated.h"

USTRUCT(BlueprintType)
struct GRIDFARM_API FFertilizer 
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int pHchange = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float NitrogenAdded = 40.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float PhosphorusAdded = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CalciumAdded = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MagnesiumAdded = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SulfurAdded = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MicronutrientsAdded = 1.0f;

};
