#pragma once

#include "Math/Vector.h"

struct FNormalVertex
{
	// 버텍스 포지션.
	FVector Pos;
	// 버텍스 노말.
	FVector Normal;
	// 버텍스 색상.
	FVector4 Color;
	// 버텍스 텍스쳐 좌표.
	//FVector2 Tex;
};

struct FStaticMesh
{
    // Mesh obj 파일 경로 이름.
	FString PathFileName;

	// 버텍스 정보.
	TArray<FNormalVertex> Vertices;
    // 인덱스 정보.
	TArray<uint32> Indices;
};

// Raw Data
struct FObjInfo
{
    // Vertex List
    // UV List
    // Normal List
    // Vertex Index List
    // UV Index List
    // Normal Index List
    // Material List
    // Texture List
    
};

struct FObjMaterialInfo
{
    // Diffuse Scalar
    // Diffuse Texture
    
};

struct FObjImporter
{
    // Obj Parsing (*.obj to FObjInfo)
    // Material Parsing (*.obj to MaterialInfo)
    // Convert the Raw data to Cooked data (FStaticMesh)
    
};