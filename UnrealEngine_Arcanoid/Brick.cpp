// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Ball.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SM_brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_collision"));
	Box_Collision->SetBoxExtent(FVector(25, 10, 10));
	RootComponent = Box_Collision;
	
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
}

void ABrick::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Ball")) 
	{
		
	/*	ABall* myball = Cast<ABall>(OtherActor);
		myball->addVelocity(speedModiferOnBounce);*/
		//時間を経ったらオブジェクトを破壊する
		FTimerHandle unUseHandle;
		GetWorldTimerManager().SetTimer(unUseHandle, this, &ABrick::destroyBrick, 0.1f, false);
		
	}
}

void ABrick::destroyBrick()
{
	this->Destroy();
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

