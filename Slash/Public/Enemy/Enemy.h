
#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterTypes.h"
#include "Characters/BaseCharacter.h"
#include "Enemy.generated.h"

class UWidgetComponent;
class UHealthBarComponent;
class UPawnSensingComponent;

UCLASS()
class SLASH_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AEnemy();

	virtual void Tick(float DeltaTime) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	                         class AController* EventInstigator, AActor* DamageCauser) override;

	virtual void Destroyed() override;

	
	
protected:
	virtual void BeginPlay() override;
	void SpawnSoul();

	virtual void Die_Implementation() override;
	virtual void Attack() override;
	virtual bool CanAttack() override;
	virtual void AttackEnd() override;
	virtual void HandleDamage(float DamageAmount) override;
	
	UPROPERTY(BlueprintReadOnly)
	EEnemyState EnemyState = EEnemyState::EES_Patrolling;


	
private:

	// AI Behavior
	void InitializedEnemy();
	void CheckCombatTarget();
	void CheckPatrolTarget();
	void PatrolTimerFinished();
	void HideHealthBar();
	void ShowHealthBar();
	void LoseInterest();
	void StartPatroling();
	void ChaseTarget();
	bool IsoutSideCombatRadius();
	bool IsOutSideAttackRadius();
	bool IsInSideAttackRadius();
	bool IsChasing();
	bool IsAttacking();
	bool IsDead();
	bool IsEngaged();
	void ClearPatrolTimer();
	void StartAttackTimer();
	void ClearAttackTimer();
	bool InTargetRange(AActor* Target, double Radius);
	void MoveToTarget(AActor* Target);
	AActor* ChoosePatrolTarget();
	void SpawnDefaultWeapon();
	
	UFUNCTION()
	void PawnSeen(APawn* SeenPawn); // Callback for OnPawnSeen in UPawnSensingComponent

	UPROPERTY(VisibleAnywhere)
	UHealthBarComponent* HealthbarWidget;

	UPROPERTY(VisibleAnywhere)
	UPawnSensingComponent* PawnSensing;

	UPROPERTY(EditAnywhere, Category= Combat)
	TSubclassOf<class AWeapon> WeaponClass;

	UPROPERTY(EditAnywhere, Category= Combat)
	double CombatRadius = 1000.f;

	UPROPERTY(EditAnywhere, Category= Combat)
	double AttackRadius = 150.f;

	UPROPERTY(EditAnywhere, Category= Combat)
	double AcceptanceRadius = 150.f;
	
	//Navigation
	
	UPROPERTY()
	class AAIController* EnemyContoller;
	
	UPROPERTY(EditInstanceOnly, Category= "AINavigation")
	AActor* PatrolTarget;

	UPROPERTY(EditInstanceOnly, Category= "AINavigation")
	TArray<AActor*> PatrolTargets;
	
	UPROPERTY(EditAnywhere)
	double PatrolRadius = 100.f;
	
	FTimerHandle PatrolTimer;
	
	UPROPERTY(EditAnywhere, Category= "AI Navigation")
	float PatrolWaitMin = 5.f;
	
	UPROPERTY(EditAnywhere, Category= "AI Navigation")
	float PatrolWaitMax = 10.f;

	UPROPERTY(EditAnywhere, Category= Combat)
	float PatrolingSpeed = 125.f;
	
	FTimerHandle AttackTimer;

	UPROPERTY(EditAnywhere, Category= Combat)
	float AttackMin = 0.5f;
	
	UPROPERTY(EditAnywhere, Category= Combat)
	float AttackMax = 1.f;

	UPROPERTY(EditAnywhere, Category= Combat)
	float ChasingSpeed = 300.f;

	UPROPERTY(EditAnywhere, Category= Combat)
	float DeathLifeSpan = 8.f;

	UPROPERTY(EditAnywhere, Category= Combat)
	TSubclassOf<class ASoul> SoulClass;
};
