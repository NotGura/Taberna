#include <Taberna.h>

class Sandbox : public Taberna::Application
{
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Taberna::Application* Taberna::CreateApplication() {
	return new Sandbox();
}

