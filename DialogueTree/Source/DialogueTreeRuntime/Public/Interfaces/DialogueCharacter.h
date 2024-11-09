// 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "DialogueCharacter.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UDialogueCharacter : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DIALOGUETREERUNTIME_API IDialogueCharacter
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual bool StartDialogueGesture(const FGameplayTag& GestureTag) = 0;
	virtual void StopDialogueGesture() = 0;
};
