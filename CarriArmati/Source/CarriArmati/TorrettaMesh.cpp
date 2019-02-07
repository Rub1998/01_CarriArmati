// Fill out your copyright notice in the Description page of Project Settings.

#include "TorrettaMesh.h"


void UTorrettaMesh::Eleva(float VelRelativa)
{
	//UE_LOG(LogTemp, Warning, TEXT("vel relativa %f"), VelRelativa);

	VelRelativa = FMath::Clamp<float>(VelRelativa, -1, 1);

	float CambioLevatura = VelRelativa * ElevazioneMaxSec *  GetWorld()->DeltaTimeSeconds;


	float NuovaLevatura = RelativeRotation.Pitch + CambioLevatura;

	NuovaLevatura = FMath::Clamp<float>(NuovaLevatura, ElevazioneMin, ElevazioneMax);

	SetRelativeRotation(FRotator(NuovaLevatura, 0, 0));

}

void UTorrettaMesh::Ruota(float VelRelativa)
{

	VelRelativa = FMath::Clamp<float>(VelRelativa, -1, 1);

	float CambioRotazione = VelRelativa * RotazioneMaxSec *  GetWorld()->DeltaTimeSeconds;

	float NuovaRotazione = RelativeRotation.Yaw + CambioRotazione;

	SetRelativeRotation(FRotator(0, NuovaRotazione,  0));

}

