#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

// window
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// player
#define PLAYER_SIZE 32
#define PLAYER_SPEED 4

// map
#define TILE_SIZE 32
#define MAP_WIDTH 25
#define MAP_HEIGHT 19
int level[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// collision function
bool isWall(int x, int y)
{
    int tile_x = x / TILE_SIZE;
    int tile_y = y / TILE_SIZE;
    if (tile_x < 0 || tile_y < 0 || tile_x >= MAP_WIDTH || tile_y >= MAP_HEIGHT) {
        return true;
    }
    return level[tile_y][tile_x] == 1;
}

int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Rect player = {TILE_SIZE * 2, TILE_SIZE * 2, PLAYER_SIZE, PLAYER_SIZE};
    bool running = true;
    SDL_Event event;
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        // movement
        int new_x = player.x;
        int new_y = player.y;
        if (keystates[SDL_SCANCODE_W]) new_y -= PLAYER_SPEED;
        if (keystates[SDL_SCANCODE_S]) new_y += PLAYER_SPEED;
        if (keystates[SDL_SCANCODE_A]) new_x -= PLAYER_SPEED;
        if (keystates[SDL_SCANCODE_D]) new_x += PLAYER_SPEED;

        if (!isWall(new_x, player.y) && !isWall(new_x + PLAYER_SIZE - 1, player.y) && !isWall(new_x, player.y + PLAYER_SIZE - 1) && !isWall(new_x + PLAYER_SIZE - 1, player.y + PLAYER_SIZE - 1)) {
            player.x = new_x;
        }
        if (!isWall(player.x, new_y) && !isWall(player.x + PLAYER_SIZE - 1, new_y) && !isWall(player.x, new_y + PLAYER_SIZE - 1) && !isWall(player.x + PLAYER_SIZE - 1, new_y + PLAYER_SIZE - 1)) {
            player.y = new_y;
        }

        // render
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_RenderClear(renderer);
    
        // draw map tiles
        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                SDL_Rect tile_rect = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
                if (level[y][x] == 1) {
                    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
                } else {
                    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
                }
                SDL_RenderFillRect(renderer, &tile_rect);
            }
        }

        // draw player
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
