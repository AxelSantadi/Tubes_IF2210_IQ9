# Makefile

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -std=c++11

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIRS := $(wildcard $(SRC_DIR)/Class/*/)

# Source files
SRCS := $(wildcard $(SRC_DIR)/Class/*/*.cpp)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Create object directory if it doesn't exist
$(shell mkdir -p $(OBJ_DIR))

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(addprefix -I,$(INC_DIRS)) -c $< -o $@

# Main target
all: $(OBJS)

clean:
	rm -rf $(OBJ_DIR)

.PHONY: all clean
