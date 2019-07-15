// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoAxis.h"

void UGizmoAxis::UpdateGizmoTransType(EGizmoTransType InTransType)
{
	if (TransType != InTransType)
	{
		TransType = InTransType;
		if (TransTypeMeshs.Contains(InTransType))
		{
			UStaticMesh* Mesh = TransTypeMeshs[InTransType];
			if(Mesh != NULL)
				this->SetStaticMesh(Mesh);
		}
	}
	Super::UpdateGizmoTransType(InTransType);
}