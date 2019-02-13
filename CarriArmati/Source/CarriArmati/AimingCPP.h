// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TorrettaMesh.h"
#include "Proiettile.h"
#include "AimingCPP.generated.h"

UENUM()
enum class EaimingStatus : uint8
{
	movimento,
	mira,
	ricarica,
	generico
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARRIARMATI_API UAimingCPP : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "SetUp")
		float reload_time = 3;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float Vellancio = 10000;

	float reload;

public:	
	// Sets default values for this component's properties
	UAimingCPP();

	UPROPERTY(BlueprintReadonly, Category = "enum")
		EaimingStatus  myaim = EaimingStatus::movimento;

	void SetStatus(uint8 nuovo_stato);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void MuoviCannone(FVector AimDirection);

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AActor> ProjectileBP;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetCannone(UTorrettaMesh* Set);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetTorre(UTorrettaMesh* Set);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SparaReal();

	UTorrettaMesh * Cannone = nullptr;
	UTorrettaMesh * Torre = nullptr;

};
