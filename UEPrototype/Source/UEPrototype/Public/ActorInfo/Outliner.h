// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Outliner.generated.h"


class AActor;

//UObject�� Blueprint���� �����ϱ����� UCLASS(Blueprintable,BlueprintType)�� ���
//�� class�� �ܺο��� ������ Actor������ �������� �׷��ְų� �����ϴ� ������ �Ѵ�.
UCLASS(Blueprintable, BlueprintType)
class UEPROTOTYPE_API UOutliner : public UObject
{
	GENERATED_BODY()

public:
	//���������� ���õǾ��� Actor�� ��ȯ�ϴ� �Լ�
	FORCEINLINE AActor* GetLastOutlinedActor()const { return LastOutlinedActor; }

	//�ܺο��� ���õ� ���Ϳ� ���ؼ� �������� �׷��ִ� �Լ�
	//����� �������� �׸��� ����� ���õ� ���͸� �ϳ� �� ������ ������ material�� ���� ������ȿ���� ���°�
	UFUNCTION(BlueprintCallable, Category = "Outliner")
		void DrawActorOutline(AActor* Actor);

	//�������� �׷��� Ư�� Actor�� �������� �����ش� �Լ�
	UFUNCTION(BlueprintCallable, Category = "Outliner")
		void EraseActorOutline();




private:

	//���������� �������� �׷��� Actor�� ���۷����� ������ �����̴�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Outliner", meta = (AllowPrivateAccess = "true"))
		AActor* LastOutlinedActor;


	//������ ���Ÿ� ���� �ش� Actor�� �ڽ� Actor�� LableName�� "OutLiner"�� �͵��� ã�Ƽ�
	//"OutLiner"�� ������ �ִٸ� �����ϴ� ����� ����ϴµ�, "OutLiner"�� �̰��������� �ߺ������� ���Ǿ�
	//�ϳ��� �����θ���� ����ϴ°�.
	const FString OutlinerLabelName = "OutLiner";

};
