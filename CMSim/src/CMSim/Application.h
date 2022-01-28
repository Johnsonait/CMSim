#pragma once

#include "Core.h"

namespace CMSim {

	class CMSIM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//Defined by client
	Application* CreateApplication();

}