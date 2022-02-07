#include "game.h"
#include <iostream>
#include "SDL.h"

//Game::Game(std::size_t grid_width, std::size_t grid_height)
//    : snake(grid_width, grid_height),
Game::Game(std::size_t grid_width, std::size_t grid_height, float speedSelect)//Step 2. Set speed
    : snake(grid_width, grid_height, speedSelect),//Step 2. Set speed
      another_snake(grid_width, grid_height, speedSelect),//Step 5. Create another Snake
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
  PlaceObstacle();//Step4. Set obstacle
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    //renderer.Render(snake, food);
    //renderer.Render(snake, food, obstacle); //Step4. Set obstacle
    renderer.Render(snake, food, obstacle, another_snake); //Step 5. Create another Snake

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);

    // If the location is same as obstacle, re-locate.
    if (x == obstacle.x && y == obstacle.y){
      x = random_w(engine);
      y = random_h(engine);
    }

    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::PlaceObstacle() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);

    // If the location is same as food, re-locate.
    if (x == food.x && y == food.y){
      x = random_w(engine);
      y = random_h(engine);
    }

    // Check that the location is not occupied by a snake item before placing
    // obstacle.
    if (!snake.SnakeCell(x, y)) {
      obstacle.x = x;
      obstacle.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();
  another_snake.AnotherUpdate();//Step 5. Create another Snake

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    PlaceObstacle();
    // Grow snake and increase speed.
    snake.GrowBody();
    another_snake.GrowBody();
    snake.speed += 0.02;
  }

  //Step4. Set obstacle
  // Check if there's obstacle over here
  if (obstacle.x == new_x && obstacle.y == new_y) {
    score--;//decrease the score for penalty
    PlaceFood();
    PlaceObstacle();
    //increase speed.
    snake.speed += 0.02;
  }

  //Step 5. Create another Snake
  if (another_snake.head_x == new_x && another_snake.head_y == new_y) {
    score--;//decrease the score for penalty
    PlaceFood();
    PlaceObstacle();
    //increase speed.
    snake.speed += 0.02;
  } 

}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }