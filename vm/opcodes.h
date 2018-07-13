#pragma once

enum {
  PUSH = 1,     // Push 1st argument onto stack
  POP = 2,      // Delete top of stack
  PRINT = 3,    // Print top of stack as integer
  PRINTA = 4,   // Print top of stack as ASCII char
  ADD = 5,      // Pop two elements off stack, add them together, push result onto stack
  SUB = 6,      // Pop two elements off stack, subtract top from bottom, push result onto stack
  MUL = 7,      // Pop two elements off stack, multiply them, push result onto stack
  DIV = 8,      // Pop two elements off stack, integer-divide bottom by top, push result onto stack
  RPOP = 9,     // Pop top of stack and put into register given by first argument
  RPUSH = 10,   // Put register value given by first argument onto stack,
  RCPY = 11,    // Copy top of stack to register given by first argument
  JUMP = 12,    // Jump to instruction given as 1st argument
  JUMPT = 13,   // Jump to instruction given as 1st argument if top of stack is > 0
  JUMPF = 14,   // Jump to instruction given as 1st argument if top of stack is <= 0
  HALT = 15,    // Jump beyond instruction set - finish execution
  READ = 16,    // Read a character from input, place onto stack
  GT = 17,      // Pop two top elements from stack, place 1 on stack if bottom > top, 0 otherwise
  LT = 18,      // Pop two top elements from stack, place 1 on stack if bottom < top, 0 otherwise
  EQ = 19,      // Pop two top elements from stack, place 1 on stack if bottom == top, 0 otherwise
};
