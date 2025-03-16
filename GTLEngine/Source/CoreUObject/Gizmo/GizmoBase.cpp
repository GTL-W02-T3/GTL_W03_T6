#include "pch.h"
#include "GizmoBase.h"
#include "Utils/Math/Geometry.h"

UGizmoBase::UGizmoBase(EAxis axis, AActor* Target) : Target(Target), axis(axis) {}

void UGizmoBase::Tick(float TickTime) {
    if ( IsAbsoluteCoord ) {
        if ( axis == EAxis::Y ) {
            mat = mat * FMatrix::GetRotateMatrix(FQuat::EulerToQuaternion(FVector(0.f, 0.f, -90.f)));
        } else if ( axis == EAxis::Z ) {
            mat = mat * FMatrix::GetRotateMatrix(FQuat::EulerToQuaternion(FVector(0.f, 90.f, 0.f)));
        }
        mat = FMatrix::GetTranslateMatrix(Target->GetActorLocation());
    } else {
        //transform = FMatrix::GetScaleMatrix(Target->GetActorScale());
        // 
        //mat = FMatrix::GetRotateMatrix(Target->GetActorRotation());
        mat = FMatrix::GetRotateMatrix(Target->GetActorRotation());
        if ( axis == EAxis::Y ) {
            mat = mat * FMatrix::GetRotateMatrix(FQuat::EulerToQuaternion(FVector(0.f, 0.f, -90.f)));
        }
        if ( axis == EAxis::Z ) {
            mat = mat * FMatrix::GetRotateMatrix(FQuat::EulerToQuaternion(FVector(0.f, 90.f, 0.f)));
        }
        mat = mat * FMatrix::GetTranslateMatrix(Target->GetActorLocation());
    }
}

void UGizmoBase::Destroy() {}

FAABB UGizmoBase::GetAABB() const {
    FVector min = FVector(FLT_MAX, FLT_MAX, FLT_MAX);
    FVector max = FVector(-FLT_MAX, -FLT_MAX, -FLT_MAX);

    FVector vecs[8];
    if ( Target == nullptr ) {
        OutputDebugString(L"UGizmoBase::GetAABB(): Target nullptr");
        return FAABB(min, max);
    }

    for ( int i = 0; i < 8; i++ ) {
        vecs[i] = mat.TransformPositionVector(OriginalAABB[i]);
        if ( vecs[i].X < min.X ) min.X = vecs[i].X;
        if ( vecs[i].Y < min.Y ) min.Y = vecs[i].Y;
        if ( vecs[i].Z < min.Z ) min.Z = vecs[i].Z;
        if ( vecs[i].X > max.X ) max.X = vecs[i].X;
        if ( vecs[i].Y > max.Y ) max.Y = vecs[i].Y;
        if ( vecs[i].Z > max.Z ) max.Z = vecs[i].Z;
    }

    return FAABB(min, max);
}

bool UGizmoBase::IsClicked(FRay ray, float maxDistance, FVector& hitpoint) {

	return Geometry::IsRayIntersectAABB(GetAABB(), ray, maxDistance);
}
