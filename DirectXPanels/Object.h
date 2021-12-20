#pragma once

#include<DirectXMath.h>

class Object
{
public:	
	Object();

	virtual void Update() {}
	DirectX::XMFLOAT4X4 GetView() { return m_View; }

protected:
	DirectX::XMFLOAT4X4 m_View;
};

