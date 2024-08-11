PROGRAM testDV7SCP
  IMPLICIT NONE
  INTEGER :: p
  DOUBLE PRECISION, ALLOCATABLE :: y(:)
  DOUBLE PRECISION :: s
  INTEGER :: i, testCases, j
  
  ! Test cases
  testCases = 3
  DO j = 1, testCases
     SELECT CASE(j)
     CASE(1)
        p = 5
        s = 2.0
     CASE(2)
        p = 3
        s = -1.5
     CASE(3)
        p = 4
        s = 0.0
     END SELECT

     ALLOCATE(y(p))
     CALL DV7SCP(p, y, s)
     
     PRINT*, "Test Case ", j, ": p=", p, " s=", s
     DO i = 1, p
        IF (y(i) /= s) THEN
           PRINT*, "Test Failed at index ", i
           STOP
        END IF
     END DO
     DEALLOCATE(y)
     PRINT*, "Test Passed"
  END DO
END PROGRAM testDV7SCP

SUBROUTINE DV7SCP(P, Y, S)
  INTEGER P
  DOUBLE PRECISION S, Y(P)
  INTEGER I
  DO I = 1, P
     Y(I) = S
  END DO
  RETURN
END SUBROUTINE DV7SCP