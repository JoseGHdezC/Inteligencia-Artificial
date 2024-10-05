#include "../include/maze.hpp"

Maze::Maze(const std::string& file) {
  std::ifstream input_file{file};
  std::string line{""};
  if (input_file.is_open()) {
    input_file >> line;
    row_size_ = std::stoi(line);
    input_file >> line;
    column_size_ = std::stoi(line);
    getline(input_file, line);
    for (unsigned i = 0; i < row_size_; ++i) {
      getline(input_file, line);
      std::cout << "Line " << i << ": " << line << std::endl;
      for (unsigned j = 0; j < column_size_(); ++j) {
        
      }
      std::vector<char> row;
      for (unsigned j = 0; j < line.length(); ++j) {
        if (line[j] != ' ') {
          row.emplace_back(line[j]);
        }
      }
      maze_.emplace_back(row);
    }
  } else {
    std::cerr << "File could not be opened. Please check file name." << std::endl;
  }
  std::cout << "Maze created." << std::endl;
}

std::ostream& operator<<(std::ostream& os, Maze& maze) {
  std::cout << "Maze size: " << maze.get_row() << " x " << maze.get_column() << std::endl;
  for (unsigned i = 0; i < maze.get_row(); ++i) {
    for (unsigned j = 0; j < maze.get_column(); ++j) {
      //std::cout << maze.get_maze()[i][j] << " ";
      switch (maze.get_maze()[i][j]) {
        case '0':
          os << PASS_CHR;
          break;
        case '1':
          os << WALL_CHR;
          break;
        case '2':
          os << PATH_CHR;
          break;
        case '3':
          os << START_CHR;
          break;
        case '4':
          os << END_CHR;
          break;
        default:
          std::cerr << "NOT EXIST" << std::endl;
      }
    }
    std::cout << std::endl;
  }
  return os;
}