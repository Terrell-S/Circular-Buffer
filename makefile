CC := gcc
#flags used when compiling sources
CFLAGS := -Iinclude -Wall -g -Wextra -std=c11 

#wildcard = search for these files. lists out the source files
SRCS := $(wildcard src/*.c)
#patsubst = replace the src/%.c with build/%.o for these files
OBJS := $(patsubst src/%.c, build/%.o, $(SRCS))

#dont look for files of these names
.PHONY: all run clean

#could have unrelated target we also want to check
all: cbuff

cbuff: $(OBJS)
	$(CC) $(OBJS) -o $@ -pthread

build/%.o: src/%.c | build
	$(CC) $(FLAGS) -c $< -o $@

build:
	mkdir -p build

run: all
	./cbuff

clean:
	rm -rf build cbuff
