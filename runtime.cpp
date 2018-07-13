#include <fstream>
#include <iostream>
#include "vm/vm.h"

int main(int argc, char * argv[]) {
  if (argc != 2) {
    std::cout << "Filename must be passed in as first argument." << std::endl;
    return 127;
  }

  std::ifstream input;
  std::vector<int> program;
  int buffer;

  input.open(argv[1], std::ios::binary | std::ios::in);

  while(input.read((char *)&buffer, sizeof(int))) {
    program.push_back(buffer);
  }

  input.close();

  Vm vm(program);
  vm.run(0);

  return 0;
}
