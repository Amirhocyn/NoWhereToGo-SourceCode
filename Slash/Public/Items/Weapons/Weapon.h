// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"

class  USoundBase;
class UBoxComponent;

UCLASS()
class SLASH_API AWeapon : public AItem
{
	GENERATED_BODY()
public:
	AWeapon();
	void AttachMeshToSocket(USceneComponent* InParent, FName InSocketName);
	void PlayEquipSound();
	void DisableSphereCollision();
	void DiActivateEmbers();
	void Equip(USceneComponent* InParent, FName InSocketName, AActor* NewOwner, APawn* NewInstigator);
	void ExecuteGetHit(FHitResult BoxHit);
	bool ActorIsSameType(AActor* OtherActor);
	TArray<AActor*> IgnoreActors;
protected:

	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void CreateField(const FVector& FieldLocation);
	
private:
	
	void BoxTrace(FHitResult& BoxHit);

	UPROPERTY(EditAnywhere, Category= "Weapon Properties")
	FVector BoxTraceExtend = FVector(5.f);

	UPROPERTY(EditAnywhere, Category= "Weapon Properties")
	bool bShowBoxDebug = false;
	
	UPROPERTY(EditAnywhere, Category= "Weapon Properties")
	USoundBase* EquipSound;

	UPROPERTY(VisibleAnywhere, Category= "Weapon Properties")
	UBoxComponent* WeaponBox;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceStart;
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceEnd;

	UPROPERTY(EditAnywhere, Category= "Weapon Properties")
	float Damage = 20.f;
	

public:
	FORCEINLINE UBoxComponent* GetWeaponBox() const {return WeaponBox;}
};
