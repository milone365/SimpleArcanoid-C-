// Fill out your copyright notice in the Description page of Project Settings.


#include "BallBounds.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Padle_Controller.h"

// Sets default values
ABallBounds::ABallBounds()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//ボックスcomponentの追加
	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = Box_Collision;
}

// Called when the game starts or when spawned
void ABallBounds::BeginPlay()
{
	Super::BeginPlay();
	//あたり安定
	Box_Collision->OnComponentBeginOverlap.AddDynamic(this,&ABallBounds
		::OnOverlapBegin);
	//アクセス
	PlayerController_Ref = Cast<APadle_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

void ABallBounds::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult & SweepResult)
{
	//tagの確認
	if (OtherActor->ActorHasTag("Ball"))
	{
		//球を壊して、新しい作る
		OtherActor->Destroy();
		PlayerController_Ref->SpawnNewBall();
	}
}

// Called every frame
void ABallBounds::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

