// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterPlayerController.h"
#include "Blaster/HUD/BlasterHUD.h"
#include "Blaster/HUD/CharacterOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void ABlasterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Using GetHUD Funcation from the PlayerController Class and Casting it to OUR Blaster HUD and storing it
	BlasterHUD = Cast<ABlasterHUD>(GetHUD());
}

void ABlasterPlayerController::SetHUDHealth(float Health, float MaxHealth)
{
	//need to access BlasterHUD
	BlasterHUD = BlasterHUD == nullptr ? Cast<ABlasterHUD>(GetHUD()) : BlasterHUD;

	bool bHUDValid = BlasterHUD &&
		BlasterHUD->CharacterOverlay &&
			BlasterHUD->CharacterOverlay->HealthBar &&
				BlasterHUD->CharacterOverlay->HealthText;
	
	if(bHUDValid)
	{
		//Creating the Percentage
		const float HealthPercent = Health / MaxHealth;
		//Setting the HealthPercent as the HealthBars %
		//SetPercent is a function of the ProgressBar
		BlasterHUD->CharacterOverlay->HealthBar->SetPercent(HealthPercent);

		//Formatting the Text for Health Text as an FString
		FString HealthText = FString::Printf(TEXT("%d/%d"), FMath::CeilToInt(Health), FMath::CeilToInt(MaxHealth));

		//Need to Convert the HealthText FString to a FText for the SetText function.
		BlasterHUD->CharacterOverlay->HealthText->SetText(FText::FromString(HealthText));
	}
}
