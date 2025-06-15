#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main()
{
    InitWindow(1280, 720, "raylib/raygui test macOS");
    SetExitKey(KEY_Q);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        GuiButton((Rectangle){ 10, 10, 100, 40 }, "Hello");
        GuiButton((Rectangle){ 120, 10, 100, 40 }, "Welcome");
        GuiButton((Rectangle){ 230, 10, 100, 40 }, "to");
        GuiButton((Rectangle){ 340, 10, 100, 40 }, "raygui!");
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
