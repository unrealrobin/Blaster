// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
		
	}

}

void UOverheadWidget::SetPlayerName(FString NameToDisplay)
{
	if (PlayerName)
	{
		PlayerName->SetText(FText::FromString(NameToDisplay));
	}
	else
	{
		PlayerName->SetText(FText::FromString(FString("Player 2")));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetLocalRole();
	FString Role;
	switch (LocalRole)
	{
	case ENetRole::ROLE_Authority:
			Role = FString("Authority");
			break;
	case ENetRole::ROLE_AutonomousProxy:
			Role = FString("Autonomous Proxy");
			break;
	case ENetRole::ROLE_SimulatedProxy:
			Role = FString("Simulated Authority");
			break;
	case ENetRole::ROLE_None:
			Role = FString("None");
			break;
	}

	FString LocalRoleString = FString::Printf(TEXT("Local Role: %s"), *Role);

	SetDisplayText(LocalRoleString);
}

void UOverheadWidget::ShowPlayerStateName(APawn* InPawn)
{

	if (InPawn == nullptr)
	{
		return;
	}

	APlayerState* PlayersState = InPawn->GetPlayerState();

	FString PawnName = PlayersState->GetPlayerName();

	SetPlayerName(PawnName);

}

void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	RemoveFromParent();//removes this widget from the view port.
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
};