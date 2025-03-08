#pragma once

// STL include
#include <windows.h>
#include <tchar.h>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

// D3D include
#pragma comment(lib, "user32")
#pragma comment(lib, "d3d11")
#pragma comment(lib, "d3dcompiler")

#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>

using namespace Microsoft::WRL;

// typedef default int type.
typedef UINT		uint;
typedef	UINT8		uint8;
typedef	UINT16		uint16;
typedef	UINT32		uint32;
typedef	UINT64		uint64;
typedef	INT8		int8;
typedef	INT16		int16;
typedef	INT32		int32;
typedef	INT64		int64;

template <typename T>
using TArray = vector<T>;

template <typename T1, typename T2>
using TPair = pair<T1, T2>;

template <typename T1, typename T2>
using TMap = unordered_map<T1, T2>;

template <typename T>
using TQueue = queue<T>;

template <typename T>
using TSet = set<T>;

