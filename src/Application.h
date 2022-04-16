#pragma once

#include <SDL2/SDL.h>

class Application
{
public:
	Application(int width, int height);
	~Application();

	bool Initialize();
	void Run();
	void Shutdown();

private:
	bool m_running;
	int m_screenWidth;
	int m_screenHeight;
	int m_ticks;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	void ProcessInput();
	void Update();
	void Render();
};
