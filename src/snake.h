#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

#include <random>// Step 5. Create another Snake (Inheritance)

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  //Snake(int grid_width, int grid_height)
  Snake(int grid_width, int grid_height, float speedSelect) //Step 2. Set speed
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        //head_y(grid_height / 2) {}
        head_y(grid_height / 2),
        speed(speedSelect){}//Step 2. Set speed

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  //float speed{0.1f};
  float speed;//Step 2. Set speed
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

// Step 5. Create another Snake (Inheritance)
class AnotherSnake: public Snake {
 public:
  AnotherSnake(int grid_w, int grid_h, float speedS)
      //: grid_width(grid_width),
      //  grid_height(grid_height),
      //  head_x(grid_width / 4),
      //  head_y(grid_height / 4),
      //  speed(speedSelect){} // Error occured
      :Snake(grid_w, grid_h, speedS)
      {
        grid_width = grid_w;
        grid_height = grid_h;
        head_x = grid_width / 4;
        head_y = grid_height / 4;
        speed = 0.02f;
      }


  float speed;
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

  void AnotherUpdate();

 private:
  void AnotherUpdateHead();
  void AnotherUpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif