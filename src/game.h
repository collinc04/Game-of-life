#pragma once

#include <vector>

// make game info global
inline constexpr int width = 70;
inline constexpr int height = 70;
constexpr int cell_size = 20;

// Game board global to be accessed by gui
extern std::vector<std::vector<bool>> board;
extern std::vector<std::vector<bool>> board_next;

//functions
void toggle(int x, int y);
void step();