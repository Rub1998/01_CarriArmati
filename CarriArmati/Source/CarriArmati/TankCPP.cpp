// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCPP.h"


// Sets default values
ATankCPP::ATankCPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Aiming = CreateDefaultSubobject<UAimingCPP>(FName("Aiming"));

}

// Called when the game starts or when spawned
void ATankCPP::BeginPlay()
{
	Super::BeginPlay();
	
}
/*
// Called every frame
void ATankCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (reload > 0) reload -= DeltaTime;
}

// Called to bind functionality to input
void ATankCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATankCPP::AimAt(FVector HitLocation)
{
	Aiming->AimAt(HitLocation,Vellancio);
}

void ATankCPP::SetCannone(UTorrettaMesh* Set)
{
	Aiming->SetCannone(Set);
	Cannone = Set;
}

void ATankCPP::SetTorre(UTorrettaMesh* Set)
{
	Aiming->SetTorre(Set);
}

void ATankCPP::SparaReal()
{
	if (!ProjectileBP)
	{
		//UE_LOG(LogTemp, Error, TEXT("nessun proiettile selezionato"));
	}
	else
	{

		if (reload <= 0)
		{
			AProiettile* Proiettile = GetWorld()->SpawnActor<AProiettile>(
				ProjectileBP,
				Cannone->GetSocketLocation(FName("fuoco")),
				Cannone->GetSocketRotation(FName("fuoco")));

			Proiettile->Lancio(Vellancio);

			reload = reload_time;

		}


	}

	
}
*/