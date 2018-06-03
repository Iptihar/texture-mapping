#include <iostream>
#include <SDL2/SDL.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

static const int DISPLAY_WIDTH = 800;
static const int DISPLAY_HEIGHT = 600;

int main(int argc, char** argv)
{
	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "Iptihar_Osman_HW5");
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	Mesh teapot("teapot2.obj");
	Shader shader("basicShader");
	Texture texture("bricks.png");
	Camera camera(glm::vec3(10.0f, 50.0f, 100.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	Transform transform;
	
	SDL_Event e;
	bool isRunning = true;
	float counter = 0.0f;
	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				isRunning = false;
		}

		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);

		shader.Bind();
		texture.Bind();
		shader.Update(transform, camera);
		teapot.Draw();

		display.SwapBuffers();
		SDL_Delay(1);
	}

	return 0;
}
