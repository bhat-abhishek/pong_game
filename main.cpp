#include <iostream>
#include <raylib.h>

using namespace std;

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

int player_score = 0;
int cpu_score = 0;

class Ball
{
protected:
    void ResetBall()
    {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        int speed_choices[2] = {-1, 1};
        speed_x *= speed_choices[GetRandomValue(0, 1)];
        speed_y *= speed_choices[GetRandomValue(0, 1)];
    }

public:
    float x, y; // positions
    int radius;
    int speed_x, speed_y;

    void Draw() {
        DrawCircle(x, y, radius, WHITE);
    }

    void Update(){
        x += speed_x;
        y += speed_y;

        if ( y + radius >= GetScreenHeight() || y - radius <= 0 ) { 
            speed_y *= -1;
        }

        if (x + radius >= GetScreenWidth())
        {
            cpu_score++;
            ResetBall();
        }

        if (x - radius <= 0)
        {
            player_score++;
            ResetBall();
        }
    }

};


class Paddle{ 
protected:
    void LimitMovement() {
        if (y <= 0)
        {
            y = 0;
        }

        if (y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x,y;
    float width, height;
    int speed;

    void Draw(){
        DrawRectangleRounded(Rectangle{x, y, width, height},0.8,0, WHITE);
    }
    
    void Update() { 
        if(IsKeyDown(KEY_W)) { 
            y = y - speed;
        }

        if(IsKeyDown(KEY_S)) { 
            y = y + speed;
        }
        
        LimitMovement();
       
    }

};

class CpuPaddle: public Paddle{
public:
    void Update(int ball_y) { 

        if( y + height /2 > ball_y ) { 
            y = y - speed;
        }

        if( y +  height /2 < ball_y ) { 
            y = y + speed;
        }

        LimitMovement();
    }
};

Ball ball;
Paddle player_paddle;
CpuPaddle cpu_paddle;

int main()
{
    // screen size
    const int screen_width = 1280;
    const int screen_height = 800;

    // pong properties
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.radius = 20;
    ball.speed_x = 12;
    ball.speed_y = 12;

    player_paddle.x = 10;
    player_paddle.y = screen_height / 2 - 60;
    player_paddle.height = 120;
    player_paddle.width = 20;
    player_paddle.speed = 10;

    cpu_paddle.x = screen_width - 35;
    cpu_paddle.y = screen_height / 2 - 60;
    cpu_paddle.height = 120;
    cpu_paddle.width = 20;
    cpu_paddle.speed = 10;

    InitWindow(screen_width, screen_height, "Pong Game");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
       
        ball.Update();
        player_paddle.Update();
        cpu_paddle.Update(ball.y);

        if (CheckCollisionCircleRec({ ball.x, ball.y },ball.radius, { player_paddle.x, player_paddle.y, player_paddle.width, player_paddle.height})) { 
            ball.speed_x *= -1;
        }

        if (CheckCollisionCircleRec({ball.x, ball.y}, ball.radius, {cpu_paddle.x, cpu_paddle.y, cpu_paddle.width, cpu_paddle.height}))
        {
            ball.speed_x *= -1;
        }

        ClearBackground(Dark_Green);
        DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
        DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);

        ball.Draw();
        player_paddle.Draw();
        cpu_paddle.Draw();

        DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}