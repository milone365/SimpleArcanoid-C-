// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Padle.generated.h"

class 	UFloatingPawnMovement;
UCLASS()
class ARCADE_API APadle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APadle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Padle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* floatingMovement;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void MoveHorizontal(float AxisValue);
};
