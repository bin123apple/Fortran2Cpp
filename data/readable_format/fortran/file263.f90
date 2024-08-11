MODULE xmod
  INTEGER :: x = -666
CONTAINS
  INTEGER FUNCTION foo()
    foo = 42
  END FUNCTION foo

  INTEGER FUNCTION bar(a)
    INTEGER, INTENT(IN) :: a
    bar = a
  END FUNCTION bar
END MODULE xmod

MODULE ymod
  INTEGER :: y = -666
CONTAINS
  INTEGER FUNCTION foo()
    foo = 42
  END FUNCTION foo

  INTEGER FUNCTION bar(a)
    INTEGER, INTENT(IN) :: a
    bar = a
  END FUNCTION bar
END MODULE ymod

PROGRAM main
  USE xmod, ONLY: x, foo => foo, bar => bar
  USE ymod, ONLY: y
  INTEGER :: result

  x = 666
  y = 666

  IF (x /= 666) PRINT *, "X assignment test failed."
  IF (y /= 666) PRINT *, "Y assignment test failed."

  result = foo()
  IF (result /= 42) PRINT *, "X foo() test failed."

  result = bar(100)
  IF (result /= 100) PRINT *, "X bar() test failed."

  PRINT *, "All Fortran tests passed."
END PROGRAM main