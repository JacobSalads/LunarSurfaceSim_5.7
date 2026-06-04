// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RenderTargetReader.generated.h"

// Forward declaration
class UTextureRenderTarget2D;

UCLASS()
class LUNARSURFACESIM_API ARenderTargetReader : public AActor
{
	GENERATED_BODY()

public:
	ARenderTargetReader();

	// Read render target pixels as grayscale bytes - callable from Blueprint
	UFUNCTION(BlueprintCallable, Category = "Render Target")
	static TArray<uint8> ReadGrayscalePixels(UTextureRenderTarget2D* RenderTarget);

	// Get render target dimensions
	UFUNCTION(BlueprintCallable, Category = "Render Target")
	static void GetRenderTargetSize(UTextureRenderTarget2D* RenderTarget, int32& Width, int32& Height);
};
