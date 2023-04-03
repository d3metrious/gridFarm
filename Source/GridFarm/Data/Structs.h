#pragma once

#include "CoreMinimal.h"
#include "../Tools/ActivateToolBase.h"
#include "Engine/DataTable.h"
#include "Structs.generated.h"


USTRUCT(BlueprintType)
struct FToolUseCost {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Money;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Diesel;
};

USTRUCT(BlueprintType)
struct FToolObjectData : public FTableRowBase{

	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActivateToolBase* ActiveToolClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActivateToolBase* PlaceableObjectClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntPoint ToolSize;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FToolUseCost UseCost;


};


