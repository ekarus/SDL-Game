#include <SDL.h>

int main(int arhc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = SDL_CreateWindow("Game",
					SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
					640,640,
					SDL_WINDOW_SHOWN);
	SDL_Renderer *rend = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	bool run = true;
	SDL_Event event;

	while(run){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				run = false;
			}
		}

		SDL_RenderClear(rend);

		//

		SDL_RenderPresent(rend);
	}
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(rend);

	SDL_Quit();

	return 0;
}