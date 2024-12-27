CC = g++
CFLAGS = -Wall -g

# Automatically find all source files
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)
DEPS := $(OBJECTS:.o=.d)

# Targets
main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS) -lmysqlcppconn

# Compilation rules with dependency generation
%.o: %.cpp
	$(CC) $(CFLAGS) -MD -MP -c $< -o $@

# Include the generated dependency files
-include $(DEPS)

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf *.o *.d main
