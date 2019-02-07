// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "MeshCingolo.h"
#include "Movimento.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class CARRIARMATI_API UMovimento : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Controlli")
		void IntenzioneAvanti(float movimento);

	UFUNCTION(BlueprintCallable, Category = "Controlli")
		void IntenzioneLaterale(float movimento);

	UFUNCTION(BlueprintCallable, Category = "Controlli")
		void Initialize(UMeshCingolo* DxTrack, UMeshCingolo * SxTrack);

	virtual void RequestDirectMove
	(
		const FVector & MoveVelocity,
		bool bforceMaxSpeed

	) override;

private:
	UMeshCingolo* DxC = nullptr;
	UMeshCingolo* SxC = nullptr;

	
	
	
};
