#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>

#define MAX_TUBES 100
#define TUBES_WIDTH 80

typedef struct Sprite {
    Texture2D texture;
    Rectangle source_rect;
    Rectangle dest_rect;
    Vector2 vel;
} Sprite;

typedef struct Tubes {
    Rectangle rec;
    Color color;
    bool active;
} Tubes;

static const int scrW = 800;
static const int scrH = 450;

static bool gameOver = false;
static bool pause = false;
static int score = 0;
static int hiScore = 0;

static Sprite sprite = {0};
static Tubes tubes[MAX_TUBES * 2] = {0};
static Vector2 tubesPos[MAX_TUBES] = {0};
static int tubesSpeedX = 0;
static bool superfx = false;

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


int main()
{
    // Init window
    //-----------------------------------------------------------
    InitWindow(scrW, scrH, "flappy pickles");
    
    // Load texture, must be after window initialization

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

        //DrawTexture(pickle_idle, 10.0, 100.0, RAYWHITE);
        DrawTexturePro(player.texture, player.source_rect, player.dest_rect, origin, 0.0, RAYWHITE);

        EndDrawing();
        




    }
    
    UnloadTexture(pickle_idle);


    return 0;
}


void InitGame(void)
{
    Vector2 origin = {0, 0};
    Texture2D pickle_idle = LoadTexture("assets/pickle.png");

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
    tubesSpeedX = 2;

    for (int i = 0; i < MAX_TUBES; i++) {
        tubesPos[i].x = 400 + 280 * i;
        tubesPos[i].y = -GetRandomValue(0, 120);
    }

    for (int i = 0; i < MAX_TUBES * 2; i += 2) {
        tubes[i].rec.x = tubesPos[i / 2].x;
        tubes[i].rec.y = tubesPos[i / 2].y;
        tubes[i].rec.width = TUBES_WIDTH;
        tubes[i].rec.height = 255;

        tubes[i + 1].rec.x = tubesPos[i / 2].x;
        tubes[i + 1].rec.y = 600 + tubesPos[i / 2].y - 255;
        tubes[i + 1].rec.width = TUBES_WIDTH;
        tubes[i + 1].rec.height = 255;

        tubes[i / 2].active = true;
    }
    score = 0;
    gameOver = false;
    superfx = false;
    pause = false;
}

void UpdateGame(void)
{
    if (!gameOver) {
        if (IsKeyPressed('P')) pause = !pause;
        if (!pause) {
            for (int i = 0; i < MAX_TUBES; i++) tubesPos[i].x -= tubesSpeedX;
            for (int i = 0; i < MAX_TUBES * 2; i += 2) {
                tubes[i].rec.x = tubesPos[i / 2].x;
                tubes[i + 1].rec.x = tubesPos[i / 2].x;
            }
            if (IsKeyDown(KEY_SPACE) && !gameOver) sprite.
        }
    }
}


