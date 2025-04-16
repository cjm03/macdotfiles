#include <raylib.h>
#include <stdio.h>

typedef struct Sprite {
    Texture2D texture;
    Rectangle source_rect;
    Rectangle dest_rect;
    Vector2 vel;
} Sprite;

void movePlayer(Sprite* player) {
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

void applyGravity(Sprite* sprite) {
    sprite->vel.y += 100.0;
    if (sprite->vel.y > 600.0) {
        sprite->vel.y = 600.0;
    }
}

void applyVelocity(Sprite* sprite) {
    sprite->dest_rect.x += sprite->vel.x * GetFrameTime();
    sprite->dest_rect.y += sprite->vel.y * GetFrameTime();
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "epic");

    Vector2 origin = {0, 0};
    Texture2D pickle_idle = LoadTexture("/home/crab/crabby/projects/c/ray/assets/pickle.png");

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

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        movePlayer(&player);
        applyGravity(&player);

        applyVelocity(&player);

        if (player.dest_rect.y > GetScreenHeight() - player.dest_rect.height) {
            player.dest_rect.y = GetScreenHeight() - player.dest_rect.height;
        }
        BeginDrawing();

        ClearBackground(SKYBLUE);

        DrawTexturePro(player.texture, player.source_rect, player.dest_rect, origin, 0.0, RAYWHITE);

        EndDrawing();
    }
    UnloadTexture(pickle_idle);

    return 0;
}