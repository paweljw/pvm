#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "vm/opcodes.h"

int resolveOption(std::string token) {
  if(token == "PUSH") return PUSH;
  if(token == "POP") return POP;
  if(token == "PRINT") return PRINT;
  if(token == "PRINTA") return PRINTA;
  if(token == "ADD") return ADD;
  if(token == "SUB") return SUB;
  if(token == "MUL") return MUL;
  if(token == "DIV") return DIV;
  if(token == "MOD") return MOD;
  if(token == "RPOP") return RPOP;
  if(token == "RPUSH") return RPUSH;
  if(token == "JUMP") return JUMP;
  if(token == "JUMPT") return JUMPT;
  if(token == "JUMPF") return JUMPF;
  if(token == "JUMPS") return JUMPS;
  if(token == "HALT") return HALT;
  if(token == "READ") return READ;
  if(token == "GT") return GT;
  if(token == "LT") return LT;
  if(token == "EQ") return EQ;
  return std::stoi(token);
}

int main(int argc, char * argv[]) {
  std::string line;
  std::string token;
  std::ifstream input;
  std::ofstream output;
  int tokenValue = 0;

  if (argc != 3) {
    std::cout << "Pass input as first argument, output as second." << std::endl;
    return 127;
  }

  if(argv[1] == argv[2]) {
    std::cout << "Don't pass in the same file twice, it's a recipe for disaster." << std::endl;
    return 127;
  }

  input.open(argv[1], std::ios::in);
  output.open(argv[2], std::ios::binary | std::ios::out);

  std::vector<std::string> tokenStream;

  while(std::getline(input, line)) {
    if(line[0] == '#') continue;
    std::istringstream tokens(line);
    while(tokens >> token) {
      tokenStream.push_back(token);
    }
  }

  bool labelMode = false;
  int instructionPointer = 0;

  std::map<std::string, int> labels;
  
  // Labels pass

  std::for_each(tokenStream.begin(), tokenStream.end(), [&](auto &token){
    if (labelMode) {
      labels[token] = instructionPointer;
      labelMode = false;
    } else {
      if(token == "LABEL") {
        labelMode = true;
      } else {
        instructionPointer++;
      }
    }
  });

  std::for_each(tokenStream.begin(), tokenStream.end(), [&](auto &token){
    if (labelMode) {
      labelMode = false;
    } else {
      if(labels[token]) {
        tokenValue = labels[token];
        output.write((char *)&tokenValue, sizeof(int));
      } else {
        if(token == "LABEL") {
          labelMode = true;
        } else {
          tokenValue = resolveOption(token);
          output.write((char *)&tokenValue, sizeof(int));
        }
      }
    }
  });
  output.close();
}
