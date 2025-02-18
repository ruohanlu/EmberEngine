#include <Ember.h>

#include "imgui/imgui.h"

class ExampleLayer : public Ember::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}
	void OnUpdate() override
	{
		if (Ember::Input::IsKeyPressed(EB_KEY_TAB))
			EB_TRACE("Tab key is pressed (poll)!");
	}
	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}
	void OnEvent(Ember::Event& event) override
	{
		if (event.GetEventType() == Ember::EventType::KeyPressed)
		{
			Ember::KeyPressedEvent& e = (Ember::KeyPressedEvent&)event;
			if (e.GetKeyCode() == EB_KEY_TAB)
				EB_TRACE("Tab key is pressed (event)!");
			EB_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};


class Sandbox : public Ember::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Ember::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Ember::Application* Ember::CreateApplication()
{
	return new Sandbox();
}