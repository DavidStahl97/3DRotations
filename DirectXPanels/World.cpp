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
	std::tuple<Object&, Rendering::MeshData> arrowMesh(m_Arrow, CreateArrowMesh());
	
	std::vector<std::tuple<Object&, Rendering::MeshData>> objects;
	objects.push_back(arrowMesh);
	
	return objects;
}