#include "pch.h"
#include "Object.h"

using namespace DirectX;

Object::Object() 
{	
	XMStoreFloat4x4(&m_View, XMMatrixIdentity());
}