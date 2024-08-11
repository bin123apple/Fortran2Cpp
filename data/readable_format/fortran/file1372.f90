PROGRAM test_dlamch
  IMPLICIT NONE

  CHARACTER :: test_chars(11)
  CHARACTER :: ch
  INTEGER :: i
  DOUBLE PRECISION :: result

  test_chars = (/ 'E', 'S', 'B', 'P', 'N', 'R', 'M', 'U', 'L', 'O', 'X' /)

  WRITE(*,*) 'Testing DLAMC3...'
  WRITE(*,*) 'DLAMC3(1.0D0, 2.0D0) = ', DLAMC3(1.0D0, 2.0D0)

  WRITE(*,*) 'Testing DLAMCH...'
  DO i = 1, 11
    ch = test_chars(i)
    result = DLAMCH(ch)
    WRITE(*,*) 'DLAMCH(', ch, ') = ', result
  END DO

CONTAINS

  DOUBLE PRECISION FUNCTION DLAMC3(A, B)
    DOUBLE PRECISION, INTENT(IN) :: A, B
    DLAMC3 = A + B
  END FUNCTION DLAMC3

  DOUBLE PRECISION FUNCTION DLAMCH(CMACH)
    CHARACTER, INTENT(IN) :: CMACH
    DOUBLE PRECISION :: ONE, ZERO, EPS, SFMIN, SMALL, RMACH
    DOUBLE PRECISION :: RND  ! Placeholder for rounding behavior
    ONE = 1.0D0
    ZERO = 0.0D0
    RND = 1.0D0  ! Assuming RND is meant to represent rounding to nearest, set to 1.0 as default
    EPS = EPSILON(ONE)
    SFMIN = TINY(ONE)
    SMALL = ONE / HUGE(ONE)

    SELECT CASE (CMACH)
    CASE ('E')
      RMACH = EPS
    CASE ('S')
      RMACH = SFMIN
    CASE ('B')
      RMACH = RADIX(ONE)
    CASE ('P')
      RMACH = EPS * RADIX(ONE)
    CASE ('N')
      RMACH = DIGITS(ONE)
    CASE ('R')
      RMACH = RND
    CASE ('M')
      RMACH = MINEXPONENT(ONE)
    CASE ('U')
      RMACH = TINY(ONE)
    CASE ('L')
      RMACH = MAXEXPONENT(ONE)
    CASE ('O')
      RMACH = HUGE(ONE)
    CASE DEFAULT
      RMACH = ZERO
    END SELECT

    DLAMCH = RMACH
  END FUNCTION DLAMCH

END PROGRAM test_dlamch