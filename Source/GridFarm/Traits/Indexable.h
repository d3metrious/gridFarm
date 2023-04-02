#pragma once

#include "CoreMinimal.h"
#include "Indexable.generated.h"

USTRUCT(BlueprintType)
struct GRIDFARM_API FIndexable {

	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Index = 0;

	FIndexable(){}

	FIndexable(const int &value) 
		: Index(value)
	{}


};
