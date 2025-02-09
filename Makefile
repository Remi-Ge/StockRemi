# Compiler and options definitions
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Definitions of source and object files
SRC = src/main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = build

# Main rule
all: $(EXEC)

# Create the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Generic rule to compile each .cpp file into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the build
run: $(EXEC)
	./$(EXEC)

# Clean up compiled files
clean:
	rm -f $(OBJ) $(EXEC)
