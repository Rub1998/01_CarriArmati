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
	auto AimRotation = AimDirection.Rotation();
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
	UE_LOG(LogTemp, Warning, TEXT("il barrel %s mira a %s"), *Rotazione.ToString(), *AimRotation.ToString());


}


// Called when the game starts
void UAimingCPP::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimingCPP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimingCPP::AimAt(FVector HitLocation, float Vellancio)
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