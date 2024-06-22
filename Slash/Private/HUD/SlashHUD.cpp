// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashHUD.h"
#include "HUD/SlashOverlay.h"

#include "Blueprint/UserWidget.h"

void ASlashHUD::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* Controller = World->GetFirstPlayerController();
		if (Controller && SlashOverLayClass)
		{
			SlashOverlay = CreateWidget<USlashOverlay>(Controller, SlashOverLayClass);
			SlashOverlay->AddToViewport();
		}
	}
}
