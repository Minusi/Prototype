// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "MaterialCommand.generated.h"

class UActorConstraintMarker;
class UVPMaterial;



enum class FParamType : uint8
{
	VECTOR,
	COLOR,
	TEXTURE,
};

UCLASS()
class UEPROTOTYPE_API UMaterialCommand : public UActorCommandBase
{
	GENERATED_BODY()
public:
	/* 생성자 */
	UMaterialCommand();

	/* UCommandBase로부터 상속됨 */

	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;

public:
	void SetParamVector(AActor* Target, FVector Vector, FName Name);

	void SetParamTexture(AActor* Target, UTexture2D* Texture, FName Name);

	void SetParamColor(AActor* Target, FLinearColor Color, FName Name);

private:
	/* 하이라이트로 표시할 마커입니다 */
	static UActorConstraintMarker* ActorConstraintMarker;

	UPROPERTY()
	UVPMaterial* VPMaterial;

	FParamType ParamType;
};
