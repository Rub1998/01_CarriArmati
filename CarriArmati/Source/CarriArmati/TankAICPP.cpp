// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAICPP.h"


void ATankAICPP::BeginPlay()
{
	Super::BeginPlay();

	auto CarroControllato = GetTank();

	auto Bersaglio        = GetPlayerTank();

	if (!CarroControllato || !Bersaglio) return;

	Timer = FMath::FRandRange(4, 8);

	//UE_LOG(LogTemp, Warning, TEXT("controllo il tank %s"), *Bersaglio->GetName());

	//var1.Equals(var2, valore);
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

void ATankAICPP::Tick(float deltatime)
{
	Super::Tick(deltatime);

	if(GetPlayerTank() && Aim)
	{
		Aim->AimAt(GetPlayerTank()->GetActorLocation());
	
		if (Timer > 0) Timer -= deltatime;
		else
		{
			Aim->SparaReal();
			Timer = FMath::FRandRange(4, 8);
		}

		MoveToActor(GetPlayerTank(),RDistanza);

	}
}

void ATankAICPP::SetAim(UAimingCPP* Set)
{
	Aim = Set;
}
