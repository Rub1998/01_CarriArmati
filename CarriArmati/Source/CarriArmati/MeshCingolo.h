// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MeshCingolo.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class CARRIARMATI_API UMeshCingolo : public UStaticMeshComponent
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable, Category = "Controls")
		void RichiestaMovimento(float movimento);

	UPROPERTY(EditDefaultsOnly, Category = "Controls")
		float ForzaMaxCingolo = 25000000;
	
	
	
};
