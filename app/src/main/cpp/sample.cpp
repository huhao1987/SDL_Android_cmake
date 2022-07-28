//
//It just a simple sample to show a picture with SDL
// Created by Hao on 2022/7/28.
//
#include <SDL.h>

int main(int argc, char *argv[]) {

    SDL_Window *win = 0;
    SDL_Renderer *ren = 0;
    SDL_Surface *bmp = 0;
    SDL_Texture* tex = 0;
    SDL_bool done = SDL_FALSE;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
        return 1;
    }
    win = SDL_CreateWindow("Hello World!", 0, 0, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
    if (win == 0){
        return 1;
    }
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == 0){
        return 1;
    }

    bmp = SDL_LoadBMP("a.bmp");
    if (!bmp) {
        return 1;
    }
    tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if (!tex) {
        return 1;
    }

    while (!done) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT || event.type == SDL_KEYDOWN || event.type == SDL_FINGERDOWN) {
                SDL_Log("theevent:%s","onclick");
            }
        }

        SDL_SetRenderDrawColor(ren, 0xA0, 0xA0, 0xA0, 0xFF);
        SDL_RenderCopy(ren, tex, NULL, NULL);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;}