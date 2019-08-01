// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Outliner.generated.h"



class AActor;



/*	UObject를 Blueprint에서 생성하기위해 UCLASS(Blueprintable,BlueprintType)을 사용
 *	이 클래스는 외부에서 지정된 Actor에 대해 윤곽선을 그려주거나 제거하는 역할을 수
 *	행합니다.
 */
UCLASS(Blueprintable, BlueprintType)
class UEPROTOTYPE_API UOutliner : public UObject
{
	GENERATED_BODY()

public:
	/* 생성자 */
	UOutliner();

	/* UOutliner를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "ActorInfo", meta = (UnsafeDuringActorConstruction = "true"))
	static UOutliner* GetGlobalOutliner();

	/* 마지막으로 선택되었던 Actor를 반환하는 함수 */
	FORCEINLINE AActor* GetLastOutlinedActor()const { return LastOutlinedActor; }

	/* 외부에서 선택된 액터에 대해서 윤곽선을 그려주는 함수입니다.
	 * 참고로 윤곽선을 그리는 방식은 선택된 액터를 하나 더 복제해 
	 * 조정된 material을 입혀 윤곽선 효과를 냅니다. */
	UFUNCTION(BlueprintCallable, Category = "Outliner")
		void DrawActorOutline(AActor* Actor);

	/* 윤곽선이 그려진 특정 Actor의 윤곽선을 지워줍니다 */
	UFUNCTION(BlueprintCallable, Category = "Outliner")
		void EraseActorOutline();



private:
	/*	월드 컨텍스트를 가지고 있는 CDO인지 여부를 판단합니다.
	이것을 수행하는 이유는 AEditorWorldManager의 구성 요소들만이 유효한
	프레임워크 플로우를 따를 수 있기 때문입니다. */
	UFUNCTION()
	bool ContainWorldContextCDO();




private:
	/* 마지막으로 윤곽선이 그려진 Actor입니다 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Outliner", meta = (AllowPrivateAccess = "true"))
		AActor* LastOutlinedActor;


	/* 윤곽선 제거를 위해 해당 Actor의 자식 Actor중 LableName이 "OutLiner"인 것들을 찾아서
	 * "OutLiner"를 가지고 있다면 제거하는 방식을 사용하는데, "OutLiner"가 이곳저곳에서 중복적으로 사용되어
	 * 하나의 변수로만들어 사용합니다 */
	const FString OutlinerLabelName = "OutLiner";

};
