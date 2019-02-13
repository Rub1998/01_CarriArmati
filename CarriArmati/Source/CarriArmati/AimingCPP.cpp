// Fill out your copyright notice in the Description page of Project Settings.

#include "AimingCPP.h"


// Sets default values for this component's properties
UAimingCPP::UAimingCPP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UAimingCPP::MuoviCannone(FVector AimDirection)
{
	auto Rotazione = Cannone->GetForwardVector().Rotation();
	auto AimRotation   = AimDirection.Rotation();
	auto deltarotation = AimRotation - Rotazione;

	Cannone->Eleva(deltarotation.Pitch);
	if (FMath::Abs(deltarotation.Yaw) > 180)
	{
		Torre->Ruota(-deltarotation.Yaw);
	}
	else
	{
		Torre->Ruota(deltarotation.Yaw);
	}
	//UE_LOG(LogTemp, Warning, TEXT("il barrel %s mira a %s"), *Rotazione.ToString(), *AimRotation.ToString());


}


// Called when the game starts
void UAimingCPP::BeginPlay()
{
	Super::BeginPlay();
	reload = reload_time;
	// ...
	
}


// Called every frame
void UAimingCPP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (reload > 0) reload -= DeltaTime;
	// ...
}


void UAimingCPP::AimAt(FVector HitLocation)
{
	//UE_LOG(LogTemp, Warning, TEXT("il Carro %s mira a %s con il comp %s"), *GetOwner()->GetName(), *HitLocation.ToString(),*Cannone->GetComponentLocation().ToString());

	FVector Toss;
	FVector Start = Cannone->GetSocketLocation(FName("fuoco"));

	bool result = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		Toss,
		Start,
		HitLocation,
		Vellancio,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (result)
	{
		FVector AimDirection = Toss.GetSafeNormal();
		MuoviCannone(AimDirection);
	}


}

void UAimingCPP::SetCannone(UTorrettaMesh* Set)
{
	Cannone = Set;
}

void UAimingCPP::SetTorre(UTorrettaMesh* Set)
{
	Torre = Set;
}

void UAimingCPP::SparaReal()
{
	if (!ProjectileBP)
	{
		UE_LOG(LogTemp, Error, TEXT("nessun proiettile selezionato"));
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

void UAimingCPP::SetStatus(uint8 nuovo_stato)
{
	switch (nuovo_stato)
	{
		case 0:
		   myaim = EaimingStatus::ricarica;
		break;

		case 1:
			myaim = EaimingStatus::movimento;
		break;

		case 2:
			myaim = EaimingStatus::mira;
		break;

	}


}