/*
 * Copyright © 2022, Medelfor, Limited. All rights reserved.
 * For any additional information refer to https://medelfor.com
 */

#include "Jetpack.h"
#include "Modules/ModuleManager.h"
#include "Net/UnrealNetwork.h"

TArray<TScriptInterface<IJetpackExtension>> AJetpack::GetExtensions() const
{
	return {};
}

EJetpackState AJetpack::GetState() const
{
	return State;
}

void AJetpack::OnStarted_Implementation(TArray<TScriptInterface<IJetpackExtension>>& Extensions)
{

}

void AJetpack::OnRep_Fuel(float NewFuel)
{

}

void AJetpack::SetJetpackEnabled(bool IsEnabled)
{

}

void AJetpack::BlowItUp_Implementation(float ExplosionSize)
{

}

bool AJetpack::BlowItUp_Validate(float ExplosionSize)
{
	return false;
}

void AJetpack::SetState(EJetpackState NewState)
{

}

void AJetpack::Extend(TScriptInterface<IJetpackExtension> Extension,
	int32 Priority, int32 StartingSequence)
{

}

void AJetpack::GetLifetimeReplicatedProps(
  TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION(AJetpack, RemainingFuel, COND_SimulatedOrPhysics)
	DOREPLIFETIME(AJetpack, State)
}

IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, Jetpack, "Jetpack");
