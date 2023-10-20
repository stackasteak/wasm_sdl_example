#include <emscripten.h>
#include <SDL.h>

struct allstate{
  SDL_Window * window;
  SDL_Renderer * renderer;

  allstate(SDL_Window * w, SDL_Renderer * r) : window(w), renderer(r){};
};



void mainloop(void * state){
  SDL_Rect r;
  r.x = 100;
  r.y = 100;
  r.w = 50;
  r.h = 50;

  auto state1 = static_cast<allstate*>(state);
  
  SDL_SetRenderDrawColor(state1->renderer, 200, 0, 0, 255);
  SDL_RenderFillRect(state1->renderer, &r);

  SDL_SetRenderTarget(state1->renderer, NULL);
  SDL_RenderPresent(state1->renderer);
};

int main() {

  SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS);
  SDL_Window * window;
  SDL_Renderer * renderer;

  allstate state(window,renderer);

  SDL_CreateWindowAndRenderer(800,400,0,&(state.window),&(state.renderer));
  emscripten_set_main_loop_arg(mainloop, &state, 0, 1);


  return 0;
}
