// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Outliner.generated.h"


class AActor;

//UObject를 Blueprint에서 생성하기위해 UCLASS(Blueprintable,BlueprintType)을 사용
//이 class는 외부에서 지정된 Actor에대해 윤곽선을 그려주거나 제거하는 역할을 한다.
UCLASS(Blueprintable, BlueprintType)
class UEPROTOTYPE_API UOutliner : public UObject
{
	GENERATED_BODY()
public:
	UOutliner();
public:
	//마지막으로 선택되었던 Actor를 반환하는 함수
	FORCEINLINE AActor* GetLastOutlinedActor()const { return LastOutlinedActor; }

	//외부에서 선택된 액터에 대해서 윤곽선을 그려주는 함수
	//참고로 윤곽선을 그리는 방식은 선택된 액터를 하나 더 복제해 조정된 material을 입혀 윤곽선효과를 내는것
	UFUNCTION(BlueprintCallable, Category = "Outliner")
		void DrawActorOutline(const AActor* Actor);

	//윤곽선이 그려진 특정 Actor의 윤곽선을 지워준는 함수
	UFUNCTION(BlueprintCallable, Category = "Outliner")
		void EraseActorOutline();




private:

	//마지막으로 윤곽선이 그려진 Actor의 레퍼런스를 가지는 변수이다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Outliner", meta = (AllowPrivateAccess = "true"))
		AActor* LastOutlinedActor;


	//윤곽선 제거를 위해 해당 Actor의 자식 Actor중 LableName이 "OutLiner"인 것들을 찾아서
	//"OutLiner"를 가지고 있다면 제거하는 방식을 사용하는데, "OutLiner"가 이곳저곳에서 중복적으로 사용되어
	//하나의 변수로만들어 사용하는것.
	const FString OutlinerLabelName = "OutLiner";

};
