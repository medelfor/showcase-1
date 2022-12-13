/*
 * Copyright © 2022, Medelfor, Limited. All rights reserved.
 * For any additional information refer to https://medelfor.com
 */

#include "BaseJetpackExtension.h"

EJetpackExtension::Type ABaseJetpackExtension::GetType()
{
  return EJetpackExtension::Type::MOVEMENT;
}

void ABaseJetpackExtension::OnJetpackStateChanged_Implementation()
{

}

void ABaseJetpackExtension::OnTick_Implementation(float DeltaTime)
{

}

int32 ABaseJetpackExtension::SubInitialize(FTransform InitialTransform)
{
	return 0;
}

void ABaseJetpackExtension::Initialize(FTransform InitialTransform,
	int32 StatusCode)
{

}
