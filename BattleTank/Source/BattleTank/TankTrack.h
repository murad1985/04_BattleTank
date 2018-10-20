// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	// Max force per track in Neutons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000000;	// Assume 40ton tank and 1g acceleration


private:
	UTankTrack();

	TArray<class ASprungWheel*>GetWheels() const;

	void DriveTrack(float CurrentThrottle);

};
