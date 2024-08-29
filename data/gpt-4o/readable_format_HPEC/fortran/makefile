# Compiler and flags
FC = gfortran
FFLAGS = -c -fopenmp

# Source files
SRC = $(wildcard *.f90)

# Object files
OBJ = $(SRC:.f90=.o)

# Default target
all: $(OBJ)

# Pattern rule for compiling .f90 files into .o files
%.o: %.f90
	@$(FC) $(FFLAGS) $< -o $@ 2> $*.err
	@if [ $$? -ne 0 ]; then \
		echo "Compilation error in $<, see $*.err for details."; \
	else \
		rm -f $*.err; \
	fi

# Clean up object files, error files, and executables
clean:
	rm -f $(OBJ) *.err

