#include "raylib.h"

int main() 
{
    int width            = 800;
    int height           = 450;
    InitWindow( width, height, "Flush Was Here");

    // Circle aka Player
    int circle_radius{25};
    int circle_x{200};
    int circle_y{200};

    // Circle Collision Detection EDGES
    int left_circle_x   {circle_x - circle_radius};
    int right_circle_x  {circle_x + circle_radius};
    int upper_circle_y  {circle_y - circle_radius};
    int bottom_circle_y {circle_y + circle_radius};

    // speed for things
    int direction{10}; // Axe
    int player_speed{10}; // Circle

    // Axe
    int axe_length{50};
    int axe_x{400};
    int axe_y{0};

    // Axe Collision Detection EDGES
    int left_axe_x   {axe_x};
    int right_axe_x  {axe_x + axe_length};
    int upper_axe_y  {axe_y};
    int bottom_axe_y {axe_x + axe_length};        

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {


        BeginDrawing();
        ClearBackground(WHITE);

        // Game Logic 
        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

        axe_y += direction;
        if (axe_y > height || axe_y < width)
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
