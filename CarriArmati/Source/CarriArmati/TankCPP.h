// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AimingCPP.h"
#include "TankCPP.generated.h"

UCLASS()
class CARRIARMATI_API ATankCPP : public APawn
{
	GENERATED_BODY()

		FORCEINLINE UStaticMeshComponent* GetCannone() { return Cannone; }


public:
	// Sets default values for this pawn's properties
	ATankCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Object)
		UAimingCPP* Aiming;

protected:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetCannone(UStaticMeshComponent* Set);

	UStaticMeshComponent* Cannone = nullptr;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float Vellancio = 100000;
	
};
