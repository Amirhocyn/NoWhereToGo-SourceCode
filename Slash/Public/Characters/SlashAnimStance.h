// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterTypes.h"
#include "SlashAnimStance.generated.h"


/**
 * 
 */
UCLASS()
class SLASH_API USlashAnimStance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly)
	class ASlashCharacter* SlashCharacter;

	UPROPERTY(BlueprintReadOnly, Category= Movement)
	class UCharacterMovementComponent* SlashCharacterMovement;

	UPROPERTY(BlueprintReadOnly, Category= Movement)
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category= Movement)
	bool IsFalling;

	UPROPERTY(BlueprintReadOnly, Category=Movement)
	ECharacterState CharacterState;

	UPROPERTY(BlueprintReadOnly, Category= Movement)
	EActionState ActionState;

	UPROPERTY(BlueprintReadOnly, Category= Movement)
	TEnumAsByte<EDeathPose> DeathPose;
};
