// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Padle_Controller.generated.h"

class ABall;
class AG_Manager;

UCLASS()
class ARCADE_API APadle_Controller : public APlayerController
{
	GENERATED_BODY()
		APadle_Controller();

		UFUNCTION()
		virtual void SetupInputComponent() override;
protected:
	virtual void BeginPlay() override;
	//移動
	void MoveHorizontal(float AxisValue);
	//ball ref
	void Launch();
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall>BallObj;

	ABall* myBall;
	//球のスポーン所
	FVector spawnLocation = FVector(0, 0,20);
	FRotator spawnRotation = FRotator(0, 0, 0);
	FActorSpawnParameters SpawnInfo;
	
public:
	void SpawnNewBall();
	AG_Manager* gm;
};
