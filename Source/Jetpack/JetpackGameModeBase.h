/*
 * Copyright © 2022, Medelfor, Limited. All rights reserved.
 * For any additional information refer to https://medelfor.com
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JetpackGameModeBase.generated.h"

/**
 * A basic game mode with a validation system
 */
UCLASS(Blueprintable)
class JETPACK_API AJetpackGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	/**
	 * Describes a validation to perform
	 */
	struct FValidationMode
	{
		/**
		 * Describes different kinds of entities that can be validated
		 */
		enum class Entity
		{
			/**
			 * Validate all jetpacks
			 */
			JETPACKS,
			/**
			 * Validate all extensions
			 */
			EXTENSIONS
		}
		/** Specifies what kind of entities require validation */
		WhatToValidate = Entity::JETPACKS;

		/**
		 * Do repeat validation after it's finished
		 */
		bool DoRepeat = false;

		/**
		 * Start the validation when this many seconds passes
		 */
		float TimeoutSeconds = 1.0f;

		/**
		 * Start new validation after the last is finished and after this many
		 * seconds passed
		 */
		float LoopTimeSeconds = 1.0f;
	};

	/**
	 * Start a system validation
	 *
	 * @param Mode The mode to perform validation in
	 * @see FValidationMode
	 */
	virtual void SetupSystemValidation(TSharedPtr<FValidationMode> Mode);

private:
	/**
	 * Resets internal state for the upcoming validation
	 */
	void SetupValidationInternal();

	/**
	 * Directly performs the validation after internal state is set
	 *
	 * @param Mode The mode to perform validation in
	 */
	void PerformValidation(TSharedPtr<FValidationMode> Mode);

	/**
	 * A mode selected for the next validation
	 */
	TSharedPtr<FValidationMode> Validation;
};
