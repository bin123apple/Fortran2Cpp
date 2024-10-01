# Compiler and flags
CC = g++
CXXFLAGS = -c -fopenmp

# Source files
SRC = $(wildcard *.cpp)

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(OBJ)

# Pattern rule for compiling .cpp files into .o files
%.o: %.cpp
	@$(CC) $(CXXFLAGS) $< -o $@ 2> $*.err
	@if [ $$? -ne 0 ]; then \
		echo "Compilation error in $<, see $*.err for details."; \
	else \
		rm -f $*.err; \
	fi

# Clean up object files, error files, and executables
clean:
	rm -f $(OBJ) *.err *.exe*

