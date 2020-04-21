#include <Solis.h>

class SandBox : public Solis::Application
{
public:
	SandBox()
	{
		
	}

	~SandBox()
	{

	}
};

Solis::Application* Solis::CreateApplication()
{
	return new SandBox;
}