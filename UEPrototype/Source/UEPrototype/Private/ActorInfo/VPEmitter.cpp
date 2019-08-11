// Fill out your copyright notice in the Description page of Project Settings.

#include "VPEmitter.h"
#include <Particles/ParticleSystemComponent.h>
#include <Particles/ParticleEmitter.h>

//파티클 컴포넌트 부착, 초기 트랜스폼, 부모가 있는지에 대한 Init
void AVPEmitter::InitEmitter(UParticleSystem* ParticleSystem, FTransform Transform, AActor* Parent = nullptr)
{
	if (ParticleSystem == nullptr) return;

	//캐싱
	CachedParticleSystem = GetParticleSystemComponent();
	//Emitter Actor에 장착될 ParticleSystem
	CachedParticleSystem->Template = ParticleSystem;
	
	//파티클 액터가 다른 액터의 자식일 떄 상대적인 Transform을 적용
	if (Parent != nullptr)
	{	
		SetActorLabel(EmitterLableName);
		SetActorLocation(Parent->GetActorLocation());
		AttachToActor(Parent, FAttachmentTransformRules::KeepWorldTransform);
	}
	else
	{
		SetActorTransform(Transform);
	}

	
	//파티클은 생성될 때 활성화가 off이므로 on으로 바꿔줌
	//Activate();
	
}
//파티클의 파라미터들을 Set 해주는 함수
void AVPEmitter::SettingEmitter(const FEmitterParam EmitterParam, const FTransform RelativeTrasnform)
{
	
	
	//Initialize size의 distribution을 Particle Param으로 바꾸고, 이름을 InitParticleSize로 바꿔야함
	//ParamMode를 DPM Direct로 바꾸고 vector의 값을 파티클이 가질 수 있는 최대값으로 설정해라.
	//파티클 파라미터 설정
	{
		CachedParticleSystem->SetVectorParameter("InitParticleSize", EmitterParam.InitParticleSize);
		CachedParticleSystem->SetFloatParameter("Lifetime", EmitterParam.Lifetime);
		CachedParticleSystem->SetFloatParameter("SpawnRate", EmitterParam.SpawnRate);
		CachedParticleSystem->SetFloatParameter("SpawnRateScale", EmitterParam.SpawnRateScale);
		CachedParticleSystem->SetColorParameter("Color", EmitterParam.Color);
		CachedParticleSystem->SetFloatParameter("Alpah", EmitterParam.Alpah);
	}
	
	//이미터에 대한 상대적인 Trasnform 설정. 나중에 기즈모로 의해 조정되어야함.
	CachedParticleSystem->SetRelativeTransform(RelativeTrasnform);
	
	//파티클이 무한정 생성되는게아니라 일정 주기의 딜레이를 가지고 생성됩니다.
	CachedParticleSystem->EmitterDelay = EmitterParam.EmitterDelay;
}

void AVPEmitter::ActivateEmitter()
{
	CachedParticleSystem->Activate();
	Activate();

}

void AVPEmitter::DeActivateEmitter()
{
	CachedParticleSystem->Deactivate();
}



