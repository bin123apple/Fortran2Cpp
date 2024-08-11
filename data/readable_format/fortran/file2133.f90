PROGRAM test_zlacgv
  IMPLICIT NONE
  INTEGER :: i
  INTEGER :: n, incx
  COMPLEX*16 :: x(5)
  COMPLEX*16 :: expected(5)

  ! Initialize test data
  n = 5
  incx = 1
  x = [(1.0D0, 2.0D0), (3.0D0, 4.0D0), (5.0D0, 6.0D0), (7.0D0, 8.0D0), (9.0D0, 10.0D0)]
  expected = [(1.0D0, -2.0D0), (3.0D0, -4.0D0), (5.0D0, -6.0D0), (7.0D0, -8.0D0), (9.0D0, -10.0D0)]

  ! Call the subroutine
  CALL ZLACGV(n, x, incx)

  ! Check the results
  DO i = 1, n
    IF (x(i) /= expected(i)) THEN
      PRINT *, 'Test failed at index', i
      STOP
    END IF
  END DO

  PRINT *, 'All tests passed!'
END PROGRAM test_zlacgv

! Subroutine definition
SUBROUTINE ZLACGV(N, X, INCX)
  INTEGER            INCX, N
  COMPLEX*16         X(*)
  INTEGER            I, IOFF
  INTRINSIC          DCONJG

  IF (INCX.EQ.1) THEN
    DO I = 1, N
      X(I) = DCONJG(X(I))
    END DO
  ELSE
    IOFF = 1
    IF (INCX.LT.0) THEN
      IOFF = 1 - (N - 1) * INCX
    END IF
    DO I = 1, N
      X(IOFF) = DCONJG(X(IOFF))
      IOFF = IOFF + INCX
    END DO
  END IF
  RETURN
END SUBROUTINE ZLACGV