// Fill out your copyright notice in the Description page of Project Settings.

#include "VPAmbientSound.h"
#include <Components/AudioComponent.h>
#include <Sound/SoundBase.h>
AVPAmbientSound::AVPAmbientSound() 
{
	myAudioComponent = GetAudioComponent();
	//Default Values
	myAudioComponent->VolumeMultiplier = 1.f;
	myAudioComponent->PitchMultiplier = 1.f;
	myAudioComponent->AttenuationOverrides.FalloffDistance = 3600.f;
	myAudioComponent->AttenuationOverrides.AttenuationShapeExtents
		= FVector(400.f, 0.0f, 0.0f);
}

void AVPAmbientSound::InitSound(AActor* Actor, FSoundProperty SoundProperty, FAttenuationProperty AttenuationProperty)
{
	

	//���忡 ���� Value ����
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
		
		
	//���迡 ����  Value ����

	{
		//����ȭ�� �� ���ΰ�(�ϴ� �����̱��ѵ� ����ڿ��� �Ѱ����� �ȳѰ����� �����غ�����)
		myAudioComponent->bAllowSpatialization = true;

		//���迡 ���� �Ķ���͸� ���� �����ϱ����� bool��
		myAudioComponent->bOverrideAttenuation = true;

		//3d���������� ����ȭ, true�� ���������.
		myAudioComponent->AttenuationOverrides
			.bApplyNormalizationToStereoSounds = true;

		//���׷��� ���� �Ÿ�, �ʹ� ��ȭ�۾��̹Ƿ� default���� �ھƵд�.
		myAudioComponent->AttenuationOverrides.StereoSpread = 200.0f;

		//����ȭ �˰���, �ʹ� ��ȭ�۾��̹Ƿ� default���� �ھƵд�.
		myAudioComponent->AttenuationOverrides.SpatializationAlgorithm =
			ESoundSpatializationAlgorithm::SPATIALIZATION_Default;

		//����ȭ ���뿡 ���� bool��(�ڷᰡ ����)
		myAudioComponent->AttenuationOverrides.bSpatialize = true;

		//2���������� ���� �ݰ�, 3������ ����� ���� 0���� ����
		myAudioComponent->AttenuationOverrides.OmniRadius = 0.0f;

		//Enable volume attenuation�� �ɷ� �����ϰ� ������(�ȵǸ� ã�ƺ���)
		myAudioComponent->AttenuationOverrides.bAttenuate = true;

		//����Ÿ��� ���� �˰��� ����
		myAudioComponent->AttenuationOverrides.DistanceAlgorithm
			= (EAttenuationDistanceModel)AttenuationProperty.AttenuationDistanceModel;

		//�׻� play�� ��Ű���� NaturalSound �˰����� ������ �����̵Ǿ���Ѵ�. ���� 
		//AlwaysPlay�� �����ٸ� ������ NaturalSound�� ����ǵ�����.(����ڿ��� NaturalSound�� �����������)
		if (SoundProperty.bAlwaysPlay)
		{
			myAudioComponent->AttenuationOverrides.DistanceAlgorithm = EAttenuationDistanceModel::NaturalSound;
			myAudioComponent->AttenuationOverrides.dBAttenuationAtMax = -60;
		}

		//���� ��翡 ���� ����
		myAudioComponent->AttenuationOverrides.AttenuationShape
			= AttenuationProperty.AttenuationShape;
		//���谡 ������(���� =0)�Ÿ��� ���� ����
		myAudioComponent->AttenuationOverrides.FalloffDistance
			= AttenuationProperty.FalloffDistance;
		//���谡 ����Ǵ� �Ÿ�, ���� X���� �ְ� ������������ ������.
		myAudioComponent->AttenuationOverrides.AttenuationShapeExtents
			= FVector(AttenuationProperty.DecreaseRadius, 0.0f, 0.0f);

		//���ιݰ��� ���谡 �����°Ÿ����� �ָ� ������ ȿ�� �����̾ȵ�. ���� ���ιݰ���
		//�ݵ�� falloffDistance���� ���� ���� �������Ѵ�.
		if (AttenuationProperty.FalloffDistance < AttenuationProperty.DecreaseRadius)
		{
			myAudioComponent->AttenuationOverrides.AttenuationShapeExtents =
				FVector(AttenuationProperty.FalloffDistance, 0.0f, 0.0f);	
		}
			
	}
		

		

	

	//������ ���� Value ����
		//������ ����ڰ� ���� �ǵ鿩�� �ʿ䰡 ���� ����.���߿� �ʿ信 ���� ����ü �ּ��� Ǯ�� �Ű�������
		//�޾ƿ� ����
	{
		myAudioComponent->PitchModulationMax = 1.0f;
		myAudioComponent->PitchModulationMin = 1.0f;
		myAudioComponent->VolumeModulationMax = 1.0f;
		myAudioComponent->VolumeModulationMin = 1.0f;
	}
	

	
	//�ش� Actor�� LableName�� �ۼ�
	this->SetActorLabel(SoundLabelName);

	//������ default location ���� �ٿ��� Actor�� location�� �̿��� ����
	this->SetActorLocation(Actor->GetActorLocation());

	//�ش� Actor�� �ٿ��� Actor�� ���̰� ������� Ʈ�������� ��������.
	this->AttachToActor(Actor, FAttachmentTransformRules::KeepWorldTransform);
	
	//������ ���ÿ� �����ϴ� ������ true��� �ٷ� �����Ų��.
	if (myAudioComponent->bAutoActivate)
		Play();
}
//���� Actor ����
void AVPAmbientSound::DestroySound()
{
	Destroy();
}

void AVPAmbientSound::PlayNormal()
{
	Play();
}



UAudioComponent * AVPAmbientSound::GetCustomAudioComponent() const
{
	return myAudioComponent;
}

//���� ���尡 �ش� ������ ���� Sound���ͷμ� �������� �����ϴ� �Լ�
//�� �Լ��� �ܺ�(�Ƹ��� UI���� �� ��)���� ����Ͽ� �����ؾ���.
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



