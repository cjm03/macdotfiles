#include <raylib.h>
#include <raymath.h>

#define MAX_COLUMNS 20

//----------------------------------------------------------
// Program main entry point
//----------------------------------------------------------
int main(void)
{
    // Initialization
    // ------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "3dcam FPP");

    // Define camera for 3d view (position, target, up vector)
    Camera camera = { 0 };
    camera.position = (Vector3){0.0f, 2.0f, 4.0f};
    camera.target = (Vector3){0.0f, 2.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    int cameraMode = CAMERA_FIRST_PERSON;

    // generate random columns
    float heights[MAX_COLUMNS] = {0};
    Vector3 positions[MAX_COLUMNS] = {0};
    Color colors[MAX_COLUMNS] = {0};

    for (int i = 0; i < MAX_COLUMNS; i++) {
        heights[i] = (float)GetRandomValue(1, 12);
        positions[i] = (Vector3){(float)GetRandomValue(-15, 15), heights[i]/2.0f, (float)GetRandomValue(-15, 15)};
        colors[i] = (Color){GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255};
    }
    DisableCursor();
    SetTargetFPS(60);
    //---------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        // -----------------------------------------------------------------------
        // Switch camera mode
        if (IsKeyPressed(KEY_ONE)) {
            cameraMode = CAMERA_FREE;
            camera.up = (Vector3){0.0f, 1.0f, 0.0f};
        }
        if (IsKeyPressed(KEY_TWO)) {
            cameraMode = CAMERA_FIRST_PERSON;
            camera.up = (Vector3){0.0f, 1.0f, 0.0f};
        }
        if (IsKeyPressed(KEY_THREE)) {
            cameraMode = CAMERA_THIRD_PERSON;
            camera.up = (Vector3){0.0f, 1.0f, 0.0f};
        }
        if (IsKeyPressed(KEY_FOUR)) {
            cameraMode = CAMERA_ORBITAL;
            camera.up = (Vector3){0.0f, 1.0f, 0.0f};
        }
        if (IsKeyPressed(KEY_P)) {
            if (camera.projection == CAMERA_PERSPECTIVE) {
                cameraMode = CAMERA_THIRD_PERSON; 
                camera.position = (Vector3){ 0.0f, 2.0f, -100.0f };
                camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
                camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
                camera.projection = CAMERA_ORTHOGRAPHIC;
                camera.fovy = 20.0f; // near plane width in CAMERA_ORTHOGRAPHIC
                CameraYaw(&camera, -135 * DEG2RAD, true);
                CameraPitch(&camera, -45 * DEG2RAD, true, true, false);
            } else if (camera.projection == CAMERA_ORTHOGRAPHIC) {
                // Reset to default view
                cameraMode = CAMERA_THIRD_PERSON;
                camera.position = (Vector3){ 0.0f, 2.0f, 10.0f };
                camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
                camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
                camera.projection = CAMERA_PERSPECTIVE;
                camera.fovy = 60.0f;
            }
        }
        UpdateCamera(&camera, cameraMode);
    }
}
