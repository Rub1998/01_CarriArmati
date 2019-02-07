// Fill out your copyright notice in the Description page of Project Settings.

#include "MeshCingolo.h"


void UMeshCingolo::RichiestaMovimento(float movimento)
{
	if (movimento != 0)
	{
		//FString Name = GetName();
	    //UE_LOG(LogTemp, Warning, TEXT("%s muove di %f"), *Name, movimento);

		FVector ForzaApplicata = GetForwardVector() * movimento * ForzaMaxCingolo;
		FVector ForzaLocazione = GetComponentLocation();

		//USceneComponent* TRoot = GetOwner()->GetRootComponent();
		
		UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

		TankRoot->AddForceAtLocation(ForzaApplicata, ForzaLocazione);

	}


}


