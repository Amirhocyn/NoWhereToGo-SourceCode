// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Treasure.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/PickUp.h"

void ATreasure::SpawnPickupSound()
{
	if (PickUpSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, PickUpSound, GetActorLocation());
	}
}

void ATreasure::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickUp* PickupInterface = Cast<IPickUp>(OtherActor);
	if (PickupInterface)
	{
		PickupInterface->AddGold(this);
		SpawnPickupSound();
		Destroy();
	}
}
