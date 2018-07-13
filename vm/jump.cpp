#include "vm.h"
#include <iostream>

void Vm::jump() {
  advance(); // Move to next instruction (argument)
  programPointer = program[programPointer]; // Unconditionally move to argument
}

void Vm::jumpt() {
  advance(); // Move to argument
  if (stack.back() > 0) {
    programPointer = program[programPointer]; // If top of stack is true, jump
  } else {
    advance(); // Move to next instruction
  }
  stack.pop_back(); // Destroy the comparison source either way
}

void Vm::jumpf() {
  advance(); // Move to argument
  if (stack.back() <= 0) {
    programPointer = program[programPointer]; // If top of stack is false, jump
  } else {
    advance(); // Move to next instruction
  }
  stack.pop_back(); // Destroy source of comparison either way
}

void Vm::halt() {
  programPointer = program.size();
}
