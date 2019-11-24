// Fill out your copyright notice in the Description page of Project Settings.


#include "Padle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APadle::APadle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//設定
	SM_Padle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("staticMesh"));
	RootComponent = SM_Padle;
	SM_Padle->SetEnableGravity(false);
	SM_Padle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Padle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Padle->SetCollisionProfileName(TEXT("PhysicsActor"));
	//移動のため
	floatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("floatingPawn movement"));
	

}

// Called when the game starts or when spawned
void APadle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APadle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APadle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APadle::MoveHorizontal(float AxisValue)
{
	//移動
	AddMovementInput(FVector(AxisValue, 0, 0), 1, false);
}

