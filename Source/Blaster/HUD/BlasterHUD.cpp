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

		if(HUDPackage.CrosshairsCenter)
		{
			//Draw Texture
			DrawCrosshair(HUDPackage.CrosshairsCenter, ViewportCenter);
		};
		if(HUDPackage.CrosshairsTop)
		{
			//Draw Texture
			DrawCrosshair(HUDPackage.CrosshairsTop, ViewportCenter);
		};
		if(HUDPackage.CrosshairsBottom)
		{
			//Draw Texture
			DrawCrosshair(HUDPackage.CrosshairsBottom, ViewportCenter);
		};
		if(HUDPackage.CrosshairsLeft)
		{
			//Draw Texture
			DrawCrosshair(HUDPackage.CrosshairsLeft, ViewportCenter);
		};
		if(HUDPackage.CrosshairsRight)
		{
			//Draw Texture
			DrawCrosshair(HUDPackage.CrosshairsRight, ViewportCenter);
		};
	};
}

void ABlasterHUD::DrawCrosshair(UTexture2D* Texture, FVector2d ViewportCenter)
{
	//function for drawing crosshair at correct location

	const float TextureWidth =  Texture->GetSizeX();
	const float TextureHeight =  Texture->GetSizeY();

	//Draws the texture at the center of the viewport based on the calculation of the width and height of the texture.
	const FVector2d TextureDrawPoint(
		ViewportCenter.X - (TextureWidth/2.f),
		ViewportCenter.Y - (TextureHeight/2.f)
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
