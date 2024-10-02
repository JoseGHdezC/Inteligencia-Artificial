#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>
#include <iostream>
#include <fstream>

// indica pasillo
#define PASS_ID  0
// indica pared
#define WALL_ID  1
// indica camino de salida
#define PATH_ID  2
// indica inicio del laberinto
#define START_ID 3
// indica la salida del laberinto
#define END_ID   4

// Maze character for printing
#define WALL_CHR  "█"
#define PASS_CHR  " "
#define PATH_CHR  "*"
#define START_CHR "S"
#define END_CHR   "E"

class Maze {
 public:
  Maze(const std::string&);

  unsigned get_row() { return row_size_; }
  unsigned get_column() { return column_size_; }
  std::vector<std::vector<char>>& get_maze() { return maze_;}

  friend std::ostream& operator<<(std::ostream&, Maze&);

 private:
  std::vector<std::vector<char>> maze_;
  std::vector<std::vector<char>> solved_maze_;
  unsigned row_size_{0};
  unsigned column_size_{0};
};
#endif