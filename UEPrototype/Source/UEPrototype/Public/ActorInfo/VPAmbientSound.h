

#pragma once

#include "CoreMinimal.h"
#include "Sound/AmbientSound.h"
#include <Components/AudioComponent.h>
#include <Sound/SoundAttenuation.h>
#include "VPAmbientSound.generated.h"

class UAudioComponent;


//기존의 EAttenuationDistanceModel에서 Custom할 수 있는 것들을 다시 enum으로 재생성한 것.
UENUM(BlueprintType)
enum  class ECustomAttenuationDistanceModel : uint8
{
	LINEAR					UMETA(DisplayName = "Linear"),
	LOGARITHMIC				UMETA(DisplayName = "Logarithmic"),
	INVERSE					UMETA(DisplayName = "Inverse"),
	LOGREVERSE				UMETA(DisplayName = "LogReverse"),
	NATURALSOUND			UMETA(DisplayName = "NaturalSound"),
	//주석친것들은 사용자가 컨트롤하기 어려운부분이고, 다른 enum값과 다르게 상태에따른 변수들이 달라지므로 패스
	
	//Custom,
};



//나중에 widget을 통해 사용자 인터페이스에서 원하는 설정들을 집어 넣어주기위한 Sound 구조체
USTRUCT(BlueprintType)
struct FSoundProperty 
{
	GENERATED_BODY()

public:
	//이 Actor에 넣어 줄 Sound
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	USoundBase* Sound;
	//이 Actor를 UISound로 만들 것인가?(도중에 목록창이나 메뉴창을 봐도 계속 흘러나오는 음악)
	//내 생각으로는 멀티플레이를 감안하면 무조건 on시키는게 맞다고 봄, 내가 동작을 안해도 흘러가야하니
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	bool bUISound;
	//이 Actor가 생성시(우리는 동적 생성이니 Play실행시) 음악이 바로 재생되는지에 대한 여부
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	bool bAutoActivate;
	//마스터 볼륨, 전체적인 볼륨에대한 컨트롤, default로 1을 넣어준다
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	float VolumeMultiplier;
	//마스터 피처, 전체적인 피처에대한 컨트롤, default로 1을 넣어준다.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	float PitchMultiplier;
	//fallout거리를 벗어나게되면 음악이 자동으로 정지가되는데 이 변수가 true이면
	//fallout거리를 벗어나더라도 음악이 계속 실행된다.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	bool bAlwaysPlay;
	//반복여부에 대한 설정
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	bool bLooping;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	bool bIsPaused;
};

//나중에 widget을 통해 사용자 인터페이스에서 원하는 설정들을 집어 넣어주기위한 Attenuation(감쇠) 구조체
USTRUCT(BlueprintType)
struct FAttenuationProperty
{
	GENERATED_BODY()

public:
	// 주석친 것들은 내부적으로 처리해야하므로 외부에서 설정못하게 함.
	//bool bAllowSpatialization;
	//bool bOverrideAttenuation;
	//bool bSpatialization;
	//ESoundSpatializationAlgorithm SoundSpatializationAlgorithm; //Panning
	//float NonSpatializedRadius; //0.0
	//float 3dStereoSpread; //200.0
	//bool bNomalize3dStereoSound; //false
	//bool EnableVolumeAttenuation;

	//멀어질수록 선형으로 볼륨이작아지는가,로그형식을따르는가,역로그를 따르는가에 대한 enum
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	ECustomAttenuationDistanceModel AttenuationDistanceModel;
	//감쇠에 대한 모양에 대한 enum(blueprint에서 사용하기위해 TEnumAsByte를 사용했음.이미 정의된 구조체라
	//이런 방식을 도입, default는 구체형태로 감쇠
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	TEnumAsByte<EAttenuationShape::Type> AttenuationShape;
	//감쇠효과 최대 거리로 생각
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	float FalloffDistance;
	//음원으로부터 어느정도 떨어진 거리부터 감쇠효과를 받을것인가에 대한 변수
	//반대로 이 반경 내에서는 감쇠효과를 받지않고 똑같은 볼륨이 적용됨
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPAmbientSound")
	float DecreaseRadius;

};

USTRUCT(BlueprintType)
struct FModulationProperty
{
	GENERATED_BODY()
public:
	//Modulation은 딱히 User가 건드릴 일 없음.
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
	//Widget에서 사운드를 만들어 낼 때 호출되야하는 함수, 사용자가 설정된 값을 통해 사운드를 생성하는 함수
	UFUNCTION(BlueprintCallable,Category = "VPAmbientSound")
	void InitSound(AActor* Actor, FSoundProperty SoundProperty,  FAttenuationProperty AttenuationProperty);
	
	//AAmbientSound에 구현되어 있는 함수들, Blueprint 테스트용으로 만들어놓음. 나중에 제거해도 상관없음

	UFUNCTION(BlueprintCallable, Category = "VPAmbientSound")
	UAudioComponent* GetCustomAudioComponent() const;

	//loop event에 맞는 매개변수의 함수를 만들려고 일부러 생성한것.
	UFUNCTION(BlueprintCallable, Category = "VPAmbientSound")
	void PlayNormal();

	
	//Level Blueprint 상에서는 확인할 수 없음. 따라서 커스텀 Function을 만들어서 확인을했다.
	//코드상으로는 확인할 수 있으니 나중에 UI와 관련해서 사용되길 권장함.
	UFUNCTION(BlueprintCallable, Category = "VPAmbientSound")
	static bool CheckIsUniqueSound(const AActor* Actor);

private:
	//생성된 Actor의 자식으로 들어갈 때 자신을 식별하기위한 이름.
	const FString SoundLabelName = "AmbientSound";
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPAmbientSound", meta = (AllowPrivateAccess = "true"))
	UAudioComponent* myAudioComponent;
};
