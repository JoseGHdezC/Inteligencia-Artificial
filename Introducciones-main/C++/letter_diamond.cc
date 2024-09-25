#include <iostream>
#include <vector>
#include <string>

int main() {
  std::cout << "Introduce letter: ";
  char letter{'\0'};
  std::cin >> letter;

  const unsigned kDisplacement{65};
  std::vector<std::string> diamond;
  std::string line{""};
  char current_letter{'A'};
  unsigned space_number = static_cast<unsigned>(letter) - kDisplacement;
  unsigned middle_space{0};
  int k = 0;
  //std::cout << static_cast<unsigned>(letter) << std::endl;
  //std::cout << "Spaces: " << space_number << std::endl;
  for (; current_letter <= letter; current_letter = current_letter + 1) {
    line = "";
    //std::cout << "Current letter: " << current_letter << std::endl;
    for (int i = 0; i < space_number; ++i) {
      line += " ";
    }
    line += current_letter;
    if (current_letter != 'A') {
      middle_space = static_cast<unsigned>(current_letter) - kDisplacement + k++;
      for (int j = 0; j < middle_space; ++j) {
        line += " ";
      }
      line += current_letter;
    }
    for (int i = 0; i < space_number; ++i) {
      line += " ";
    }
    --space_number;
    diamond.emplace_back(line);
  }
  current_letter = current_letter - 2;
  space_number = space_number + 2;
  k = k - 2;
  for (; current_letter >= 'A'; current_letter = current_letter - 1) {
    line = "";
    //std::cout << "Current letter: " << current_letter << std::endl;
    for (int i = 0; i < space_number; ++i) {
      line += " ";
    }
    line += current_letter;
    if (current_letter != 'A') {
      middle_space = static_cast<unsigned>(current_letter) - kDisplacement + k--;
      for (int j = 0; j < middle_space; ++j) {
        line += " ";
      }
      line += current_letter;
    }
    for (int i = 0; i < space_number; ++i) {
      line += " ";
    }
    ++space_number;
    diamond.emplace_back(line);
  }
  for (int i = 0; i < diamond.size(); ++i) {
    std::cout << diamond[i] << std::endl;
  }
  return 0;
}