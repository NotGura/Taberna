#pragma once

#ifdef TB_PLATFORM_WINDOWS

extern Taberna::Application* Taberna::CreateApplication();

int main() {

	auto app = Taberna::CreateApplication();
	app->run();
	delete app;
}
#else
#error Project only works on windows

#endif