// Fill out your copyright notice in the Description page of Project Settings.

#include "RenderTargetReader.h"
#include "Engine/TextureRenderTarget2D.h"

ARenderTargetReader::ARenderTargetReader()
{
	PrimaryActorTick.bCanEverTick = false;
}

TArray<uint8> ARenderTargetReader::ReadGrayscalePixels(UTextureRenderTarget2D* RenderTarget)
{
	TArray<uint8> GrayscalePixels;

	if (!RenderTarget)
	{
		UE_LOG(LogTemp, Warning, TEXT("RenderTargetReader: RenderTarget is null"));
		return GrayscalePixels;
	}

	auto* RTResource = RenderTarget->GameThread_GetRenderTargetResource();
	if (!RTResource)
	{
		UE_LOG(LogTemp, Warning, TEXT("RenderTargetReader: Could not get render target resource"));
		return GrayscalePixels;
	}

	TArray<FColor> ColorPixels;
	bool bSuccess = RTResource->ReadPixels(ColorPixels);

	if (!bSuccess || ColorPixels.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("RenderTargetReader: ReadPixels failed or returned empty array"));
		return GrayscalePixels;
	}

	// Convert RGBA to grayscale using luminance weights
	GrayscalePixels.Reserve(ColorPixels.Num());
	for (const FColor& Pixel : ColorPixels)
	{
		uint8 Gray = (uint8)(0.299f * (float)Pixel.R + 0.587f * (float)Pixel.G + 0.114f * (float)Pixel.B);
		GrayscalePixels.Add(Gray);
	}

	UE_LOG(LogTemp, Log, TEXT("RenderTargetReader: Read %d pixels successfully"), GrayscalePixels.Num());
	return GrayscalePixels;
}

void ARenderTargetReader::GetRenderTargetSize(UTextureRenderTarget2D* RenderTarget, int32& Width, int32& Height)
{
	if (!RenderTarget)
	{
		Width = 0;
		Height = 0;
		return;
	}
	Width = RenderTarget->SizeX;
	Height = RenderTarget->SizeY;
}

