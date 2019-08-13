// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "MaterialCommand.generated.h"

class UActorConstraintMarker;
class UVPMaterial;
class AActor;


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

	UFUNCTION(BlueprintCallable,Category = "Command")
	void SetParamsVector(UStaticMeshComponent* Actor, FVector Vector, FName Name);
	UFUNCTION(BlueprintCallable, Category = "Command")
	void SetParamsTexture(UStaticMeshComponent* Actor, UTexture2D* Texture, FName Name);
	UFUNCTION(BlueprintCallable, Category = "Command")
	void SetParamsColor(UStaticMeshComponent* Actor, FLinearColor Color, FName Name);
	UFUNCTION(BlueprintCallable, Category = "Command")
	void SetParamsScalar(UStaticMeshComponent* Actor, float Value, FName Name);

private:
	/* 하이라이트로 표시할 마커입니다 */
	static UActorConstraintMarker* ActorConstraintMarker;

	
	static UVPMaterial* VPMaterial;

	FParamType ParamType;
};
