// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCPP.h"


// Sets default values
ATankCPP::ATankCPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Aiming = CreateDefaultSubobject<UAimingCPP>(FName("Aiming"));


}

// Called when the game starts or when spawned
void ATankCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
}

void ATankCPP::SetTorre(UTorrettaMesh* Set)
{
	Aiming->SetTorre(Set);
}
