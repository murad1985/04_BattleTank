// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


// Tick
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardsCrosshair();
}
	

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Player Controller not possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		// UE_LOG(LogTemp, Warning, TEXT("Look location: %s"), *HitLocation.ToString());

		// TODO tell controlled to tank to aim at crosshair
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(
		ViewportSizeX * CrossHairXLocation, 
		ViewportSizeY * CrossHairYLocation
	);

	// Deproject screen position of the crosshair to world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
	}
	
	// Line-trace along that direction and see what we hit


	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation; // to be discarded
	DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection);
	return true;
}



