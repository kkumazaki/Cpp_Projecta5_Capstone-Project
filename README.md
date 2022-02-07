# CPPND: Capstone Snake Game Example

This is my repository for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

In the Capstone Project, I extend the Snake game, following the principles I have learned throughout this Nanodegree Program. This project demonstrated that I can independently create applications using a wide range of C++ features.

## Modification Points
I modified the Snake Game as following:
### Step 1. Input name (main.cpp)
I let user to input his/her name, and show it in console.  
Also, I add his/her name on the log file name.

### Step 2. Set speed (main.cpp, game.cpp, game.h, snake.h)
I let user to input the desired speed of the snake.  
I add arguments to the constructors of Game and Snake to modify the speed.

### Step 3. Create file (main.cpp)
I create and save a file when the program finishes.  
The file name contains user name, set speed, and year/date/time.

### Step 4. Set obstacle (game.h, render.cpp, render.h)
I set an obstacle with red color.  
If the snake touch it, the score decreases.

### Step 5. Create another Snake (game.cpp, game.h, render.cpp, render.h, snake.cpp, snake.h)
I create AnotherSnake class which inherits Snake class.  
It moves rondomely, and the score decreases if the snake touch it.

## Rubric Points
### 1. Compiling and Testing (All Rubric Points REQUIRED)  
* The submission must compile and run.  
--> It compile and run without errors.

### 2. Loops, Functions, I/O  
* The project demonstrates an understanding of C++ functions and control structures.  
--> The project code is clearly organized into functions. (all files)

* The project reads data from a file and process the data, or the program writes data to a file.  
--> I added the codes to save log files when the program finishes. (main.cpp)

* The project accepts user input and processes the input.  
--> I added the codes to input user name and snake speed. (main.cpp, game.cpp, game.h, snake.h)

### 3. Object Oriented Programming
* The project uses Object Oriented Programming techniques.  
--> The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks. (all files)

* Classes use appropriate access specifiers for class members.  
--> All class data members are explicitly specified as public or private. (all files)

* Class constructors utilize member initialization lists.  
--> All class members that are set to argument values are initialized through member initialization lists. (all files)

* Classes abstract implementation details from their interfaces.  
--> All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways. (all files)

* Classes encapsulate behavior.  
--> Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions. (all files)

* Classes follow an appropriate inheritance hierarchy.  
--> I added the new class AnotherSnake that inherits Snake class. (snake.cpp, snake.h)



## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
