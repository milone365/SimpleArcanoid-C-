// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ball.generated.h"

class UProjectileMovementComponent;
UCLASS()
class ARCADE_API ABall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABall();
	virtual void Launch();
	bool BallLanched;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//画像のため
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
		UStaticMeshComponent* sm_ball;

	//移動の為に
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
		UProjectileMovementComponent* ProjectileMovement;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		UStaticMeshComponent* GetBall();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void addVelocity(float value);
};
