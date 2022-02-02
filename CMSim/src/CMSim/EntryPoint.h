#pragma once

#ifdef CMS_PLATFORM_WINDOWS
#include "Core.h"

extern CMSim::Application* CMSim::CreateApplication();

int main(int argc, char** arcv)
{
	CMSim::Log::Init();
	CMS_CORE_WARN("Core logger initialized");
	CMS_INFO("Client logger initialized ");

	auto app = CMSim::CreateApplication();
	CMS_INFO("Application Initialized");

	app->Run();
	delete app;

	return 0;
}

#endif