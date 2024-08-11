PROGRAM swap_main
  IMPLICIT NONE

  INTEGER :: i, j
  REAL    :: x, y

  i = 10
  j = 60
  x = 40.567
  y = 38.678

  PRINT *, 'Before swapping: i= ', i, ' j= ', j, ' x= ', x, ' y = ', y
  
  CALL swapint(i, j)
  CALL swapreal(x, y)

  PRINT *, 'After swapping: i= ', i, ' j= ', j, ' x= ', x, ' y = ', y

CONTAINS

  SUBROUTINE swapreal(a, b)
    REAL, INTENT(INOUT) :: a, b
    REAL :: temp
    temp = a
    a = b
    b = temp
  END SUBROUTINE swapreal

  SUBROUTINE swapint(a, b)
    INTEGER, INTENT(INOUT) :: a, b
    INTEGER :: temp
    temp = a
    a = b
    b = temp
  END SUBROUTINE swapint

END PROGRAM swap_main