// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Crop.generated.h"

USTRUCT(BlueprintType)
struct GRIDFARM_API FCrop
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WaterNeeded = 100.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int OptimalpH = 70;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SoilStructure = 100.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float NitrogenNeeded = 40.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float NitrogenAdded = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float PhosphorusNeeded = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CalciumNeeded = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MagnesiumNeeded = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SulfurNeeded = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MicronutrientsNeeded = 1.0f;

};
