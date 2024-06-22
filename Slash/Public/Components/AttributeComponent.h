// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLASH_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void RegenStamina(float DeltaTime);
	
protected:
	virtual void BeginPlay() override;

private:
	//Current health
	UPROPERTY(EditAnywhere, Category="Actor Attributes")
	float Health;
	
	UPROPERTY(EditAnywhere, Category="Actor Attributes")
	float MaxHealth;

	UPROPERTY(EditAnywhere, Category="Actor Attributes")
	float Stamina;
	
	UPROPERTY(EditAnywhere, Category="Actor Attributes")
	float MaxStamina;

	UPROPERTY(EditAnywhere, Category="Actor Attributes")
	int32 Gold;
	
	UPROPERTY(EditAnywhere, Category="Actor Attributes")
	int32 Souls;

	UPROPERTY(EditAnywhere, Category="Actor Attributes")
	float DodgeCost = 14.f;

	UPROPERTY(EditAnywhere, Category="Actor Attributes")
	float StaminaRegenerate = 8.f;
public:
	void ReceiveDamage(float Damage);
	void UseStamina(float StaminaCost);
	float GetHealthPercent();
	float GetStaminaPercent();
	bool IsAlive();
	void AddSouls(int32 NumberOfSouls);
	void AddGold(int32 AmountOfSGold);
	FORCEINLINE int32 GetGold() const {return Gold;}
	FORCEINLINE int32 GetSouls() const {return Souls;}
	FORCEINLINE int32 GetDodgeCost() const {return DodgeCost;}
	FORCEINLINE int32 GetStamina() const {return Stamina;}
};
