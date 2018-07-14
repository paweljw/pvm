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
	rm -f *.pvm

hello_world: examples/hello_world.pvs
	bin/compiler examples/hello_world.pvs hello_world.pvm

fizzbuzz: examples/fizzbuzz.pvs
	bin/compiler examples/fizzbuzz.pvs fizzbuzz.pvm

fibonacci: examples/fibonacci.pvs
	bin/compiler examples/fibonacci.pvs fibonacci.pvm

examples: runtime compiler hello_world fizzbuzz fibonacci
