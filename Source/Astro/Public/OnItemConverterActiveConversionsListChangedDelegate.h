#pragma once
#include "CoreMinimal.h"
#include "ActiveItemConversionProgress.h"
#include "OnItemConverterActiveConversionsListChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemConverterActiveConversionsListChanged, const TArray<FActiveItemConversionProgress>&, newActiveConversions);

