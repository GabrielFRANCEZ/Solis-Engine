#pragma once

#include <stdio.h>

#ifdef SL_PLATFORM_WINDOWS

extern Solis::Application* Solis::CreateApplication();

int main()
{
	printf("Solis Engine\n");

	Solis::Log::Init();
	float v = 0.01;
	SL_CORE_INFO("Version {0}", v);
	SL_CORE_WARN("Initialized Log");
	float version = 0.1f;
	SL_CLIENT_INFO("version {0} ", version);

	auto app = Solis::CreateApplication();
	app->Run();
	delete app;
} 


#endif