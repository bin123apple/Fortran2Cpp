! Modified Fortran code to write to a file
PROGRAM EXAMPLE
    OPEN(UNIT=10, FILE="output.txt", STATUS="replace", ACTION="write")
    WRITE(10, *) 'Hello, World!'
    CLOSE(UNIT=10)
END PROGRAM EXAMPLE