PROGRAM testMOVINT
  IMPLICIT NONE
  INTEGER, PARAMETER :: NMOV = 5
  INTEGER :: IFROM(NMOV), ITO(NMOV)
  INTEGER :: I

  ! Initialize the source array
  DO I = 1, NMOV
     IFROM(I) = I
  END DO
  
  ! Call the subroutine
  CALL MOVINT(NMOV, IFROM, ITO)
  
  ! Check the results
  DO I = 1, NMOV
     IF (ITO(I) /= IFROM(I)) THEN
        PRINT *, 'Test failed!'
        STOP
     END IF
  END DO
  
  PRINT *, 'Test passed!'
END PROGRAM testMOVINT

SUBROUTINE MOVINT(NMOV, IFROM, ITO)
  INTEGER, INTENT(IN) :: NMOV
  INTEGER, INTENT(IN) :: IFROM(*)
  INTEGER, INTENT(OUT) :: ITO(*)
  INTEGER :: I

  DO I = 1, NMOV
     ITO(I) = IFROM(I)
  END DO
END SUBROUTINE MOVINT