// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterHUD.h"

void ABlasterHUD::DrawHUD()
{
	Super::DrawHUD();

	FVector2d ViewportSize;
	if(GEngine)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
		const FVector2d ViewportCenter(ViewportSize.X / 2.f, ViewportSize.Y / 2.f);

		float SpreadScaled = CrosshairSpreadMax * HUDPackage.CrosshairSpread;

		if(HUDPackage.CrosshairsCenter)
		{
			FVector2d Spread(0.f, 0.f);
			//Draw Texture
			DrawCrosshair(HUDPackage.CrosshairsCenter, ViewportCenter, Spread);
		};
		if(HUDPackage.CrosshairsTop)
		{
			FVector2d Spread(0.f, -SpreadScaled);
			//Draw Texture
			DrawCrosshair(HUDPackage.CrosshairsTop, ViewportCenter, Spread);
		};
		if(HUDPackage.CrosshairsBottom)
		{
			FVector2d Spread(0.f, SpreadScaled);
			//Draw Texture
			DrawCrosshair(HUDPackage.CrosshairsBottom, ViewportCenter, Spread);
		};
		if(HUDPackage.CrosshairsLeft)
		{
			FVector2d Spread(-SpreadScaled, 0.f);
			//Draw Texture
			DrawCrosshair(HUDPackage.CrosshairsLeft, ViewportCenter, Spread);
		};
		if(HUDPackage.CrosshairsRight)
		{
			FVector2d Spread(SpreadScaled, 0.f);
			//Draw Texture
			DrawCrosshair(HUDPackage.CrosshairsRight, ViewportCenter, Spread);
		};
	};
}

void ABlasterHUD::DrawCrosshair(UTexture2D* Texture, FVector2d ViewportCenter, FVector2d Spread)
{
	//function for drawing crosshair at correct location

	const float TextureWidth =  Texture->GetSizeX();
	const float TextureHeight =  Texture->GetSizeY();

	//Draws the texture at the center of the viewport based on the calculation of the width and height of the texture.
	const FVector2d TextureDrawPoint(
		ViewportCenter.X - (TextureWidth/2.f) + Spread.X,
		ViewportCenter.Y - (TextureHeight/2.f) + Spread.Y
	);

	DrawTexture(
		Texture,
		TextureDrawPoint.X,
		TextureDrawPoint.Y,
		TextureWidth,
		TextureHeight,
		0.f,
		0.f,
		1.f,
		1.f,
		FLinearColor::White
	);
	
}
