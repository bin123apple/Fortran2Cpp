PROGRAM TestDDANRM
  IMPLICIT NONE
  DOUBLE PRECISION, ALLOCATABLE :: V(:), WT(:), RPAR(:)
  INTEGER, ALLOCATABLE :: IPAR(:)
  DOUBLE PRECISION :: result
  INTEGER :: NEQ
  DOUBLE PRECISION :: EXPECTED_VALUE

  ! Define the expected value for the test case
  EXPECTED_VALUE = 1.0D0  ! This needs to be adjusted based on the expected output

  ! Example test case
  NEQ = 3
  ALLOCATE(V(NEQ), WT(NEQ), RPAR(1), IPAR(1))  ! Adjust the size of RPAR and IPAR as needed
  V = (/1.0D0, 2.0D0, 3.0D0/)
  WT = (/1.0D0, 2.0D0, 3.0D0/)
  
  result = DDANRM(NEQ, V, WT, RPAR, IPAR)
  PRINT *, "Test 1 Result: ", result
  IF (ABS(result - EXPECTED_VALUE) < 1.0D-6) THEN
     PRINT *, "Test 1 Passed."
  ELSE
     PRINT *, "Test 1 Failed."
  END IF

  ! Deallocate arrays
  DEALLOCATE(V, WT, RPAR, IPAR)

  CONTAINS

    DOUBLE PRECISION FUNCTION DDANRM (NEQ, V, WT, RPAR, IPAR)
      INTEGER  NEQ, IPAR(*)
      DOUBLE PRECISION  V(NEQ), WT(NEQ), RPAR(*)
      INTEGER  I
      DOUBLE PRECISION  SUM, VMAX
      DDANRM = 0.0D0
      VMAX = 0.0D0
      DO 10 I = 1,NEQ
        IF(ABS(V(I)/WT(I)) .GT. VMAX) VMAX = ABS(V(I)/WT(I))
    10  CONTINUE
      IF(VMAX .LE. 0.0D0) GO TO 30
      SUM = 0.0D0
      DO 20 I = 1,NEQ
    20  SUM = SUM + ((V(I)/WT(I))/VMAX)**2
      DDANRM = VMAX*SQRT(SUM/NEQ)
    30  CONTINUE
      RETURN
    END FUNCTION DDANRM

END PROGRAM TestDDANRM