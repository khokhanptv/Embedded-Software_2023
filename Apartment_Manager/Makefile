CC := gcc
CXX := g++
CFLAGS := -Wall -Wextra -std=c11 -IHeader
CXXFLAGS := -Wall -Wextra -std=c++11 -IHeader
TARGET := main

SRC_C := $(wildcard Sourcee/*.c)
SRC_CPP := $(wildcard Sourcee/*.cpp)

OBJ_C := $(SRC_C:.c=.o)
OBJ_CPP := $(SRC_CPP:.cpp=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ_C) $(OBJ_CPP)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(TARGET) $(OBJ_C) $(OBJ_CPP)
