// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankCPP.h"
#include "TankControllerCPP.generated.h"

/**
 * 
 */
UCLASS()
class CARRIARMATI_API ATankControllerCPP : public APlayerController
{
	GENERATED_BODY()

		virtual void BeginPlay() override;
	    ATankCPP* GetTank();
	
		virtual void Tick(float deltatime) override;

		void Mira();

		float MirinoX = 0.5;
		float MirinoY = 0.3;

		bool TrovaVista(FVector& loc);
		bool TrovaDirezioneVista(FVector2D Mirino, FVector& DirezioneVista);
		bool TrovaHitVista(FVector DirezioneVista, FVector&HitLocation);
		
protected:

	    UPROPERTY(EditAnywhere, Category = "SetUp")
		float LineTraceRange = 1000000.f; 


};
