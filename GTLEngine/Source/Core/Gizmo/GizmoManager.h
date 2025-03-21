#pragma once

#include "Object.h"

#include "Gizmo/GizmoBase.h"

struct FRay;

class UGizmoManager
{

public:
	UGizmoManager();

	void Tick(float DeltaTime);
	void Destroy();

	void Picking();

private:
	AActor* SelectedActor;
	IDragable* DragTarget;
	TArray<UGizmoBase*> Gizmo;
public:
	IClickable* PickClickable(float MouseX, float MouseY) const;
	void ClearSelected();
	const TArray<UGizmoBase*> GetGizmo();
	void AttachGizmo(AActor* target);
	inline AActor* GetSelected() const { return SelectedActor; }
	inline void SetSelected(AActor* actor) { SelectedActor = actor; }
};

