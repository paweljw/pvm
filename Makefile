CC=g++
CPPFLAGS=-std=c++17
LDFLAGS=-g

VM_SRCS := $(wildcard vm/*.cpp)
VM_OBJS := $(VM_SRCS:.cpp=.o)

all: runtime compiler

runtime: $(VM_OBJS) runtime.o
	$(CC) $(LDFLAGS) -o bin/runtime runtime.o $(VM_OBJS)

compiler: compiler.o
	$(CC) $(LDFLAGS) -o bin/compiler compiler.o

clean:
	rm -f *.o
	rm -f vm/*.o
	rm -f bin/runtime
	rm -f bin/compiler

examples: compiler
	bin/compiler examples/fizzbuzz.pvs fizzbuzz.pvm
	bin/compiler examples/hello_world.pvs hello_world.pvm
