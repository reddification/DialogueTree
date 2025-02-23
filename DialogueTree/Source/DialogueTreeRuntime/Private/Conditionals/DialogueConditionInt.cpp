// Copyright Zachary Brett, 2024. All rights reserved.

//Header
#include "Conditionals/DialogueConditionInt.h"
//Plugin
#include "Conditionals/Queries/Base/DialogueQueryInt.h"
//UE
#include "UObject/UObjectGlobals.h"

#define LOCTEXT_NAMESPACE "DialogueQueryInt"

void UDialogueConditionInt::PostDuplicate(EDuplicateMode::Type DuplicateMode)
{
    Super::PostDuplicate(DuplicateMode);

    if (!Query) return;
    Query = DuplicateObject<UDialogueQueryInt>(Query, this);
}

bool UDialogueConditionInt::IsMet() const
{
    check(Query);
    int32 QueryValue = Query->ExecuteQuery();

    switch (Comparison)
    {
        case EIntComparison::GreaterThan:
            return QueryValue > CompareValue;
        case EIntComparison::GreaterThanOrEqualTo:
            return QueryValue >= CompareValue;
        case EIntComparison::LessThan:
            return QueryValue < CompareValue;
        case EIntComparison::LessThanOrEqualTo:
            return QueryValue <= CompareValue;
        default:
            return QueryValue == CompareValue;
    }
}

void UDialogueConditionInt::SetQuery(UDialogueQuery* InQuery)
{
    check(InQuery);
    Query = Cast<UDialogueQueryInt>(InQuery);
    check(Query);
}

void UDialogueConditionInt::SetDialogue(UDialogue* InDialogue)
{
    check(InDialogue);
    Query->SetDialogue(InDialogue);
}

FText UDialogueConditionInt::GetDisplayText(const TMap<FName, FText>& ArgTexts, 
    const FText QueryText) const
{
    FText BaseText = LOCTEXT("BaseText", "{0} {1} {2}");
    FText CompareText = ArgTexts.FindChecked("Comparison");
    FText CompareValueText = ArgTexts.FindChecked("CompareValue");

    return FText::Format(
        BaseText, 
        QueryText,
        CompareText,
        CompareValueText);
}

FText UDialogueConditionInt::GetGraphDescription(FText QueryText)
{
    FText BaseText = LOCTEXT("BaseText", "{0} {1} {2}");
    FText CompareText;
    switch (Comparison)
    {
        case EIntComparison::GreaterThan:
            CompareText = LOCTEXT("GreaterThan", ">");
            break;
        case EIntComparison::LessThan:
            CompareText = LOCTEXT("LessThan", "<");
            break;
    case EIntComparison::GreaterThanOrEqualTo:
        CompareText = LOCTEXT("GreaterThanOrEqualTo", ">=");
        break;
    case EIntComparison::LessThanOrEqualTo:
        CompareText = LOCTEXT("LessThanOrEqualTo", "<=");
        break;
        default:
            CompareText = LOCTEXT("EqualTo", "=");
            break;
    }
    FText CompareValueText = FText::AsNumber(CompareValue);

    return FText::Format(
        BaseText,
        QueryText,
        CompareText,
        CompareValueText);
}

bool UDialogueConditionInt::IsValidCondition()
{
    if (Query && Query->IsValidQuery())
    {
        return true;
    }

    return false;
}

UDialogueQuery* UDialogueConditionInt::GetQuery() const
{
    return Query;
}

#undef LOCTEXT_NAMESPACE