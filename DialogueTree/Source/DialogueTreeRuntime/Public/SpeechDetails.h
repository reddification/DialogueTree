// Copyright Zachary Brett, 2024. All rights reserved.

#pragma once

//UE
#include "CoreMinimal.h"
#include "Sound/SoundCue.h"
#include "GameplayTagContainer.h"
//Generated
#include "SpeechDetails.generated.h"

USTRUCT(BlueprintType)
struct DIALOGUETREERUNTIME_API FSpeechGestureData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly)
	FName SpeakerName;

	UPROPERTY(BlueprintReadOnly)
	FGameplayTag GestureTag;

	UPROPERTY(BlueprintReadOnly, meta=(UIMin = 0.f, ClampMin = 0.f, UIMax = 1.f, ClampMax = 1.f))
	float GestureChance;
};

// 19.11.2024 @AK: changing data for FSpeechDetails to have an array of FSpeechOption with FText and USoundCue instead of single FText SpeechText and SpeechAudio
// G2VS2 Begin
USTRUCT(BlueprintType)
struct DIALOGUETREERUNTIME_API FSpeechOptionData
{
	GENERATED_BODY()
	
	/** The text of the speech */
	UPROPERTY(BlueprintReadOnly)
	FText SpeechText = FText();

	/** The audio associated with the speech */
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<USoundCue> SpeechAudio = nullptr;
};

/**
* Struct used to pass information about an individual dialogue 
* speech. 
*/
USTRUCT(BlueprintType)
struct DIALOGUETREERUNTIME_API FSpeechDetails
{
	GENERATED_BODY()

	/** The text of the speech */
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TArray<FSpeechOptionData> SpeechVariations;

	/** The name of the speaker */
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	FName SpeakerName = NAME_None;

	/** The base title for the speech (foundation of its ID) */
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	FName SpeechTitle = NAME_None; 

	/** The minimum time for the speech to play before transitioning (unless
	* skipped) */
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	float MinimumPlayTime = 3.f;

	/** Any behavior flags associated with the speech as gameplay tags */
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	FGameplayTagContainer GameplayTags;

	/** Whether the speech content should be ignored when entering the node */
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	bool bIgnoreContent = false;

	/** Whether the player is allowed to skip the speech */
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	bool bCanSkip = true;

	/** Used when an option. Whether the option is locked or free to 
	* be selected */
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	bool bIsLocked = false;

	/** Additional message associated with the speech when used as an option.
	* For example, can provide an optional reason for being locked. */
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	FText OptionMessage = FText();

	/** Gesture to play for character */
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	FGameplayTag GestureTag_Obsolete;
	
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	float GestureChance_Obsolete = 0.8f;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TArray<FSpeechGestureData> Gestures;
};

// G2VS2 End

// Original structure
/**
* Struct used to pass information about an individual dialogue 
* speech. 
*/
// USTRUCT(BlueprintType)
// struct DIALOGUETREERUNTIME_API FSpeechDetails
// {
// 	GENERATED_BODY()
//
// 	/** The text of the speech */
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	FText SpeechText = FText();
//
// 	/** The name of the speaker */
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	FName SpeakerName = NAME_None;
//
// 	/** The base title for the speech (foundation of its ID) */
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	FName SpeechTitle = NAME_None; 
//
// 	/** The audio associated with the speech */
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	TObjectPtr<USoundBase> SpeechAudio = nullptr;
//
// 	/** The minimum time for the speech to play before transitioning (unless
// 	* skipped) */
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	float MinimumPlayTime = 3.f;
//
// 	/** Any behavior flags associated with the speech as gameplay tags */
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	FGameplayTagContainer GameplayTags;
//
// 	/** Whether the speech content should be ignored when entering the node */
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	bool bIgnoreContent = false;
//
// 	/** Whether the player is allowed to skip the speech */
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	bool bCanSkip = true;
//
// 	/** Used when an option. Whether the option is locked or free to 
// 	* be selected */
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	bool bIsLocked = false;
//
// 	/** Additional message associated with the speech when used as an option.
// 	* For example, can provide an optional reason for being locked. */
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	FText OptionMessage = FText();
//
// 	/** Gesture to play for character */
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	FGameplayTag GestureTag;
// 	
// 	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
// 	float GestureChance = 0.8f;
// };