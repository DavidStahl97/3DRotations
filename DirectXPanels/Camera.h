#pragma once

class Camera
{
public:
	void Update();

	DirectX::XMFLOAT4X4 getView() { return m_View; }

	void SetPhi(float phi) { m_Phi = phi; }
	void SetEpsilon(float epsilon) { m_Epsilon = epsilon; }

private:
	DirectX::XMFLOAT4X4 m_View;

	float m_Phi = 0;
	float m_Epsilon = 0;
	float m_Distance = 2;
};