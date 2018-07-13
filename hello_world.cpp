#include <vector>

#include "vm/opcodes.h"
#include "vm/vm.h"

std::vector<int> program = {
  // Push hello world data
  PUSH, 10, // 0
  PUSH, 33, // 2
  PUSH, 100, // 4
  PUSH, 108, // 6
  PUSH, 114, // 8
  PUSH, 111, // 10
  PUSH, 87, // 12
  PUSH, 32, // 14
  PUSH, 111, // 16
  PUSH, 108, // 18
  PUSH, 108, // 20
  PUSH, 101, // 22
  PUSH, 72, // 24
  // Push length onto stack
  PUSH, 13, // 26
  RPOP, 0, // 28, Pop the length and push onto register 0
  PRINTA, // 30
  POP, // 31
  RPUSH, 0, // 32, Pop length off of register 0
  PUSH, 1, // Push second operand of subtraction
  SUB, // Pop two, push result onto stack
  RCPY, 0, // Copy counter back onto stack
  PUSH, 0,
  EQ,
  JUMPF, 30, // Jump to print if top of stack >0
};

int main () {
  Vm vm(program);
  vm.run(0);
  return 0;
}
