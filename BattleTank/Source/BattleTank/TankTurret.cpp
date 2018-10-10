// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	auto RelSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto DirectionChange = RelSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewDirection = RelativeRotation.Yaw + DirectionChange;

	// auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(0, RawNewDirection, 0));
}


