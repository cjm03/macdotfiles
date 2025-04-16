#include <raylib.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "epic3d");

    Camera3D camera = {0};
    camera.position = (Vector3){10.0, 10.0, 10.0};
    camera.target = (Vector3){0.0, 0.0, 0.0};
    camera.up = (Vector3){0.0, 1.0, 0.0};
    camera.fovy = 45.0;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 cubePosition = {0.0, 0.0, 0.0};

    DisableCursor();

    SetTargetFPS(120);

    while (!WindowShouldClose()) {
        
        UpdateCamera(&camera, CAMERA_FREE);

        if (IsKeyPressed('Z')) camera.target = (Vector3){0.0, 0.0, 0.0};

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawCube(cubePosition, 2.0, 2.0, 2.0, RED);
        DrawCube(cubePosition, 8.0, 8.0, 8.0, SKYBLUE);
        DrawCubeWires(cubePosition, 2.0, 2.0, 2.0, MAROON);

        DrawGrid(10, 1.0);

        EndMode3D();

        DrawFPS(10, 10);

/*        DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5));
        DrawRectangleLines(10, 10, 320, 93, BLUE);

        DrawText("Free camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
        DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY); */

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
