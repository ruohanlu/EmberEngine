#include "ebpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Ember {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		EB_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EB_CORE_ASSERT(status, "Failed to initialize Glad!");

		EB_CORE_INFO("OpenGL Info:");
		EB_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		EB_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		EB_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}