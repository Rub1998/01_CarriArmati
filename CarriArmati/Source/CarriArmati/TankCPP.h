// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AimingCPP.h"
#include "Proiettile.h"
#include "TankCPP.generated.h"

UCLASS()
class CARRIARMATI_API ATankCPP : public APawn
{
	GENERATED_BODY()

    FORCEINLINE UTorrettaMesh* GetCannone() { return Cannone; }

	float reload;


public:
	// Sets default values for this pawn's properties
	ATankCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "SetUp")
		float reload_time = 3;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);
	
	UPROPERTY(EditAnywhere, Category = "Firing")
		UAimingCPP* Aiming = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AActor> ProjectileBP;

	UFUNCTION(BlueprintCallable, Category = "Fire")
		void SparaReal();

	
protected:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetCannone(UTorrettaMesh* Set);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTorre(UTorrettaMesh* Set);

	UTorrettaMesh* Cannone = nullptr;
	UTorrettaMesh* Torre = nullptr;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float Vellancio = 10000;
	
};
