! file: my_program.f90
PROGRAM MainProgram
  IMPLICIT NONE
  INTEGER :: a, b, result

  ! Initialize values
  a = 3
  b = 5

  ! Call the subroutine to add the numbers
  CALL add_numbers(a, b, result)

  ! Print the result
  PRINT *, "The result of adding ", a, " and ", b, " is ", result

END PROGRAM MainProgram

! Subroutine to add two numbers
SUBROUTINE add_numbers(a, b, result)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: a, b
  INTEGER, INTENT(OUT) :: result

  ! Perform the addition
  result = a + b
END SUBROUTINE add_numbers