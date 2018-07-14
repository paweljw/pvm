#include "vm.hpp"

void Vm::push() {
  advance();
  stack.push_back(program[programPointer]);
  advance();
}

void Vm::pop() {
  stack.pop_back();
  advance();
}
