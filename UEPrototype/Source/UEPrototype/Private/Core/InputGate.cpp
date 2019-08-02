// Fill out your copyright notice in the Description page of Project Settings.

#include "InputGate.h"



UInputGate::UInputGate()
{
	bInputBlocked = false;
}



void UInputGate::ToggleInputBlock()
{
	bInputBlocked = !bInputBlocked;
}



void UInputGate::SetInputBlocked(bool bNeedBlock)
{
	bInputBlocked = bNeedBlock;
}