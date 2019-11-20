// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicParameterParser.h"
#include "UEPrototype.h"
#include "ActorInfo/VPEmitter.h"
#include "ActorInfo/VPEmitter.h"

#include "Materials/MaterialInstance.h"

#include "Particles/Emitter.h"
#include <Particles/ParticleSystemComponent.h>
#include <Particles/ParticleEmitter.h>

UDynamicParameterParser::UDynamicParameterParser()
{
}

void UDynamicParameterParser::ParseMaterial(const UMaterialInstance * MaterialInstance,
	FDynamicParamList & DynamicParamList)
{
	if (IsValid(MaterialInstance) == false)
	{
		VP_LOG(Warning, TEXT("MaterialInstance가 존재하지 않습니다"));
		return;
	}

	/* 
	   Scalar , LinearColor , Texture을 Map에 Parsing
	   사용자는 변경하고 싶은 부분에 대해서 반드시 Edit창의 Parameter 값을 수정할 수 있도록
	   해주는 체크박스를 체크 해야함.
	   Vector와 LinearColor가 같이 벡터로 취급되서 그런지 Vector부분을 따로 만들어두지않은듯.
	*/
	for (const auto & it : MaterialInstance->ScalarParameterValues)
	{
		DynamicParamList.NameScalarMap.Add(it.ParameterInfo.Name, it.ParameterValue);	
		VP_LOG(Warning, TEXT("Parsing된 Scalar Name : %s"), *it.ParameterInfo.Name.ToString());
	}
	for (const auto & it : MaterialInstance->VectorParameterValues)
	{
		DynamicParamList.NameColorMap.Add(it.ParameterInfo.Name, it.ParameterValue);
		VP_LOG(Warning, TEXT("Parsing된 Color Name : %s"), *it.ParameterInfo.Name.ToString());
	}
	for (const auto & it : MaterialInstance->TextureParameterValues)
	{
		DynamicParamList.NameTextureMap.Add(it.ParameterInfo.Name, (UTexture2D*)it.ParameterValue);
		VP_LOG(Warning, TEXT("Parsing된 texture Name : %s"), *it.ParameterInfo.Name.ToString());
	}




	
}

void UDynamicParameterParser::ParseParticleSystem( const UParticleSystemComponent* ParticleSystemComp, FDynamicParamList & DynamicParamList)
{
	if (IsValid(ParticleSystemComp) == false)
	{
		VP_LOG(Warning, TEXT("ParticleSystemComp가 존재하지 않습니다."));
		return;
	}
	
	/* InstanceParameters는 Emitter에 붙어있는 Particles의 InstanceParmeters를 의미한다.
	   InstanceParmeter는 Particle Edit창의 바꾸고 싶은 파라미터의 이름을 대입한 후
	   값을 설정하면 된다. MaterialParameter처럼 모든 Parameter를 순회할 수 없다.(key-value로는
	   찾을 수 있음).따라서 미리 InstanceParameters에 미리 설정해두어야한다.
	*/

	for (const auto & it : ParticleSystemComp->InstanceParameters)
	{
		
		if (it.ParamType == EParticleSysParamType::PSPT_Scalar)
		{
			DynamicParamList.NameScalarMap.Add(it.Name, it.Scalar);
		}
		else if (it.ParamType == EParticleSysParamType::PSPT_Vector)
		{
			DynamicParamList.NameVectorMap.Add(it.Name, it.Vector);
		}
		else if (it.ParamType == EParticleSysParamType::PSPT_Color)
		{
			DynamicParamList.NameColorMap.Add(it.Name, it.Color);
		}
		
		VP_LOG(Warning, TEXT("Parsing된 Parameter Name : %s"), *it.Name.ToString());
	}
	

}