! Define the loop3_F90 subroutine
SUBROUTINE loop3_F90(N, x, y, a)
  INTEGER, INTENT(IN) :: N
  REAL*8, INTENT(IN) :: x(N), a
  REAL*8, INTENT(INOUT) :: y(N)
  INTEGER :: i

  ! Perform the operation y = y + a*x
  DO i = 1, N
    y(i) = y(i) + a*x(i)
  END DO
END SUBROUTINE loop3_F90

! Define the loop3_F90Overhead subroutine (intentionally left empty)
SUBROUTINE loop3_F90Overhead(N, x, y, a)
  INTEGER, INTENT(IN) :: N
  REAL*8, INTENT(IN) :: x(N), y(N), a
  ! This subroutine intentionally does nothing
END SUBROUTINE loop3_F90Overhead

! Main program to test the subroutines
PROGRAM testLoop3
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 5
  REAL*8 :: x(N) = [1.0, 2.0, 3.0, 4.0, 5.0]
  REAL*8 :: y(N) = [1.0, 1.0, 1.0, 1.0, 1.0]
  REAL*8 :: a = 2.5
  INTEGER :: i

  ! Test loop3_F90
  CALL loop3_F90(N, x, y, a)
  PRINT *, 'Resulting y array after loop3_F90:'
  DO i = 1, N
    PRINT *, y(i)
  END DO

  ! Reset y array
  y = [1.0, 1.0, 1.0, 1.0, 1.0]

  ! Test loop3_F90Overhead (should leave y array unchanged)
  CALL loop3_F90Overhead(N, x, y, a)
  PRINT *, 'Resulting y array after loop3_F90Overhead (should be unchanged):'
  DO i = 1, N
    PRINT *, y(i)
  END DO
END PROGRAM testLoop3