#include "pch.h"
#include "World.h"

#include "Meshes.h"

void World::Update() 
{
	m_Camera.Update();
	m_Arrow.Update();
}

std::vector<std::tuple<Object&, Rendering::MeshData>> World::CreateMeshes() 
{
	std::vector<std::tuple<Object&, Rendering::MeshData>> objects;
	
	std::tuple<Object&, Rendering::MeshData> arrowMesh(m_Arrow, CreateArrowMesh());
	objects.push_back(arrowMesh);
	
	std::tuple<Object&, Rendering::MeshData> floorMesh(m_Floor, CreateRectangleMesh(1.0f, 1.01f, 0.1f));
	//objects.push_back(floorMesh);

	return objects;
}