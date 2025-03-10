#pragma once

#include "ActorComponent.h"
#include "Math/Math.h"

class USceneComponent : public UActorComponent
{
public:
	USceneComponent();

	virtual void Destroy() override;

public:
	void SetRelativeLocation(const FVector& Loc);
	void SetRelativeRotation(const FVector& Rot);
	void SetRelativeScale3D(const FVector& Scale);

private:
	FVector RelativeLocation;
	FVector RelativeRotation;
	FVector RelativeScale3D;

public:
	USceneComponent* GetParent() const { return AttachParent; }
	TArray<USceneComponent*> GetAllChildren() const { return AttachChildren; }

	void SetupAttachment(class USceneComponent* InParent);

private:
	USceneComponent* AttachParent;
	TArray<USceneComponent*> AttachChildren;

};