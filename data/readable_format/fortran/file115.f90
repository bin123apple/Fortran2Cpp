PROGRAM TestIBlock
  IMPLICIT NONE
  DOUBLE PRECISION DTK(40), TPREV, TBLOCK
  INTEGER I

  CALL IBLOCK

  WRITE(*,*) 'Testing DTK...'
  DO I = 1, 40
     IF (DTK(I) .NE. 0.5D0**(I-1)) THEN
        WRITE(*,*) 'Test failed at index:', I, 'with value', DTK(I)
        STOP
     END IF
  END DO
  WRITE(*,*) 'All tests passed!'

CONTAINS

  SUBROUTINE IBLOCK
    IMPLICIT NONE
    INTEGER K

    DTK(1) = 1.0D0
    DO K = 2,40
       DTK(K) = 0.5D0*DTK(K-1)
    END DO

    TPREV = 0.0D0
    TBLOCK = 0.0D0
  END SUBROUTINE IBLOCK

END PROGRAM TestIBlock