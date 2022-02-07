#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

//Step 1. Input name and create file
#include <fstream>
#include <iomanip>

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  //Step 1. Input name
  int nameLength = 20;
  char name[nameLength];
  std::cout << "Please input your name." << std::endl;
  std::cin >> std::setw(nameLength) >> name;
  std::string nameString(name);
  std::cout << "Well come, " << nameString << ". Please enjoy!" << std::endl;

  //Step 2. Set speed
  int select;
  float speedSelect;
  std::string speedStr;
  std::cout << "Which speed do you prefer? 1:Fast, 2:Medium, 3:Slow" << std::endl;
  std::cin >> select;
  if (select < 1 || select > 3){
    std::cout << "Please select from 1 or 2 or 3" << std::endl;
    std::cin >> select;
  }
  if (select == 1){
    speedSelect = 0.2f;
    speedStr = "Fast";
  }
  else if (select == 2){
    speedSelect = 0.1f;
    speedStr = "Medium";
  }
  else if (select == 3){
    speedSelect = 0.05f;
    speedStr = "Slow";
  }
  else{
    std::cout << "Invalid speed select. It's set to 2:Medium" << std::endl;
    speedSelect = 0.1f;
    speedStr = "Medium";
  }
  std::cout << "selected: " << speedStr << std::endl;

  //Step 3. Create file
  time_t t = time(nullptr);
  const tm* localTime = localtime(&t);
  std::stringstream s;
  s << localTime->tm_year + 1900 << "-";
  s << std::setw(2) << std::setfill('0') << localTime->tm_mon + 1;
  s << std::setw(2) << std::setfill('0') << localTime->tm_mday << "-";
  s << std::setw(2) << std::setfill('0') << localTime->tm_hour;
  s << std::setw(2) << std::setfill('0') << localTime->tm_min;
  std::ofstream writingFile;
  std::string filename = "../result/" + nameString + "_speed:" + speedStr + "_" + s.str() + ".txt";
  writingFile.open(filename, std::ios::out);

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  //Game game(kGridWidth, kGridHeight);
  Game game(kGridWidth, kGridHeight, speedSelect);//Step 2. Set speed
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  //Step 1. Input name and create file
  writingFile << "Score: " << game.GetScore() << std::endl;
  writingFile.close();

  return 0;
}