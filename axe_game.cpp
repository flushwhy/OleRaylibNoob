#include "raylib.h"

int main()
{
    // window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Flush Was here!");

    // circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    // circle edges
    int left_circle_x{circle_x - circle_radius};
    int right_circle_x{circle_x + circle_radius};
    int upper_circle_y{circle_y - circle_radius};
    int bottom_circle_y{circle_y + circle_radius};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    // axe edges
    int left_axe_x{axe_x};
    int right_axe_x{axe_x + axe_length};
    int upper_axe_y{axe_y};
    int bottom_axe_y{axe_y + axe_length};

    int direction{10};

    bool collision_with_axe{true};

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            // Game logic begins

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            // move the axe
            axe_y += direction;
            if (axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

            // Game logic ends
        }

        
        EndDrawing();
    }
}
