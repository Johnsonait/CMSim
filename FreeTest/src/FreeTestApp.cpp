#include <CMSim.h>

class FreeTest : public CMSim::Application
{
public:
	FreeTest()
	{

	}
	~FreeTest()
	{
		
	}
};

CMSim::Application* CMSim::CreateApplication()
{
	return new FreeTest();
}