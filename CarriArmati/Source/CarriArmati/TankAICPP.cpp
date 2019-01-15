// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAICPP.h"

void ATankAICPP::BeginPlay()
{
	Super::BeginPlay();

	auto CarroControllato = GetTank();

	auto Bersaglio        = GetPlayerTank();

	if (!CarroControllato || !Bersaglio) return;

	UE_LOG(LogTemp, Warning, TEXT("controllo il tank %s"), *Bersaglio->GetName());





}


ATankCPP* ATankAICPP::GetTank()
{
	return Cast<ATankCPP>(GetPawn());
}


ATankCPP* ATankAICPP::GetPlayerTank()
{
	auto Controller = Cast<ATankControllerCPP>(GetWorld()->GetFirstPlayerController());

	return Cast<ATankCPP>(Controller->GetPawn());



}





