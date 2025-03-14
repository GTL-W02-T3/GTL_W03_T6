#include "pch.h"
#include "ResourceManager.h"

#include "Resource/Shape/PrimitiveShape.h"

UResourceManager::UResourceManager()
{
    LoadPrimitives();
}

UResourceManager::~UResourceManager()
{
    Release();
}

void UResourceManager::LoadPrimitives()
{
    VertexDataMap[EPrimitiveType::Line] = {
        {0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f},
        {0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f},
    };

    uint64 TriangleVertexNum = sizeof(TriangleVertices) / sizeof(FVertexSimple);
    VertexDataMap[EPrimitiveType::Plane] = TArray<FVertexSimple>(TriangleVertices, TriangleVertices + TriangleVertexNum);

    uint64 SphereVertexNum = sizeof(SphereVertices) / sizeof(FVertexSimple);
    VertexDataMap[EPrimitiveType::Sphere] = TArray<FVertexSimple>(SphereVertices, SphereVertices + SphereVertexNum);

    uint64 CubeVertexNum = sizeof(CubeVertices) / sizeof(FVertexSimple);
    VertexDataMap[EPrimitiveType::Cube] = TArray<FVertexSimple>(CubeVertices, CubeVertices + CubeVertexNum);

    uint64 CylinderVertexNum = sizeof(CylinderVertices) / sizeof(FVertexSimple);
    VertexDataMap[EPrimitiveType::Cylinder] = TArray<FVertexSimple>(CylinderVertices, CylinderVertices + CylinderVertexNum);

    uint64 ConeVertexNum = sizeof(ConeVertices) / sizeof(FVertexSimple);
    VertexDataMap[EPrimitiveType::Cone] = TArray<FVertexSimple>(ConeVertices, ConeVertices + ConeVertexNum);

    uint64 GridVertexNum = 1000;
    float offset = static_cast<float>(GridVertexNum / 2) / 4;
    TArray<FVertexSimple>& grid = VertexDataMap[EPrimitiveType::Grid] = TArray<FVertexSimple>();
    grid.reserve(GridVertexNum);
    for ( int i = 0; i < GridVertexNum / 4; ++i ) {
        float f = static_cast<float>(i);
        grid.push_back({ f - offset, offset,  0.f,    1.0f, 1.0f, 1.0f, 1.0f });
        grid.push_back({ f - offset, -offset, 0.f,    1.0f, 1.0f, 1.0f, 1.0f });
        grid.push_back({ offset, f - offset,  0.f,    1.0f, 1.0f, 1.0f, 1.0f });
        grid.push_back({ -offset, f - offset, 0.f,    1.0f, 1.0f, 1.0f, 1.0f });
    }
}

void UResourceManager::Release()
{
    for (auto& [Type, Info] : VertexDataMap)
    {
        Info.clear();
    }
    VertexDataMap.clear();
}

const TArray<FVertexSimple> UResourceManager::GetVertexData(EPrimitiveType Type) const
{
    if (VertexDataMap.contains(Type))
    {
        return VertexDataMap.find(Type)->second;
    }
	return TArray<FVertexSimple>();
}
