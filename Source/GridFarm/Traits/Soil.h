#pragma once
#include "CoreMinimal.h"
#include "../Data/Enums.h"
#include "Soil.generated.h"

USTRUCT(BlueprintType)
struct GRIDFARM_API FSoil {

	GENERATED_BODY();

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<SoilState> CurrentSoilState = Unpurchased;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Water = 100.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int pH = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SoilStructure = 100.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Nitrogen = 40.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Phosphorus = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Calcium = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Magnesium = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Sulfur = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Micronutrients = 1.0f;

};