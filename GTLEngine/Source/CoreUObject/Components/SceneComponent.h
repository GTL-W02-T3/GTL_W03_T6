#pragma once

#include "ActorComponent.h"
#include "Math/Vector.h"
#include "Math/Rotator.h"
#include "Math/Matrix.h"

class USceneComponent : public UActorComponent
{
public:
	USceneComponent();

	virtual void Destroy() override;

public:
	void SetRelativeLocation(const FVector& Loc);
	void SetRelativeRotation(const FRotator& Rot);
	void SetRelativeScale(const FVector& Scale);
	virtual FMatrix GetWorldMatrix() const { 
		return FMatrix::GetScaleMatrix(RelativeScale) * FMatrix::GetRotateMatrix(RelativeRotation) * FMatrix::GetTranslateMatrix(RelativeLocation); 
	};
	FVector GetComponentLocation() const { return RelativeLocation; }
	FRotator GetComponentRotation() const { return RelativeRotation; }
	FVector GetComponentScale() const { return RelativeScale; }

private:
	FVector RelativeLocation;
	FRotator RelativeRotation;
	FVector RelativeScale;

public:
	USceneComponent* GetParent() const { return AttachParent; }
	TArray<USceneComponent*> GetAllChildren() const { return AttachChildren; }

	void SetupAttachment(class USceneComponent* InParent);

private:
	USceneComponent* AttachParent;
	TArray<USceneComponent*> AttachChildren;

};