/*
 * Copyright © 2022, Medelfor, Limited. All rights reserved.
 * For any additional information refer to https://medelfor.com
 */

#pragma once

#include "BaseJetpackExtension.h"
#include "TrickPerformerExtension.generated.h"

/**
 * Describes a trick for @ref ATrickPerformerExtension to perform
 *
 * @see ATrickPerformerExtension
 */
USTRUCT(BlueprintType)
struct JETPACK_API FTrick
{
	GENERATED_BODY()

	/**
	 * Target relative rotation for the jetpack
	 */
	UPROPERTY(BlueprintReadOnly)
	FRotator Rotation;

	/**
	 * Target relative translation for the jetpack
	 */
	UPROPERTY(BlueprintReadOnly)
	FVector Translation;

	/**
	 * How many times to repeat the trick
	 */
	UPROPERTY(BlueprintReadOnly)
	int32 RepeatsCount = 1;
};

/**
 * An extension for jetpack that enables it to perform programmable tricks
 *
 * @see FTrick
 */
UCLASS(BlueprintType, Blueprintable)
class ATrickPerformerExtension : public ABaseJetpackExtension
{
	GENERATED_BODY()
public:
	/**
	 * @brief Starts execution of the specified trick
	 *
	 * Calls @ref OnTrickPerforming right after the start of execution
	 *
	 * @param Trick The trick to perform
	 * @see FTrick
	 */
	UFUNCTION(BlueprintCallable)
	virtual void PerformTrick(FTrick Trick);

	/**
	 * Gets called when a trick has been started
	 *
	 * @param Trick The trick being executed now
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnTrickPerforming(FTrick Trick);

	/**
	 * Directly executes the trick
	 *
	 * @param DeltaTime Time (in seconds) passed from the last call
	 */
	void OnTick_Implementation(float DeltaTime) override;

protected:
	/**
	 * Initialized internal state through sub-initialization mechanism
	 *
	 * @param InitialTransform The initial transform of the jetpack
	 * @return
	 * @see ABaseJetpackExtension::SubInitialize
	 */
	int32 SubInitialize(FTransform InitialTransform) override;

	/**
	 * Initializes the trick execution system with seed
	 * @return Zero if everything went successful, non-zero - otherwise
	 * @param Seed Seed to use when retrieving random numbers
	 */
	void InitializeSystem(int32 Seed);
};
