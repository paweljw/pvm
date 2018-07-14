#include <iostream>

#include "vm.hpp"

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
  stack.push_back(input);
  advance();
}

