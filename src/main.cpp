#include "raylib.h"
#include "entity.h"
#include "world.h"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(600, 600, "fysix ngin");

    World world({0, 980.0f});

    /**for (int x = 0; x<20; x++){
        world.addEntity(Entity(
            2.0f, {400+float(x*10), 400}, STATIC_BODY));
    }**/
  
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            world.addEntity(Entity(float(GetRandomValue(1,20)), mousePos, RIGID_BODY, GetRandomValue(5,20), {GetRandomValue(125,250),GetRandomValue(125,255),GetRandomValue(125,255),255}));
        }
        else if(IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            world.addEntity(Entity(50.0f, mousePos, STATIC_BODY,6, RAYWHITE ));
        }
        world.update(dt);

        BeginDrawing();
            ClearBackground((Color){15,2,26});
            world.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}