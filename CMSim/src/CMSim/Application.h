#pragma once

#include "Core.h"

#include "CMSim/Window.h"
#include "CMSim/LayerStack.h"
#include "CMSim/Events/Event.h"
#include "CMSim/Events/ApplicationEvent.h"

namespace CMSim {

	class CMSIM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return  *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	//Defined by client
	Application* CreateApplication();

}