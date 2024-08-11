MODULE RandomModule
  IMPLICIT NONE
CONTAINS
  INTEGER FUNCTION CSJRAND(N, IX, IY, IZ)
    INTEGER, INTENT(INOUT) :: IX, IY, IZ
    INTEGER, INTENT(IN) :: N
    REAL :: U, X

    IX = MOD(171*IX, 30269)
    IY = MOD(172*IY, 30307)
    IZ = MOD(170*IZ, 30323)
    X = (REAL(IX) / 30269.0) + (REAL(IY) / 30307.0) + (REAL(IZ) / 30323.0)
    U = X - FLOOR(X)
    CSJRAND = INT(REAL(N) * U + 1.0)
  END FUNCTION CSJRAND
END MODULE RandomModule

PROGRAM TestCSJRAND
  USE RandomModule
  IMPLICIT NONE
  INTEGER :: result
  INTEGER :: n, ix, iy, iz

  ! Initialize seed values
  n = 10
  ix = 12345
  iy = 67890
  iz = 13579

  ! Call the CSJRAND function
  result = CSJRAND(n, ix, iy, iz)

  ! Print the result
  PRINT *, "CSJRAND Result: ", result

  ! Simple check to verify the function's output
  IF (result >= 1 .AND. result <= n) THEN
    PRINT *, "Test passed."
  ELSE
    PRINT *, "Test failed."
  END IF
END PROGRAM TestCSJRAND