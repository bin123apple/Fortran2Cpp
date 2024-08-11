PROGRAM TestIauCP
  IMPLICIT NONE
  DOUBLE PRECISION P(3), C(3)
  INTEGER I

  ! Initialize P with some values
  P(1) = 1.0
  P(2) = 2.0
  P(3) = 3.0

  ! Call the subroutine
  CALL iau_CP(P, C)

  ! Print the results
  DO I = 1, 3
     WRITE(*,*) 'C(', I, ') = ', C(I)
  END DO

END PROGRAM TestIauCP

SUBROUTINE iau_CP(P, C)
  IMPLICIT NONE
  DOUBLE PRECISION P(3), C(3)
  INTEGER I
  DO I = 1, 3
     C(I) = P(I)
  END DO
END SUBROUTINE iau_CP