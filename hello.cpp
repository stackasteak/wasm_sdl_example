#include <emscripten.h>
#include <SDL.h>

struct allstate{
  SDL_Window * window;
  SDL_Renderer * renderer;

  allstate(SDL_Window * w, SDL_Renderer * r) : window(w), renderer(r){};
};



void mainloop(allstate * state){
  SDL_Rect r;
  r.x = 100;
  r.y = 100;
  r.w = 50;
  r.h = 50;
  
  SDL_SetRenderDrawColor(state->renderer, 200, 0, 0, 0);
  SDL_RenderFillRect(state->renderer, &r);
};

int main() {

  SDL_Init(SDL_INIT_TIMER || SDL_INIT_VIDEO || SDL_INIT_EVENTS);
  SDL_Window * window;
  SDL_Renderer * renderer;

  allstate state(window,renderer);

  SDL_CreateWindowAndRenderer(400,400,0,&(state.window),&(state.renderer));
  emscripten_set_main_loop_arg(mainloop, &state, 0, 1);


  return 0;
}

