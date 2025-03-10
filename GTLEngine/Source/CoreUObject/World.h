#pragma once

#include "Object.h"

#include "Math/Math.h"

#include "Components/SceneComponent.h"

class AActor;
class ACamera;

class UWorld : public UObject
{

public:
	static UWorld* CreateWorld();

	template<typename T>
	T* SpawnActor(std::wstring InName, const FVector& InLocation, const FVector& InRotation, const FVector& InScale, UObject* InOwner)
	{
		T* newObj = T();
		AActor* newActor = dynamic_pointer_cast<AActor>(newObj);
		// newActor-> SetLocation, SetScale, SetRotation.
		newActor->SetLocation(InLocation);
		newActor->SetScale(InScale);
		newActor->SetRotation(InRotation);

		if (newActor != nullptr)
		{
			newActor->SetOwner(InOwner);
			
			USceneComponent* Comp = newActor->GetRootComponent();
			Comp->SetRelativeLocation(InLocation);
			Comp->SetRelativeRotation(InRotation);
			Comp->SetRelativeScale3D(InScale);

			ActiveActors.push_back(newActor);
		}
		return newObj;
	}

public:
	void CameraTick(float TickTime);
	virtual void Tick(float TickTime) override;
	virtual void Destroy() override;



public:
	TArray<AActor*> GetActors() const { return ActiveActors; }
	ACamera* GetCamera() const { return MainCamera; }

private:
	TArray<AActor*> ActiveActors;
	ACamera* MainCamera;


};

