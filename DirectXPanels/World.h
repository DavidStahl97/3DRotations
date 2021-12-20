#pragma once

#include "Object.h"
#include "Camera.h"
#include "Arrow.h"
#include "Content/ShaderStructures.h"

class World
{
public:
	void Update();
	std::vector<std::tuple<Object&, Rendering::MeshData>> CreateMeshes();
	Camera GetCamera() { return m_Camera; };

private:	
	Camera m_Camera;
	Arrow m_Arrow;
};

