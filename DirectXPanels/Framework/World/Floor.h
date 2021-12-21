#pragma once

#include<DirectXMath.h>
#include "Object.h"

class Floor : public Object 
{
public:
	explicit Floor() : Object() 
	{
		auto view = DirectX::XMMatrixTranslation(0, 5, 0);
		XMStoreFloat4x4(&m_View, view);
	}
};