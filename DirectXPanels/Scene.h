#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"
#include "Content\SceneRenderer.h"
#include "Content\FpsTextRenderer.h"

// Renders Direct2D and 3D content on the screen.
namespace Rendering
{
	class Scene : public DX::IDeviceNotify
	{
	public:
		Scene(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		~Scene();
		void CreateWindowSizeDependentResources();
		void StartRenderLoop();
		void StopRenderLoop();
		Concurrency::critical_section& GetCriticalSection() { return m_criticalSection; }

		World& GetWorld() { return m_sceneRenderer->GetWorld(); }

		// IDeviceNotify
		virtual void OnDeviceLost();
		virtual void OnDeviceRestored();	

	private:
		void ProcessInput();
		void Update();
		bool Render();

		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// TODO: Replace with your own content renderers.
		std::unique_ptr<SceneRenderer> m_sceneRenderer;
		std::unique_ptr<FpsTextRenderer> m_fpsTextRenderer;

		Windows::Foundation::IAsyncAction^ m_renderLoopWorker;
		Concurrency::critical_section m_criticalSection;

		// Rendering loop timer.
		DX::StepTimer m_timer;

		// Track current input pointer position.
		float m_pointerLocationX;
	};
}