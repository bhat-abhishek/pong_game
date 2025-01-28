# Pong Game

A classic Pong game implementation using C++ and Raylib. This project serves as a learning resource for game development fundamentals.

## Description

This is a modern recreation of the classic Pong arcade game where players can compete against a CPU opponent. The game features a clean, minimalist design with a green color scheme and intuitive controls.

## Features

- Player vs CPU gameplay
- Score tracking system
- Smooth paddle movement
- Ball physics with speed and direction changes
- Clean visual design with custom color palette
- Screen resolution: 1280x800

## Dependencies

- C++ compiler
- Raylib graphics library
- Standard C++ libraries

## Controls

- **W Key**: Move player paddle up
- **S Key**: Move player paddle down
- **ESC Key**: Exit game

## Game Objects

### Ball
- Moves across the screen with constant speed
- Bounces off paddles and screen boundaries
- Resets to center with random direction when scoring occurs

### Player Paddle
- Located on the left side of the screen
- Controlled using W and S keys
- Limited movement within screen boundaries

### CPU Paddle
- Located on the right side of the screen
- Automatically tracks the ball's vertical position
- Features basic AI movement

## Gameplay Mechanics

1. The ball moves continuously across the screen
2. Players score points when the ball passes the opponent's paddle
3. The ball resets to center position after each point
4. Paddles can move up and down within screen boundaries
5. Ball direction changes upon collision with paddles or screen edges

## Technical Details

### Classes

1. **Ball Class**
   - Handles ball movement and collision
   - Manages scoring system
   - Controls ball reset functionality

2. **Paddle Class**
   - Base class for paddle objects
   - Handles basic paddle drawing and movement
   - Implements boundary checking

3. **CpuPaddle Class**
   - Inherits from Paddle class
   - Implements basic AI behavior
   - Tracks ball position for movement

### Color Scheme

- Dark Green: RGB(20, 160, 133)
- Green: RGB(38, 185, 154)
- Light Green: RGB(129, 204, 184)
- Yellow: RGB(243, 213, 91)

## Performance

- Runs at 60 FPS
- Screen resolution: 1280x800
- Smooth gameplay with optimized collision detection

## Contributing

Feel free to fork this project and submit improvements through pull requests. Some areas that would benefit from contributions:

- Additional game modes
- Enhanced AI behavior
- Visual improvements
- Sound implementation
- Menu system
