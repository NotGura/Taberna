#pragma once
#include "Core.h"


namespace Taberna {

	class TABERNA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
		//To be defined in client
	};

	Application* CreateApplication();
}