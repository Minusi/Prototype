// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Particles/Emitter.h"
#include "VPEmitter.generated.h"


//주요 파라미터값에 대한 구조체
USTRUCT(BlueprintType)
struct FEmitterParam 
{
	GENERATED_BODY()
public:
	//파티클의 크기
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPEmitter")
	FVector InitParticleSize;
	//파티클들의 스폰률
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPEmitter")
	float SpawnRate;
	//파티클들의 스폰 크기
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPEmitter")
	float SpawnRateScale;
	//파티클의 색상
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPEmitter")
	FColor Color;
	//파티클의 알파값
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPEmitter")
	float Alpah;
	//파티클의 생명주기
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPEmitter")
	float Lifetime;
	//파티클의 생성에대한 딜레이
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPEmitter")
	float EmitterDelay;
};

UCLASS()
class UEPROTOTYPE_API AVPEmitter : public AEmitter
{
	GENERATED_BODY()
	
public:
	AVPEmitter();
	/* UOutliner를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "ActorInfo", meta = (UnsafeDuringActorConstruction = "true"))
	static AVPEmitter* GetGlobalEmitter();





	//생성된 이미터액터의 초기화
	UFUNCTION(BlueprintCallable,Category = "VPEmitter")
	void InitEmitter(UParticleSystem* ParticleSystem, FTransform Transform ,AActor* Parent);

	//사용자가 파라미터를 조정하도록 해주는 함수
	UFUNCTION(BlueprintCallable, Category = "VPEmitter")
	void SettingEmitter(const FEmitterParam EmitterParam , const FTransform RelativeTrasnform);

	

	//TODO : 영상 처리용 편집 함수들. 나중에 쓸모없어지면 삭제 바람.
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetEmitterVectorParam(UParticleSystemComponent* Target, FVector Vector, FName Name);
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetEmitterLinearColor(UParticleSystemComponent* Target, FLinearColor Color, FName Name);
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetEmitterScalarParam(UParticleSystemComponent* Target, float Value, FName Name);

	//명령을 위해 만들어둠. Emitter를 활성화시킨다.
	UFUNCTION(BlueprintCallable, Category = "VPEmitter")
	void ActivateEmitter();

	UFUNCTION(BlueprintCallable, Category = "VPEmitter")
	void DeActivateEmitter();

	//파티클시스템 컴포넌트 캐싱
	UFUNCTION(BlueprintCallable, Category = "VPEmitter")
	UParticleSystemComponent* GetCachedParticleSystem()const { return CachedParticleSystem; }

	
	
	
private:
	UPROPERTY()
	UParticleSystemComponent* CachedParticleSystem;

	const FString EmitterLableName = "VPEmitter";
};
