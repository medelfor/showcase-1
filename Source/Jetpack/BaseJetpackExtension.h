/*
 * Copyright © 2022, Medelfor, Limited. All rights reserved.
 * For any additional information refer to https://medelfor.com
 */

#pragma once

#include "JetpackExtension.h"
#include "BaseJetpackExtension.generated.h"

/**
 * Base extension offers empty and basic implementation of the methods from
 * @ref IJetpackExtension
 *
 * @see IJetpackExtension
 */
UCLASS(Blueprintable, BlueprintType)
class ABaseJetpackExtension : public AActor, public IJetpackExtension
{
	GENERATED_BODY()
public:
	/**
	 * @brief Performs initialization through sub-initialization
	 *
	 * Initializes this class internal properties and calls @ref SubInitialize
	 * so subclasses could also do something useful here. Note that
	 * @ref SubInitialize gets called only if `StatusCode` is zero.
	 *
	 * @param InitialTransform Transform of jetpack at the moment of attachment
	 * @param StatusCode Was there a failure when attaching the extension.
	 * Zero code means no failure
	 * @see SubInitialize
     * @see IJetpackExtension::Initialize
	 */
	void Initialize(FTransform InitialTransform, int32 StatusCode) override;

	/**
	 * Empty implementation
	 *
	 * @param DeltaTime Time (in seconds) passed from the last call
	 * @see IJetpackExtension::OnTick
	 */
	void OnTick_Implementation(float DeltaTime) override;

	/**
	 * Empty implementation
	 *
	 * @see IJetpackExtension::OnJetpackStateChanged
	 */
	void OnJetpackStateChanged_Implementation() override;

	/**
	 * Returns @ref EJetpackExtension::Type::MOVEMENT
	 *
	 * @return @ref EJetpackExtension::Type::MOVEMENT
	 * @see IJetpackExtension::GetType
	 */
	virtual EJetpackExtension::Type GetType() override;

protected:
	/**
	 * @brief Gives subclasses ability to perform initialization
	 *
	 * Gets called only if @ref Initialize was called with zero status code
	 *
	 * @param InitialTransform Transform of jetpack at the moment of attachment
	 * @return Zero if everything went successful, non-zero - otherwise
	 * @see Initialize
	 */
	virtual int32 SubInitialize(FTransform InitialTransform);
};
