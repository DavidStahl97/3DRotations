#pragma once

class Camera
{
public:
	void Update();

	DirectX::XMFLOAT4X4 getView() { return m_View; }

private:
	DirectX::XMFLOAT4X4 m_View;
};