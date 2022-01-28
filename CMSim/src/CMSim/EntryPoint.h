#pragma once

#ifdef CMS_PLATFORM_WINDOWS

extern CMSim::Application* CMSim::CreateApplication();

int main(int argc, char** arcv)
{

	auto app = CMSim::CreateApplication();

	app->Run();
	delete app;

	return 0;
}

#endif