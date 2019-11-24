// Fill out your copyright notice in the Description page of Project Settings.


#include "Padle_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Padle.h"
#include "Ball.h"
#include "G_Manager.h"

APadle_Controller::APadle_Controller()
{
}

void APadle_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
	EnableInput(this);
	InputComponent->BindAxis("MoveHorizontal", this, &APadle_Controller::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APadle_Controller::Launch);
}

void APadle_Controller::BeginPlay()
{
	//カメラの設定
	TArray<AActor*>CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0],Params);
	SpawnNewBall();
}

//移動
void APadle_Controller::MoveHorizontal(float AxisValue)
{
   auto myPawn = Cast<APadle>(GetPawn());
   if (myPawn) 
   {
	   myPawn->MoveHorizontal(AxisValue);
   }
}

//フラグー＞true
void APadle_Controller::Launch()
{
	myBall->Launch();
}

void APadle_Controller::SpawnNewBall()
{
	
	if (!myBall)
	{
		myBall = nullptr;
	}

	//球をスポーンする
	if (BallObj)
	{
		myBall = GetWorld()->SpawnActor<ABall>(BallObj, spawnLocation, spawnRotation, SpawnInfo);
	}
}
