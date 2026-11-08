#pragma once

#include <vector>

// make game info global
inline constexpr int width = 20;
inline constexpr int height = 20;
constexpr int cell_size = 20;
extern int generation;

// Game board global to be accessed by gui
extern std::vector<std::vector<bool>> board;
extern std::vector<std::vector<bool>> board_next;