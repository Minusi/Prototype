// Fill out your copyright notice in the Description page of Project Settings.

#include "Command/CommandBase.h"
#include "UEPrototype.h"



void UCommandBase::ExecuteIf()
{
	VP_LOG(Warning, TEXT("구현되지 않았습니다. 서브 클래스에서 구현해야 합니다"));
	return;
}





void UCommandBase::Undo()
{
	VP_LOG(Warning, TEXT("구현되지 않았습니다. 서브 클래스에서 구현해야 합니다."));
	return;
}
