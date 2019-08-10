// Fill out your copyright notice in the Description page of Project Settings.

#include "VPAmbientSound.h"
#include <Components/AudioComponent.h>
#include <Sound/SoundBase.h>
AVPAmbientSound::AVPAmbientSound() 
{
	myAudioComponent = GetAudioComponent();
	//Default Values
	myAudioComponent->VolumeMultiplier = 2.f;
	myAudioComponent->PitchMultiplier = 1.f;
	myAudioComponent->AttenuationOverrides.FalloffDistance = 3600.f;
	myAudioComponent->AttenuationOverrides.AttenuationShapeExtents
		= FVector(400.f, 0.0f, 0.0f);
}

void AVPAmbientSound::InitSound(AActor* Actor, FSoundProperty SoundProperty, FAttenuationProperty AttenuationProperty)
{
	

	//사운드에 관한 Value 설정
	{
		myAudioComponent->Sound = SoundProperty.Sound;
		myAudioComponent->bIsUISound = SoundProperty.bUISound;
		myAudioComponent->bAutoActivate = SoundProperty.bAutoActivate;
		myAudioComponent->VolumeMultiplier = SoundProperty.VolumeMultiplier;
		myAudioComponent->PitchMultiplier = SoundProperty.PitchMultiplier;
		myAudioComponent->bAlwaysPlay = SoundProperty.bAlwaysPlay;

		if (SoundProperty.bLooping)
		{
			myAudioComponent->OnAudioFinished.AddDynamic(this, &AVPAmbientSound::PlayNormal);
		}
	}
		
		
	//감쇠에 관한  Value 설정

	{
		//공간화를 할 것인가(일단 고정이긴한데 사용자에게 넘겨줄지 안넘겨줄지 생각해봐야함)
		myAudioComponent->bAllowSpatialization = true;

		//감쇠에 관한 파라미터를 따로 설정하기위한 bool값
		myAudioComponent->bOverrideAttenuation = true;

		//3d공간에대한 정규화, true로 맞춰놔야함.
		myAudioComponent->AttenuationOverrides
			.bApplyNormalizationToStereoSounds = true;

		//스테레오 사이 거리, 너무 심화작업이므로 default값을 박아둔다.
		myAudioComponent->AttenuationOverrides.StereoSpread = 200.0f;

		//공간화 알고리즘, 너무 심화작업이므로 default값을 박아둔다.
		myAudioComponent->AttenuationOverrides.SpatializationAlgorithm =
			ESoundSpatializationAlgorithm::SPATIALIZATION_Default;

		//공간화 적용에 대한 bool값(자료가 없음)
		myAudioComponent->AttenuationOverrides.bSpatialize = true;

		//2차원공간에 대한 반경, 3차원을 사용할 때는 0으로 고정
		myAudioComponent->AttenuationOverrides.OmniRadius = 0.0f;

		//Enable volume attenuation인 걸로 생각하고 설정함(안되면 찾아보자)
		myAudioComponent->AttenuationOverrides.bAttenuate = true;

		//감쇠거리에 관한 알고리즘 적용
		myAudioComponent->AttenuationOverrides.DistanceAlgorithm
			= (EAttenuationDistanceModel)AttenuationProperty.AttenuationDistanceModel;

		//항상 play를 시키려면 NaturalSound 알고리즘이 무조건 적용이되어야한다. 따라서 
		//AlwaysPlay가 켜졌다면 무조건 NaturalSound가 적용되도록함.(사용자에게 NaturalSound를 보여줄지고민)
		if (SoundProperty.bAlwaysPlay)
		{
			myAudioComponent->AttenuationOverrides.DistanceAlgorithm = EAttenuationDistanceModel::NaturalSound;
			myAudioComponent->AttenuationOverrides.dBAttenuationAtMax = -60;
		}

		//감쇠 모양에 대한 설정
		myAudioComponent->AttenuationOverrides.AttenuationShape
			= AttenuationProperty.AttenuationShape;
		//감쇠가 끝나는(볼륨 =0)거리에 대한 설정
		myAudioComponent->AttenuationOverrides.FalloffDistance
			= AttenuationProperty.FalloffDistance;
		//감쇠가 적용되는 거리, 보통 X값에 넣고 벡터형식으로 설정됨.
		myAudioComponent->AttenuationOverrides.AttenuationShapeExtents
			= FVector(AttenuationProperty.DecreaseRadius, 0.0f, 0.0f);

		//내부반경이 감쇠가 끝나는거리보다 멀리 있으면 효과 적용이안됨. 따라서 내부반경은
		//반드시 falloffDistance보다 작은 값을 가져야한다.
		if (AttenuationProperty.FalloffDistance < AttenuationProperty.DecreaseRadius)
		{
			myAudioComponent->AttenuationOverrides.AttenuationShapeExtents =
				FVector(AttenuationProperty.FalloffDistance, 0.0f, 0.0f);	
		}
			
	}
		

		

	

	//변조에 관한 Value 설정
		//변조는 사용자가 따로 건들여줄 필요가 없어 보임.나중에 필요에 따라 구조체 주석을 풀고 매개변수로
		//받아올 예정
	{
		myAudioComponent->PitchModulationMax = 1.0f;
		myAudioComponent->PitchModulationMin = 1.0f;
		myAudioComponent->VolumeModulationMax = 1.0f;
		myAudioComponent->VolumeModulationMin = 1.0f;
	}
	

	
	//해당 Actor의 LableName을 작성
	this->SetActorLabel(SoundLabelName);

	//사운드의 default location 값을 붙여질 Actor의 location을 이용해 설정
	this->SetActorLocation(Actor->GetActorLocation());

	//해당 Actor를 붙여질 Actor에 붙이고 상대적인 트랜스폼을 따르게함.
	this->AttachToActor(Actor, FAttachmentTransformRules::KeepWorldTransform);
	
	//생성과 동시에 실행하는 변수가 true라면 바로 실행시킨다.
	if (myAudioComponent->bAutoActivate)
		Play();
}
//사운드 Actor 제거
void AVPAmbientSound::DestroySound()
{
	Destroy();
}

//플레이 시작시간에 delay를 주지않고 바로 시작함.
void AVPAmbientSound::PlayNormal()
{
	Play();
}



UAudioComponent * AVPAmbientSound::GetCustomAudioComponent() const
{
	return myAudioComponent;
}

//현재 사운드가 해당 액터의 하위 Sound액터로서 유일한지 검증하는 함수
//이 함수는 외부(아마도 UI쪽이 될 듯)에서 사용하여 검증해야함.
bool AVPAmbientSound::CheckIsUniqueSound(const AActor* Actor)
{
	TArray<AActor*> ChildSound;
	Actor->GetAttachedActors(ChildSound);
	for (auto SoundIter = ChildSound.CreateConstIterator(); SoundIter;++SoundIter)
	{
		if ((*SoundIter)->GetActorLabel() == "AmbientSound") return false;
	}

	return true;
}



