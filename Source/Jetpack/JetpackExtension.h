/*
 * Copyright © 2022, Medelfor, Limited. All rights reserved.
 * For any additional information refer to https://medelfor.com
 */

#pragma once

#include "JetpackExtension.generated.h"

/**
 * @brief Describes category of a particular extension
 *
 * Declared through a namespace so it could be easily extended
 */
UENUM(BlueprintType)
namespace EJetpackExtension
{
	enum Type
	{
		/**
		 * Applicable for extensions that are meant to provide new movement
		 * functionality for a jetpack
		 */
		MOVEMENT,
		/**
		 * Applicable for extensions that extend navigation system of a jetpack
		 */
		NAVIGATION,
		/**
		 * Applicable for extensions that add weapons to a jetpack
		 */
		WEAPONRY
	};
}

UINTERFACE(BlueprintType, Blueprintable)
class UJetpackExtension : public UInterface
{
	GENERATED_BODY()
};

/**
 * Describes a jetpack extension
 */
class IJetpackExtension
{
	GENERATED_BODY()
public:
	/**
	 * Is called right after this extension has been attached to a jetpack
	 *
	 * @param InitialTransform Transform of jetpack at the moment of attachment
	 * @param StatusCode Was there a failure when attaching the extension.
	 * Zero code means no failure
	 */
	virtual void Initialize(FTransform InitialTransform, int32 StatusCode) = 0;

	/**
	 * Is called every jetpack frame
	 *
	 * @param DeltaTime Time (in seconds) passed from the last call
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnTick(float DeltaTime);

	/**
	 * Is called when state of jetpack this extensions is attached to has changed
	 *
	 * @see AJetpack::SetState
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnJetpackStateChanged();

	/**
	 * Returns type of this extension
	 *
	 * @return Type of this extension
	 * @see EJetpackExtension::Type
	 */
	UFUNCTION()
	virtual EJetpackExtension::Type GetType() = 0;
};
