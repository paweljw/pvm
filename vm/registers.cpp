#include "vm.hpp"

void Vm::rpush() {
  advance(); // Move to argument
  stack.push_back(registers[program[programPointer]]); // use register described by argument at pointer
  advance(); // Move to next instruction
}

void Vm::rpop() {
  advance(); // Move to register number
  registers[program[programPointer]] = stack.back();
  stack.pop_back();
  advance();
}

void Vm::rcpy() {
  advance();
  registers[program[programPointer]] = stack.back();
  advance();
}

