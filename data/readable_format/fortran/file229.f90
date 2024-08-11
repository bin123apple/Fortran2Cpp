PROGRAM testSortProgram
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 5
  INTEGER :: IX(N) = [5, 2, 4, 1, 3]
  INTEGER :: IY(N) = [50, 20, 40, 10, 30]
  INTEGER :: i

  CALL SORT(N, IX, IY)

  PRINT *, 'Sorted IX:'
  DO i = 1, N
    PRINT *, IX(i)
  END DO

  PRINT *, 'Sorted IY:'
  DO i = 1, N
    PRINT *, IY(i)
  END DO
END PROGRAM testSortProgram

SUBROUTINE SORT(N, IX, IY)
  INTEGER, INTENT(INOUT) :: IX(*), IY(*)
  INTEGER, INTENT(IN) :: N
  INTEGER :: NN, M, M1, J, L, I, KEEPX, KEEPY

  NN = N
  M = NN
  
  DO WHILE (M > 0)
    M = (9*M) / 16
    IF (M <= 0) EXIT
    M1 = M + 1
    
    DO J = M1, NN
      L = J
      I = J - M
      
      DO WHILE (I >= 1)
        IF (IX(L) < IX(I)) THEN
          KEEPX = IX(I)
          KEEPY = IY(I)
          IX(I) = IX(L)
          IY(I) = IY(L)
          IX(L) = KEEPX
          IY(L) = KEEPY
          L = I
          I = I - M
        ELSE
          EXIT
        END IF
      END DO
    END DO
  END DO
END SUBROUTINE SORT