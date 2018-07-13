#pragma once

#include <vector>

class Vm {
  std::vector<int> program;
  std::vector<int> stack;
  int registers[4];
  int programPointer = 0;

  public:

  Vm(std::vector<int>);
  void run(int = 0);
  void step();

  private:

  // Opcodes implementations

  // math.cpp
  void add();
  void sub();
  void mul();
  void div();

  // registers.cpp
  void rpush();
  void rpop();
  void rcpy();

  // stack.cpp
  void push();
  void pop();

  // io.cpp
  void print();
  void printa();
  void read();

  // jump.cpp
  void jump();
  void jumpt();
  void jumpf();
  void halt();

  // comparison.cpp
  void gt();
  void lt();
  void eq();

  // Helpers
  void advance();
  int stackPop();

  #ifdef DEBUG
  void printStack();
  void printRegisters();
  #endif
};

