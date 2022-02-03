#include <CMSim.h>

class ExampleLayer : public CMSim::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//CMS_INFO("ExampleLayer::Update");
	}

	void OnEvent(CMSim::Event& event) override
	{
		//CMS_TRACE("{0}", event);
	}
};

class  FreeTest : public CMSim::Application
{
public:
	FreeTest()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new CMSim::ImGuiLayer());
	}
	~FreeTest()
	{
		
	}
};

CMSim::Application* CMSim::CreateApplication()
{
	return new FreeTest();
}