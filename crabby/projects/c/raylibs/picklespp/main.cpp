#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <vector>

const int level[] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 0, 1, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
};

typedef struct Sprite {
    Texture2D texture;
    Rectangle source_rect;
    Rectangle dest_rect;
    Vector2 vel;
} Sprite;

void movePlayer(Sprite* player)
{
    player->vel.x = 0.0;
    if (IsKeyDown(KEY_D)) {
        player->vel.x = 200.0;
    }
    if (IsKeyDown(KEY_A)) {
        player->vel.x = -200.0;
    }
    if (IsKeyPressed(KEY_SPACE)) {
        player->vel.y = -1000.0;
    }
}

void applyGravity(Sprite* sprite)
{
    sprite->vel.y += 100.0;
    if (sprite->vel.y > 600.0) {
        sprite->vel.y = 600.0;
    }
}

void applyVelocity(Sprite* sprite)
{
    sprite->dest_rect.x += sprite->vel.x * GetFrameTime();
    sprite->dest_rect.y += sprite->vel.y * GetFrameTime();
}

std::vector<Sprite> load_level(Texture2D temp_texture) {
    std::vector<Sprite> sprites;

    const int level_width = 8;
    const int level_height = 5;

    for (size_t i = 0; i < level_height * level_width; i++) {
        size_t x = i % level_width;
        size_t y = i / level_width;

        if (level[i] > 0) {
            sprites.push_back((Sprite){.texture = temp_texture,
                                       .dest_rect = (Rectangle){.x = x * 32.0f,
                                                                .y = y * 32.0f,
                                                                .width = 32.0f,
                                                                .height = 32.0f}});
        }
    }
    return sprites;
}


int main()
{
    
    // Init window
    
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "epicness");
    
    // Load texture, must be after window initialization
    Vector2 origin = {0, 0};
    Texture2D pickle_idle = LoadTexture("assets/pickle.png");
    Texture2D tiles_texture = LoadTexture("assets/tileset.png");

    Sprite player = (Sprite) {
        .texture = pickle_idle,
        .source_rect = (Rectangle) {
            .x =        0.0,
            .y =        0.0,
            .width =    64.0,
            .height =   64.0,
        },
        .dest_rect = (Rectangle) {
            .x =        10.0,
            .y =        100.0,
            .width =    100.0,
            .height =   100.0,
        }
    };

    std::vector<Sprite> level_tiles = load_level(tiles_texture);

    SetTargetFPS(60);
    // begin
    while (!WindowShouldClose()) {
        // updating

        movePlayer(&player);
        applyGravity(&player);

        // post movement updates
        applyVelocity(&player);
        
        // keep player from falling hack
        if (player.dest_rect.y > GetScreenHeight() - player.dest_rect.height) {
            player.dest_rect.y = GetScreenHeight() - player.dest_rect.height;
        }
        // drawing
        BeginDrawing();

        ClearBackground(SKYBLUE);

        // draw the level tiles
        for (const auto &tile : level_tiles) {
            DrawTexturePro(tile.texture, {0, 0, 16, 16}, tile.dest_rect, {0, 0}, 0.0, RAYWHITE);
        }

        //DrawTexture(pickle_idle, 10.0, 100.0, RAYWHITE);
        DrawTexturePro(player.texture, player.source_rect, player.dest_rect, origin, 0.0, RAYWHITE);

        EndDrawing();
        




    }
    
    UnloadTexture(pickle_idle);
    UnloadTexture(tiles_texture);

    return 0;
}
