// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	sm_ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = sm_ball;
	//球の設定
	sm_ball->SetSimulatePhysics(true);
	sm_ball->SetEnableGravity(false);
	sm_ball->SetConstraintMode(EDOFMode::XZPlane);
	sm_ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	sm_ball->SetCollisionProfileName(TEXT("PhysicsActor"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("projectile movement"));
	//rimbalzo
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1f;
	//aderenza alle pareti
	ProjectileMovement->Friction = 0.0f;
	//スピードをに設定する
	ProjectileMovement->Velocity.X = 0.0f;
}



// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::Launch()
{
	if (!BallLanched)
	{
		//スピードを入れる
		sm_ball->AddImpulse(FVector(140, 0, 130), FName(), true);
		//flag->true
		BallLanched = true;
	}
}
UStaticMeshComponent * ABall::GetBall()
{
	return nullptr;
}

// Called to bind functionality to input
void ABall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//不完成
void ABall::addVelocity(float value)
{
	FVector ballvelocity = this->GetVelocity();
	ballvelocity *= (value - 1.0f);
}

