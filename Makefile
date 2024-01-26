CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -O3
SRC_DIR = src
LIB_DIR = lib
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/**/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(LIB_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/main

# Build rule
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
$(LIB_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run:
	./bin/main.exe

clean:
	del /q /s $(LIB_DIR)\*.o bin\Main.exe
