CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))

TARGET = bin/my_shell

all: $(TARGET)

$(TARGET): $(OBJ) | bin
	$(CC) $(OBJ) -o $(TARGET)

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p obj

bin:
	mkdir -p bin

run: all
	./$(TARGET)

clean:
	rm -f obj/*.o $(TARGET)

.PHONY: all run clean

