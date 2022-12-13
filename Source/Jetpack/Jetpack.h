/*
 * Copyright © 2022, Medelfor, Limited. All rights reserved.
 * For any additional information refer to https://medelfor.com
 */

#pragma once

#include "CoreMinimal.h"
#include "JetpackExtension.h"
#include "Jetpack.generated.h"

/**
 * Describes the current state of a jetpack instance
 *
 * @see AJetpack
 */
UENUM()
enum class EJetpackState : uint8
{
	/**
	 * Describes a state when a jetpack is not only turned on but actually moving
	 * or floating in the air
	 */
	RUNNING,
	/**
	 * Describes a state when a jetpack is turned on but isn't used
	 */
	IDLE,
	/**
	 * Describes a state when a jetpack is turned off and is being fueled up
	 */
	FUELING,
	/**
	 * Describes a state when a jetpack is completely turned off and isn't used in
	 * any way
	 */
	STOPPED,
	/**
	 * Service enumerator
	 */
	MAX UMETA(Hidden)
};

/**
 * A delegate that notifies subscribers if state of jetpack has changed
 *
 * @param OldState The previous state of a jetpack
 * @param NewState The new state of a jetpack
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStateChanged, EJetpackState,
	OldState, EJetpackState, NewState);

/**
 * The central class of the module. Provides base functionality of a jetpack,
 * namely fueling system, states, replicated movement and extensions.
 */
UCLASS(Blueprintable, BlueprintType)
class JETPACK_API AJetpack : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * A delegate that notifies subscribers if a new extension has been attached
	 *
	 * @param Extension The new extension
	 */
	DECLARE_MULTICAST_DELEGATE_OneParam(FOnNewExtension,
		TScriptInterface<IJetpackExtension> Extension);

	/**
	 * @brief Adds an extension to this jetpack
	 *
	 * Extends this jetpack with an extension running on the specified priority
	 * and which uses the specified starting sequence
	 *
	 * @param Extension The extension to extend this jetpack with
	 * @param Priority Priority the extension should run on. The higher - the
	 * more important extension is
	 * @param StartingSequence The sequence to use when initializing the extension
	 */
	UFUNCTION(BlueprintCallable)
	void Extend(TScriptInterface<IJetpackExtension> Extension,
		int32 Priority, int32 StartingSequence);

	/**
	 * Returns all the extensions ever added to this jetpack
	 *
	 * @return The list of extensions
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<TScriptInterface<IJetpackExtension>> GetExtensions() const;

	/**
	 * Returns the current state of this jetpack
	 *
	 * @return State this jetpack is currently in
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	EJetpackState GetState() const;

	/**
	 * @brief Sets the current state of this jetpack
	 *
	 * Updates the state of jetpack. @ref OnJetpackStateChanged will be called on
	 * every attached extension.
	 *
	 * @param NewState The new state for this jetpack
	 */
	void SetState(EJetpackState NewState);

	/**
	 * @brief Is called when the jetpack starts
	 *
	 * A Blueprint native event which is called when the jetpack starts (someone
	 * calls @ref SetJetpackEnabled with `true`). Passes in the list of registered
	 * extensions.
	 *
	 * @param Extensions All registered extensions for this jetpack
	 * @deprecated Use extension mechanism and @ref OnJetpackStateChanged instead
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnStarted(UPARAM(Ref) TArray<TScriptInterface<IJetpackExtension>>& Extensions);

	void OnStarted_Implementation(TArray<TScriptInterface<IJetpackExtension>>& Extensions);

	/**
	 * @brief A convenient way to blow up this jetpack
	 *
	 * Blows this jetpack up and creates an explosion of specified size.
	 *
	 * @param ExplosionSize Size of the explosion in centimeters. Cannot be negative
	 */
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void BlowItUp(float ExplosionSize);

	/**
	 * Validates the @ref BlowItUp
	 *
	 * @param ExplosionSize See @ref BlowItUp
	 * @return `false` if `ExplosionSize` is negative, `true` - otherwise
	 * @see BlowItUp
	 */
	bool BlowItUp_Validate(float ExplosionSize);

	void BlowItUp_Implementation(float ExplosionSize);

	/**
	 * Enables/disables this jetpack
	 *
	 * @param IsEnabled New state of the jetpack
	 */
	UE_DEPRECATED("1.1.0", "Use @ref SetState instead")
	void SetJetpackEnabled(bool IsEnabled);

	/**
	 * Setups replication
	 */
	void GetLifetimeReplicatedProps(
		TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/**
	 * @brief A facility to subscribe for notification of state changes
	 *
	 * Is broadcasted every time state changes. Doesn't get called if the value
	 * passed as `NewState` in @ref SetState is the same as the value @ref GetState
	 * returns
	 *
	 * @see SetState
	 * @see GetState
	 * @see FOnStateChanged
	 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnStateChanged OnStateChanged;

	/**
	 * The fuel (in gallons) remaining in this jetpack
	 */
	UPROPERTY(BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Fuel)
	float RemainingFuel = 0.0f;

	/**
	 * The current state of this jetpack
	 *
	 * @see EJetpackState
	 */
	UPROPERTY(BlueprintReadOnly, Replicated)
	EJetpackState State = EJetpackState::STOPPED;

	/**
	 * Whether this jetpack is enabled
	 */
	UPROPERTY()
	bool IsEnabled_DEPRECATED = false;

protected:
	/**
	 * Is called when `RemainingFuel` is being replicated
	 *
	 * @param NewFuel New amount of remaining fuel
	 */
	UFUNCTION()
	virtual void OnRep_Fuel(float NewFuel);

private:
	/**
	 * The notifier of extension attachments
	 */
	FOnNewExtension mOnNewExtension;
};
