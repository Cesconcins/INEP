# Compiler and flags
CC = g++
CFLAGS = -Wall -g

# Define directories for source files and object files
SRC_DIRS = src cercadors passareles sistema transaccions
OBJ_DIR = obj
DEP_DIR = dep

# Find all .cpp files in the source directories recursively
SOURCES := $(shell find $(SRC_DIRS) -name "*.cpp")

# Define object files corresponding to the source files
OBJECTS := $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)

# Define dependency files
DEPS := $(OBJECTS:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# Create the directories if they don't exist
$(shell mkdir -p $(OBJ_DIR)/src $(OBJ_DIR)/cercadors $(OBJ_DIR)/passareles $(OBJ_DIR)/sistema $(OBJ_DIR)/transaccions)

# Main target
main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) -lmysqlcppconn

# Compilation rule for object files and generating dependencies
$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -MD -MP -c $< -o $@

# Include the generated dependency files
-include $(DEPS)

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf obj main

# All target to build main and clean
.PHONY: all
all: main
	@echo "Build successful. Cleaning up..."
	$(MAKE) clean

