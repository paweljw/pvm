#include <iostream>
#include <vector>
#include <algorithm>

#ifdef DEBUG
#include <stdio.h>
#endif

#include "opcodes.h"
#include "vm.h"


Vm::Vm(std::vector<int> _program) {
  program = _program;
}

void Vm::run(int entrypoint) {
  programPointer = entrypoint;
  while(programPointer < static_cast<int>(program.size()))
    step();
}

void Vm::step() {
  #ifdef DEBUG
  printStack();
  printRegisters();
  std::cout << "Next instruction: " << program[programPointer] << " (at " << programPointer << ")" << std::endl;
  getchar();
  #endif

  switch (program[programPointer]) {
    case PUSH:
      push();
      break;
    case POP:
      pop();
      break;
    case PRINT:
      print();
      break;
    case PRINTA:
      printa();
      break;
    case ADD:
      add();
      break;
    case SUB:
      sub();
      break;
    case MUL:
      mul();
      break;
    case DIV:
      div();
      break;
    case RPOP:
      rpop();
      break;
    case RPUSH:
      rpush();
      break;
    case RCPY:
      rcpy();
      break;
    case JUMP:
      jump();
      break;
    case JUMPT:
      jumpt();
      break;
    case JUMPF:
      jumpf();
      break;
    case HALT:
      halt();
      break;
    case READ:
      read();
      break;
    case GT:
      gt();
      break;
    case LT:
      lt();
      break;
    case EQ:
      eq();
      break;
  }
}

void Vm::advance() {
  programPointer++;
}

int Vm::stackPop() {
  int ret = stack.back();
  stack.pop_back();
  return ret;
}

#ifdef DEBUG
void Vm::printStack() {
  std::cout << "Stack: ";
  std::for_each(stack.begin(), stack.end(), [](auto &item) {
    std::cout << item << " ";
  });
  std::cout << std::endl;
}

void Vm::printRegisters() {
  for(int i = 0; i < 4; i++) {
    std::cout << "Register " << i << " = " << registers[i] << std::endl;
  }
}
#endif
