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

	/* 외부에서 선택된 액터에 대해서 윤곽선을 그려주는 함수입니다.
	 * 참고로 윤곽선을 그리는 방식은 선택된 액터를 하나 더 복제해
	 * 조정된 material을 입혀 윤곽선 효과를 냅니다. */

	 /* 윤곽선이 그려진 특정 Actor의 윤곽선을 지워줍니다 */

	
	void ClearFocusedOutline();
	void AddFocusedOutline(AActor* Actor, TCHAR* OutlinePath = TEXT("/Game/Material/MI_Outliner"));
	void DrawHighlightedOutline(AActor* Actor, TCHAR* OutlinePath = TEXT("/Game/Material/MI_Outliner"));
	void ClearHighlightedOutline();
	void AddHighlightedOutline(AActor* Actor, TCHAR* OutlinePath = TEXT("/Game/Material/MI_Outliner"));
	void AddHighlightedOutline(TSet<AActor*> & Actors);
	void RemoveHighlightedOutline(TSet<AActor*> & Actors);
	void RemoveHighlightedOutline(AActor* Actor);

	AActor* GetFocusedOutlines() { return OutlineFocusedActor; }
	TSet<AActor*> GetHighlightOutlines() { return OutlineHighlightActors; }

	// label -> tag 이 변수는 static으로 선언을 한다. ,

private:

	//Tag로 찾자
	FName OutlinerLabelName = "OutLiner";

	TCHAR* OutlinePath = TEXT("/Game/Material/MI_Outliner_2");
	TCHAR* HighlightPath;

	AActor* OutlineFocusedActor;
	TSet<AActor*> OutlineHighlightActors;
};
