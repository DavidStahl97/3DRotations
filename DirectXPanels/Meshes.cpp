#include "pch.h"
#include "Meshes.h"

#include <DirectXMath.h>

using namespace DirectX;

namespace DirectXPanels
{
	void CreateArrow(MeshData& meshData) 
	{
		static const float length = 0.3f;
		static const float hight = 0.03f;
		static const float depth = 0.05f;

		static const float arrowLength = 0.2f;
		static const float arrowDepth = 0.15;

		static const Vertex arrowArray[] =
		{
			// rectangle
			{XMFLOAT3(-length, hight, depth), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f)},
			{XMFLOAT3(length, hight,  depth), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f)},
			{XMFLOAT3(length, -hight,  depth), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f)},
			{XMFLOAT3(-length, -hight,  depth), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f)},

			{XMFLOAT3(-length, hight, -depth), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f)},
			{XMFLOAT3(length, hight,  -depth), XMFLOAT4(0.0f, 0.3f, 0.4f, 1.0f)},
			{XMFLOAT3(length, -hight,  -depth), XMFLOAT4(0.5f, 0.0f, 0.3f, 1.0f)},
			{XMFLOAT3(-length, -hight,  -depth), XMFLOAT4(0.9f, 0.1f, 1.0f, 1.0f)},

			// arrow
			{XMFLOAT3(length, hight,  0), XMFLOAT4(0.5f, 0.0f, 0.3f, 1.0f)},
			{XMFLOAT3(length + arrowLength, hight,  0), XMFLOAT4(0.0f, 0.0f, 0.3f, 1.0f)},
			{XMFLOAT3(length, hight, 2 * depth), XMFLOAT4(0.1f, 0.0f, 0.3f, 1.0f)},
			{XMFLOAT3(length, hight, 2 * -depth), XMFLOAT4(0.8f, 0.2f, 0.3f, 1.0f)},

			{XMFLOAT3(length, -hight,  0), XMFLOAT4(0.5f, 0.0f, 0.3f, 1.0f)},
			{XMFLOAT3(length + arrowLength, -hight,  0), XMFLOAT4(0.0f, 0.0f, 0.3f, 1.0f)},
			{XMFLOAT3(length, -hight, 2 * depth), XMFLOAT4(0.8f, 0.7f, 0.35f, 1.0f)},
			{XMFLOAT3(length, -hight, 2 * -depth), XMFLOAT4(0.1f, 0.0f, 0.8f, 1.0f)},
		};

		meshData.Vertices.insert(meshData.Vertices.begin(), std::begin(arrowArray), std::end(arrowArray));

		static const UINT indices[] =
		{
			// rectangle
			0, 1, 2,
			0, 2, 3,

			6, 5, 4,
			7, 6, 4,

			3, 4, 0,
			7, 4, 3,

			5, 2, 1,
			2, 5, 6,

			5, 1, 0,
			4, 5, 0,

			3, 2, 6,
			3, 6, 7,

			// arrow			
			8, 9, 10,
			11, 9, 8,

			14, 13, 12,
			12, 13, 15,

			12, 13, 14,
			15, 13, 12,

			15, 11, 10,
			14, 15, 10,

			10, 9, 14,
			14, 9, 13,

			15, 9, 11,
			13, 9, 15,
		};

		meshData.Indices.insert(meshData.Indices.begin(), std::begin(indices), std::end(indices));
	}
}
