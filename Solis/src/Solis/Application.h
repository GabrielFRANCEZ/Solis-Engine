#pragma once
#include "Core.h"
namespace Solis
{
	class SOLIS_API Application
	{
	public: 
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

