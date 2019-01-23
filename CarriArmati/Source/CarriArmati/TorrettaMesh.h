// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TorrettaMesh.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class CARRIARMATI_API UTorrettaMesh : public UStaticMeshComponent
{
	GENERATED_BODY()


public:
	void Eleva(float VelRelativa);
	
	UPROPERTY(EditAnywhere, Category = "SetUp")
		float ElevazioneMaxSec = 20;
	
	UPROPERTY(EditAnywhere, Category = "SetUp")
		float ElevazioneMax = 35;

	UPROPERTY(EditAnywhere, Category = "SetUp")
		float ElevazioneMin = 0;

	void Ruota(float VelRelativa);

	UPROPERTY(EditAnywhere, Category = "SetUp")
		float RotazioneMaxSec = 20;

	UPROPERTY(EditAnywhere, Category = "SetUp")
		float RotazioneMax = 35;

	UPROPERTY(EditAnywhere, Category = "SetUp")
		float RotazioneMin = 0;

};
