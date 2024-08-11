PROGRAM TESTADDV
      IMPLICIT NONE
      EXTERNAL ADDV
      INTEGER, PARAMETER :: N=5
      DOUBLE PRECISION A(N), B(N), C(N)
      INTEGER I

!     Test case 1: Small array
      A(1) = 1.0
      B(1) = -1.0
      CALL ADDV(1, A, B, C)
      PRINT *, 'Test 1 (Single element): ', C(1)

!     Test case 2: Larger array with positive, negative, and zero values
      DATA A /1.0, -2.0, 3.0, 0.0, -5.0/
      DATA B /5.0, 4.0, -3.0, 0.0, 2.0/
      CALL ADDV(N, A, B, C)
      PRINT *, 'Test 2 (Mixed values): '
      DO I = 1, N
        PRINT *, 'C(', I, ') = ', C(I)
      END DO

END PROGRAM TESTADDV

SUBROUTINE ADDV(N, A, B, C)
      INTEGER N
      DOUBLE PRECISION A(N),B(N),C(N)
      INTEGER I
      DO I = 1, N
        C(I) = A(I) + B(I)
      END DO
END SUBROUTINE ADDV