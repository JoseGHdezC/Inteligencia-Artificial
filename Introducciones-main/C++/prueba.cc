#include <iostream>

int number = 2;

class Tree {
 public:
  void PrintTree() { std::cout << root_ << std::endl;}

 private:
  int root_{0};
};

void Foo(int number_1, int number_2) {
  int number = 0; // Will be used before the global variable
  std::cout << number << std::endl;
  std::cout << number_1 << " " << number_2 << std::endl;
}

int main() {
  int a, b, c, d;
  std::cin >> a >> b;
  Foo(c = a, d = b);
  std::cout << "c: " << c << " d: " << d << std::endl;
  std::string letter = "ai";
  letter.pop_back();
  letter.npos;
  std::cout << letter << std::endl;
  return 0;
}