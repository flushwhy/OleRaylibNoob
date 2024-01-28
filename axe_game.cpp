#include "raylib.h"

extern "C" {
    int main() 
    {
        int width            = 800;
        int height           = 450;
        InitWindow( width, height, "Flush Was Here");


        int circle_x{200};
        int circle_y{200};

        // speed for things
        int direction{10}; // Axe
        int player_speed{10}; // Circle


        int axe_x{400};
        int axe_y{0};


        SetTargetFPS(60);
        while (WindowShouldClose() == false)
        {
            BeginDrawing();
            ClearBackground(WHITE);

            // Game Logic 
            DrawCircle(circle_x, circle_y, 25, BLUE);
            DrawRectangle(axe_x, axe_y, 50, 50, RED);

            axe_y += direction;
            if (axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circle_x < 350)
            {
                circle_x += player_speed;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= player_speed;
            }


            EndDrawing();
        }
    }
}