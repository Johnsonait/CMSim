#pragma once

#include "CMSim/Events/Event.h"
#include "CMSim/Layer.h"
#include "CMSim/Events/ApplicationEvent.h"
#include "CMSim/Events/MouseEvent.h"
#include "CMSim/Events/KeyEvent.h"

namespace CMSim {

	class CMSIM_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		bool OnKeyReleasedEvent(KeyPressedEvent& event);
		bool OnKeyPressedEvent(KeyReleasedEvent& event);
		bool OnKeyTypedEvent(KeyTypedEvent& event);
		bool OnWindowResizeEvent(WindowResizeEvent& event);
	private:
		float m_Time = 0.0f;
	};
}