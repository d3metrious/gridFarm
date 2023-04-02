#pragma once

#include "CoreMinimal.h"
#include "Enums.generated.h"

UENUM(BlueprintType)
enum SoilState {
	Unpurchased UMETA(DisplayName = "Unpurchased"),
	Raw UMETA(DisplayName = "Raw"),
	Tilled UMETA(DisplayName = "Tilled"),
	Planted UMETA(DisplayName = "Planted"),
	Harvested UMETA(DisplayName = "Harvested")
};