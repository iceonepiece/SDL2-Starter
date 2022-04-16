#include "Application.h"

Application::Application(int width, int height)
	: m_running(false)
	, m_screenWidth(width)
	, m_screenHeight(height)
{
}

Application::~Application()
{

}

bool Application::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	m_window = SDL_CreateWindow("SDL2-Starter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenWidth, m_screenHeight, NULL);

	if (!m_window)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!m_renderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	return true;
}

void Application::Run()
{
	m_running = true;
	m_ticks = SDL_GetTicks();

	while (m_running)
	{
		ProcessInput();
		Update();
		Render();
	}
}

void Application::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void Application::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				m_running = false;
				break;
		}
	}
}

void Application::Update()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_ticks + 16))
		;

	float deltaTime = (SDL_GetTicks() - m_ticks) / 1000.0f;
	if (deltaTime > 0.05f)
		deltaTime = 0.05f;

	m_ticks = SDL_GetTicks();

	// Update anything here...
}

void Application::Render()
{
	SDL_SetRenderDrawColor(m_renderer, 69, 82, 109, 255);
	SDL_RenderClear(m_renderer);

	// Draw anything here...

	SDL_RenderPresent(m_renderer);
}
