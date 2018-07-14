#include "vm.hpp"

void Vm::gt() {
  int second = stackPop();
  int first = stackPop();
  stack.push_back(first > second ? 1 : 0);
  advance();
}

void Vm::lt() {
  int second = stackPop();
  int first = stackPop();
  stack.push_back(first < second ? 1 : 0);
  advance();
}

void Vm::eq() {
  int second = stackPop();
  int first = stackPop();
  stack.push_back(first == second ? 1 : 0);
  advance();
}
