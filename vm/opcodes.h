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
  MOD = 9,      // Pushes bottom modulo top onto stack
  RPOP = 10,     // Pop top of stack and put into register given by first argument
  RPUSH = 11,   // Put register value given by first argument onto stack,
  RCPY = 12,    // Copy top of stack to register given by first argument
  JUMP = 13,    // Jump to instruction given as 1st argument
  JUMPT = 14,   // Jump to instruction given as 1st argument if top of stack is > 0
  JUMPF = 15,   // Jump to instruction given as 1st argument if top of stack is <= 0
  JUMPS = 16,   // Jump to instruction at address that is on top of the stack (popping)
  HALT = 17,    // Jump beyond instruction set - finish execution
  READ = 18,    // Read a character from input, place onto stack
  GT = 19,      // Pop two top elements from stack, place 1 on stack if bottom > top, 0 otherwise
  LT = 20,      // Pop two top elements from stack, place 1 on stack if bottom < top, 0 otherwise
  EQ = 21,      // Pop two top elements from stack, place 1 on stack if bottom == top, 0 otherwise
};
