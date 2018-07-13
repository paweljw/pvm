#include "vm.h"

void Vm::add() {
  int second = stackPop();
  int first = stackPop();
  stack.push_back(first + second);
  advance();
}

void Vm::sub() {
  int second = stackPop();
  int first = stackPop();
  stack.push_back(first - second);
  advance();
}

void Vm::mul() {
  int second = stackPop();
  int first = stackPop();
  stack.push_back(first * second);
  advance();
}

void Vm::div() {
  int second = stackPop();
  int first = stackPop();
  stack.push_back(first / second);
  advance();
}
