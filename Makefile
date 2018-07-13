CC=g++
CPPFLAGS=-std=c++17
LDFLAGS=-g

VM_SRCS := $(wildcard vm/*.cpp)
VM_OBJS := $(VM_SRCS:.cpp=.o)

all: clean hello_world

hello_world: $(VM_OBJS) hello_world.o
	$(CC) $(LDFLAGS) -o hello_world hello_world.o $(VM_OBJS)

clean:
	rm -f *.o
	rm -f vm/*.o
	rm -f hello_world

run: clean hello_world
	./hello_world
