// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Shoot", EInputEvent::IE_Pressed, this, &AMyPlayerController::OnShoot);
	InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::OnMoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::OnMoveRight);
}

void AMyPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	Tank = Cast<ATank>(InPawn);

}



void AMyPlayerController::OnShoot()
{
	if (Tank)
	{
		Tank->Shoot();
	}
}

void AMyPlayerController::OnMoveForward( float Scale)
{
	if (Tank)
	{
		Tank->MoveForward(Scale);
	}
}

void AMyPlayerController::OnMoveRight(float Scale)
{
	Tank->MoveRight(Scale);
}