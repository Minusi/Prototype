// Fill out your copyright notice in the Description page of Project Settings.

#include "TestProceduralActor.h"
#include "UEPrototype.h"

// Sets default values
ATestProceduralActor::ATestProceduralActor()
{
	VP_CTOR;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = Mesh;
	Mesh->bUseAsOccluder = true;
}

// Called when the game starts or when spawned
void ATestProceduralActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATestProceduralActor::PostActorCreated()
{
	Super::PostActorCreated();

	CreateTriangle();
}

void ATestProceduralActor::PostLoad()
{
	Super::PostLoad();

	CreateTriangle();
}

// Called every frame
void ATestProceduralActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestProceduralActor::CreateTriangle()
{
	TArray<FVector> Vertices;
	Vertices.Add(FVector(0, 0, 0));
	Vertices.Add(FVector(0, 100, 0));
	Vertices.Add(FVector(0, 0, 100));
	
	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	TArray<FVector> Normals;
	Normals.Add(FVector(1, 0, 0));
	Normals.Add(FVector(1, 0, 0));
	Normals.Add(FVector(1, 0, 0));

	TArray<FVector2D> UV0;
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));

	TArray<FProcMeshTangent> Tangents;
	Tangents.Add(FProcMeshTangent(0, 1, 0));
	Tangents.Add(FProcMeshTangent(0, 1, 0));
	Tangents.Add(FProcMeshTangent(0, 1, 0));

	TArray<FLinearColor> VertexColors;
	VertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	VertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	VertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	Mesh->CreateMeshSection_LinearColor
	(0, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, true);

	// Enable Collision Data
	Mesh->ContainsPhysicsTriMeshData(true);
}