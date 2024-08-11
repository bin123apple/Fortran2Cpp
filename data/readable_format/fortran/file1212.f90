PROGRAM TestPPP
  IMPLICIT NONE
  DOUBLE PRECISION A(3), B(3), APB(3)
  INTEGER I

  ! Test 1: Positive numbers
  A = (/1.0, 2.0, 3.0/)
  B = (/4.0, 5.0, 6.0/)
  CALL iau_PPP(A, B, APB)
  PRINT *, 'Test 1: ', APB

  ! Test 2: Negative numbers
  A = (/-1.0, -2.0, -3.0/)
  B = (/-4.0, -5.0, -6.0/)
  CALL iau_PPP(A, B, APB)
  PRINT *, 'Test 2: ', APB

  ! Test 3: Mixed numbers
  A = (/1.5, -2.5, 3.5/)
  B = (/-1.5, 2.5, -3.5/)
  CALL iau_PPP(A, B, APB)
  PRINT *, 'Test 3: ', APB

END PROGRAM TestPPP

SUBROUTINE iau_PPP ( A, B, APB )
  IMPLICIT NONE
  DOUBLE PRECISION A(3), B(3), APB(3)
  INTEGER I
  DO I=1,3
     APB(I) = A(I) + B(I)
  END DO
END SUBROUTINE iau_PPP