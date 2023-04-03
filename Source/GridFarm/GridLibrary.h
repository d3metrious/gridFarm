#pragma once

#include "CoreMinimal.h"
#include "GridLibrary.generated.h"

UCLASS()
class GRIDFARM_API UGridLibrary : public UObject
{
	GENERATED_BODY()

public:

	static FORCEINLINE bool IsValid(AActor* Actor) {
		if (!Actor) return false;
		if (!Actor->IsValidLowLevel()) return false;
		return true;
	}
	template <typename T>
	static int GetRandomIndexFromArray(TArray<T> Array);


};

template <typename T>
int UGridLibrary::GetRandomIndexFromArray(TArray<T> Array)
{
	if(Array.IsEmpty()) return -1;
	return FMath::RandRange(0, Array.Num() -1 );
}

