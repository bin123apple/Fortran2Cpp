PROGRAM test_dnrm2
  IMPLICIT NONE
  DOUBLE PRECISION, ALLOCATABLE :: testVec(:)
  INTEGER :: i
  DOUBLE PRECISION :: norm

  ! Test case 1: N = 5, INCX = 1
  ALLOCATE(testVec(5))
  DO i = 1, 5
     testVec(i) = i * 1.0D0  ! Initialize vector with values 1.0, 2.0, ..., 5.0
  END DO
  norm = DNRM2(5, testVec, 1)
  PRINT *, 'Test 1: Norm = ', norm  ! Expected: sqrt(55)

  ! Test case 2: N = 3, INCX = 2 (test skipping elements)
  norm = DNRM2(3, testVec, 2)
  PRINT *, 'Test 2: Norm = ', norm  ! Expected: sqrt(1^2 + 3^2 + 5^2)

  ! Test case 3: Zero vector
  testVec = 0.0D0
  norm = DNRM2(5, testVec, 1)
  PRINT *, 'Test 3: Norm = ', norm  ! Expected: 0.0

  DEALLOCATE(testVec)

CONTAINS

  DOUBLE PRECISION FUNCTION DNRM2(N,X,INCX)
        INTEGER INCX,N
        DOUBLE PRECISION X(*)
        DOUBLE PRECISION ONE,ZERO
        PARAMETER (ONE=1.0D+0,ZERO=0.0D+0)
        DOUBLE PRECISION ABSXI,NORM,SCALE,SSQ
        INTEGER IX
        INTRINSIC ABS,SQRT
        IF (N.LT.1 .OR. INCX.LT.1) THEN
            NORM = ZERO
        ELSE IF (N.EQ.1) THEN
            NORM = ABS(X(1))
        ELSE
            SCALE = ZERO
            SSQ = ONE
            DO 10 IX = 1,1 + (N-1)*INCX,INCX
                IF (X(IX).NE.ZERO) THEN
                    ABSXI = ABS(X(IX))
                    IF (SCALE.LT.ABSXI) THEN
                        SSQ = ONE + SSQ* (SCALE/ABSXI)**2
                        SCALE = ABSXI
                    ELSE
                        SSQ = SSQ + (ABSXI/SCALE)**2
                    END IF
                END IF
     10     CONTINUE
            NORM = SCALE*SQRT(SSQ)
        END IF
        DNRM2 = NORM
        RETURN
  END FUNCTION DNRM2

END PROGRAM test_dnrm2