PROGRAM testDDWNRM
  IMPLICIT NONE
  DOUBLE PRECISION, ALLOCATABLE :: V(:), RWT(:)
  DOUBLE PRECISION :: result
  INTEGER :: NEQ

  ! Function prototype (interface) to ensure the main program knows how to call DDWNRM
  INTERFACE
    DOUBLE PRECISION FUNCTION DDWNRM(NEQ, V, RWT)
      INTEGER, INTENT(IN) :: NEQ
      DOUBLE PRECISION, DIMENSION(*), INTENT(IN) :: V, RWT
    END FUNCTION DDWNRM
  END INTERFACE

  ! Test case 1
  NEQ = 3
  ALLOCATE(V(NEQ), RWT(NEQ))
  V = (/1.0D0, 2.0D0, 3.0D0/)
  RWT = (/0.5D0, 1.0D0, 1.5D0/)
  PRINT *, 'Test Case 1: Expected result is close to 2.85774'
  result = DDWNRM(NEQ, V, RWT)
  PRINT *, 'Result: ', result

  ! Test case 2
  NEQ = 2
  V = (/4.0D0, -3.0D0/)
  RWT = (/1.0D0, 1.0D0/)
  PRINT *, 'Test Case 2: Expected result is close to 3.53553'
  result = DDWNRM(NEQ, V, RWT)
  PRINT *, 'Result: ', result

  DEALLOCATE(V, RWT)
END PROGRAM testDDWNRM

! The DDWNRM function is defined outside and after the main program block.
DOUBLE PRECISION FUNCTION DDWNRM(NEQ, V, RWT)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: NEQ
  DOUBLE PRECISION, DIMENSION(*), INTENT(IN) :: V, RWT
  DOUBLE PRECISION :: VMAX, SUM
  INTEGER :: I

  DDWNRM = 0.0D0
  VMAX = 0.0D0
  DO I = 1, NEQ
    IF(ABS(V(I)*RWT(I)) .GT. VMAX) VMAX = ABS(V(I)*RWT(I))
  END DO
  IF(VMAX .LE. 0.0D0) RETURN
  SUM = 0.0D0
  DO I = 1, NEQ
    SUM = SUM + ((V(I)*RWT(I))/VMAX)**2
  END DO
  DDWNRM = VMAX*SQRT(SUM/DBLE(NEQ))

  RETURN
END FUNCTION DDWNRM