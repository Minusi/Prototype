// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "Math/Color.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "UObject/Package.h"
#include "MinusiFrameworkLibrary.generated.h"


UENUM(BlueprintType)
enum class EBoolean : uint8
{
	T			UMETA(DisplayName = "True"),
	F			UMETA(DisplayName = "False")
};


/*
 *	게임프레임워크에서 제공하지 않는 기능들을 확장하여 유틸성을 제공하는 라이브러리 클래스입니다.
 */
UCLASS(ClassGroup = Minusi)
class UEPROTOTYPE_API UMinusiFrameworkLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:

	// 대상 액터와 UClass를 비교한 결과를 반환합니다.
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Minusi", meta = (DisplayName = "IsTypeofActor", Keywords = "==Actor"))
	static bool IsTypeofActor(AActor const * Actor, AActor const * Compare);

	// 대상 액터와 UClass를 비교한 결과를 Exec 출력으로 반환합니다.
	UFUNCTION(BlueprintCallable, Category = "Minusi", meta = (DisplayName = "IsTypeofActor", Keywords = "==Actor", ExpandEnumAsExecs = Execs))
	static void IsTypeofActor_Exec(AActor const * Actor, AActor const * Compare, EBoolean& Execs);

	// 대상 언리얼 오브젝트와 UClass를 비교한 결과를 반환합니다.
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Minusi", meta = (DisplayName = "IsTypeofObject", Keywords = "==Object"))
	static bool IsTypeofObject(UObject const * Object, UObject const * Compare);

	// 대상 언리얼 오브젝트와 UClass를 비교한 결과를 Exec 출력으로 반환합니다.
	UFUNCTION(BlueprintCallable, Category = "Minusi", meta = (DisplayName = "IsTypeofObject", Keywords = "==Object", ExpandEnumAsExecs = Execs))
	static void IsTypeofObject_Exec(UObject const * Object, UObject const * Compare, EBoolean& Execs);

	// 대상 언리얼 오브젝트와 UClass를 비교한 결과를 반환합니다.
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Minusi", meta = (DisplayName = "IsTypeofClass", Keywords = "==Class"))
	static bool IsTypeofClass(UObject const * Object, TSubclassOf<UObject> const Compare);

	// 대상 언리얼 오브젝트와 UClass를 비교한 결과를 Exec 출력으로 반환합니다.
	UFUNCTION(BlueprintCallable, Category = "Minusi", meta = (DisplayName = "IsTypeofClass", Keywords = "==Class", ExpandEnumAsExecs = Execs))
	static void IsTypeofClass_Exec(UObject const * Object, TSubclassOf<UObject> const Compare, EBoolean& Execs);





	// Print String의 간소화된 로그 버전입니다. 2초간 지속됩니다.
	UFUNCTION(BlueprintCallable, Category = "Minusi", meta = (Keywords = "SLog"))
	static void ScreenShortLog(FString const Message, FColor const Color = FColor(243, 156, 18));

	// Print String의 간소화된 로그 버전입니다. 5초간 지속됩니다.
	UFUNCTION(BlueprintCallable, Category = "Minusi", meta = (Keywords = "Log"))
	static void ScreenLog(FString const Message, FColor const Color = FColor(243, 156, 18));

	// Print String의 간소화된 로그 버전입니다. 10초간 지속됩니다.
	UFUNCTION(BlueprintCallable, Category = "Minusi", meta = (Keywords = "LLog"))
	static void ScreenLongLog(FString const Message, FColor const Color = FColor(243, 156, 18));





	// 특정 타입의 첫 번째 액터를 반환합니다. 이후 형변환을 수행하여 특정 타입으로 변환할 수 있습니다.
	UFUNCTION(BlueprintCallable, Category = "Minusi", meta = (WorldContext = "WorldContextObject", Keywords = "GetTag", DeterminesOutputType = "ActorToFind"))
	static AActor* GetSpecificFirstActorWithTag(const class UObject* WorldContextObject, FName Tag, TSubclassOf<AActor> ActorToFind);

	// 특정 타입의 모든 액터를 반환합니다. 이후 형변환을 수행하여 특정 타입으로 변환할 수 있습니다.
	UFUNCTION(BlueprintCallable, Category = "Minusi", meta = (WorldContext = "WorldContextObject", Keywords = "GetTag", DeterminesOutputType = "ActorToFind"))
	static TArray<AActor*> GetSpecificAllActorWithTag(const class UObject* WorldContextObject, FName Tag, TSubclassOf<AActor> ActorToFind);


	// 외적을 사용하여 두 백터 사이의 각도를 구함
	UFUNCTION(BlueprintPure, Category = "Minusi|Math")
	static void GetAngleBetweenTwoVector(FVector2D A, FVector2D B, float& Angle);

	// 두 엑터간의 거리를 일차원 함수의 변수로 넣어 반환
	UFUNCTION(BlueprintPure, Category = "Minusi|Math")
	static float DistanceRatioByOneDimensionalFunction(AActor* StartActor, AActor* EndActor, float  RatioMul, float RatioPlus, float MinSize, float MaxSize);

	// 스냅 간격을 기준으로 스냅 가능 여부, 스냅 비율 반환
	UFUNCTION(BlueprintPure, Category = "Minusi|Math")
	static void Snap(float Delta, float SnapInterval, bool& bCanSnap, float& SnappedDelta);

	// 라인 트레이스의 결과값으로 맞은 물체와 특정 위치까지의 트랜스폼(위치, 각도) 반환
	UFUNCTION(BlueprintPure, Category = "Minusi|Trace")
	static FTransform GetTransformToTraceHitResult(FHitResult HitResult, bool IsHit, FVector ActorLocation);

	// 원점과 방향을 화면상에 각각 사영시켜 원점에서 부터의 단위 방향 벡터를 구함
	UFUNCTION(BlueprintPure, Category = "Minusi|Math")
	static void ProjectWorldDirectionToScreenFromOrigin(class APlayerController* PC, FVector InDirection, FVector2D& ProjectedUnitDirectionToScreen);

	// 오브젝트 타입으로 루트에서 부터 에셋 데이터를 조사하여 반환
	UFUNCTION(BlueprintPure, Category = "Minusi|Loader")
	static TArray<struct FAssetData> GetAssetDataByObjectType(TSubclassOf<UObject> ObjectType);


	UFUNCTION(BlueprintCallable, Category = "Minusi|Debug")
	static void GetInfoWithOuterChain(const UObject* Object);


	/* 오브젝트 이름 및 유니크 ID, 오브젝트 플래그와 Outer를 출력합니다 */
	UFUNCTION(BlueprintCallable, Category = "Minudi|UObject")
	static void GetInfo(const UObject* Object);

};