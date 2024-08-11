! loop_fusion.f90
PROGRAM LOOP_FUSION
  CALL clawloop
END PROGRAM LOOP_FUSION

SUBROUTINE clawloop
  IMPLICIT NONE
  INTEGER :: i
  INTEGER :: j
  INTEGER :: k
  INTEGER :: iend = 2
  INTEGER :: jend = 4
  INTEGER :: kend = 2

  DO i=0,iend
    IF (i == 0) THEN
      PRINT*, 'First iteration of i',i
    END IF
    DO j=0,jend
      DO k=0,kend
        PRINT *, 'First loop body:',i,'/',j,'/',k
      END DO
    END DO

    DO j=2,jend
      DO k=0,kend
        PRINT *, 'Second loop body:',i,'/',j,'/',k
      END DO
    END DO
  END DO
END SUBROUTINE clawloop