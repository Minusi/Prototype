// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sound/AmbientSound.h"
#include <Components/AudioComponent.h>
#include <Sound/SoundAttenuation.h>
#include "VPAmbientSound.generated.h"

class UAudioComponent;


//������ EAttenuationDistanceModel���� Custom�� �� �ִ� �͵��� �ٽ� enum���� ������� ��.
UENUM(BlueprintType)
enum  class ECustomAttenuationDistanceModel : uint8
{
	LINEAR					UMETA(DisplayName = "Linear"),
	LOGARITHMIC				UMETA(DisplayName = "Logarithmic"),
	INVERSE					UMETA(DisplayName = "Inverse"),
	LOGREVERSE				UMETA(DisplayName = "LogReverse"),
	NATURALSOUND			UMETA(DisplayName = "NaturalSound"),
	//�ּ�ģ�͵��� ����ڰ� ��Ʈ���ϱ� �����κ��̰�, �ٸ� enum���� �ٸ��� ���¿����� �������� �޶����Ƿ� �н�
	
	//Custom,
};



//���߿� widget�� ���� ����� �������̽����� ���ϴ� �������� ���� �־��ֱ����� Sound ����ü
USTRUCT(BlueprintType)
struct FSoundProperty 
{
	GENERATED_BODY()

public:
	//�� Actor�� �־� �� Sound
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	USoundBase* Sound;
	//�� Actor�� UISound�� ���� ���ΰ�?(���߿� ���â�̳� �޴�â�� ���� ��� �귯������ ����)
	//�� �������δ� ��Ƽ�÷��̸� �����ϸ� ������ on��Ű�°� �´ٰ� ��, ���� ������ ���ص� �귯�����ϴ�
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	bool bUISound;
	//�� Actor�� ������(�츮�� ���� �����̴� Play�����) ������ �ٷ� ����Ǵ����� ���� ����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	bool bAutoActivate;
	//������ ����, ��ü���� ���������� ��Ʈ��, default�� 1�� �־��ش�
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	float VolumeMultiplier;
	//������ ��ó, ��ü���� ��ó������ ��Ʈ��, default�� 1�� �־��ش�.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	float PitchMultiplier;
	//fallout�Ÿ��� ����ԵǸ� ������ �ڵ����� �������Ǵµ� �� ������ true�̸�
	//fallout�Ÿ��� ������� ������ ��� ����ȴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	bool bAlwaysPlay;
	//�ݺ����ο� ���� ����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	bool bLooping;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	bool bIsPaused;
};

//���߿� widget�� ���� ����� �������̽����� ���ϴ� �������� ���� �־��ֱ����� Attenuation(����) ����ü
USTRUCT(BlueprintType)
struct FAttenuationProperty
{
	GENERATED_BODY()

public:
	// �ּ�ģ �͵��� ���������� ó���ؾ��ϹǷ� �ܺο��� �������ϰ� ��.
	//bool bAllowSpatialization;
	//bool bOverrideAttenuation;
	//bool bSpatialization;
	//ESoundSpatializationAlgorithm SoundSpatializationAlgorithm; //Panning
	//float NonSpatializedRadius; //0.0
	//float 3dStereoSpread; //200.0
	//bool bNomalize3dStereoSound; //false
	//bool EnableVolumeAttenuation;

	//�־������� �������� �������۾����°�,�α������������°�,���α׸� �����°��� ���� enum
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	ECustomAttenuationDistanceModel AttenuationDistanceModel;
	//���迡 ���� ��翡 ���� enum(blueprint���� ����ϱ����� TEnumAsByte�� �������.�̹� ���ǵ� ����ü��
	//�̷� ����� ����, default�� ��ü���·� ����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	TEnumAsByte<EAttenuationShape::Type> AttenuationShape;
	//����ȿ�� �ִ� �Ÿ��� ����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	float FalloffDistance;
	//�������κ��� ������� ������ �Ÿ����� ����ȿ���� �������ΰ��� ���� ����
	//�ݴ�� �� �ݰ� �������� ����ȿ���� �����ʰ� �Ȱ��� ������ �����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	float DecreaseRadius;

};

USTRUCT(BlueprintType)
struct FModulationProperty
{
	GENERATED_BODY()
public:
	//Modulation�� ���� User�� �ǵ帱 �� ����.
	//float PitchModulationMin;
	//float PitchModulationMax;
	//float VolumeModulationMin;
	//float VolumeModulationMax;
};


UCLASS(Blueprintable, BlueprintType)
class UEPROTOTYPE_API AVPAmbientSound : public AAmbientSound
{
	GENERATED_BODY()
public:
	AVPAmbientSound();
public:
	//Widget���� ���带 ����� �� �� ȣ��Ǿ��ϴ� �Լ�, ����ڰ� ������ ���� ���� ���带 �����ϴ� �Լ�
	UFUNCTION(BlueprintCallable,Category = "VPAmbientSound")
	void InitSound(AActor* Actor, FSoundProperty SoundProperty,  FAttenuationProperty AttenuationProperty);
	//���带 �����ϴ� �Լ�
	UFUNCTION(BlueprintCallable, Category = "VPAmbientSound")
	void DestroySound();

	UFUNCTION(BlueprintCallable, Category = "VPAmbientSound")
	UAudioComponent* GetCustomAudioComponent() const;

	//loop event�� �´� �Ű������� �Լ��� ������� �Ϻη� �����Ѱ�.
	UFUNCTION(BlueprintCallable, Category = "VPAmbientSound")
	void PlayNormal();

	
	//Level Blueprint �󿡼��� Ȯ���� �� ����. ���� Ŀ���� Function�� ���� Ȯ�����ߴ�.
	//�ڵ�����δ� Ȯ���� �� ������ ���߿� UI�� �����ؼ� ���Ǳ� ������.
	UFUNCTION(BlueprintCallable, Category = "VPAmbientSound")
	static bool CheckIsUniqueSound(const AActor* Actor);


	

private:
	//������ Actor�� �ڽ����� �� �� �ڽ��� �ĺ��ϱ����� �̸�.
	const FString SoundLabelName = "AmbientSound";
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPAmbientSound", meta = (AllowPrivateAccess = "true"))
	UAudioComponent* myAudioComponent;
};
