#include <iostream>

#include "vm.h"

void Vm::print() {
  std::cout << stack.back();
  advance();
}

void Vm::printa() {
  std::cout << static_cast<char>(stack.back());
  advance();
}

void Vm::read() {
  char input;
  std::cin.get(input);
  std::cout << "Read " << input << std::endl;
  stack.push_back(input);
  advance();
  std::cout << "Done" << std::endl;
}

