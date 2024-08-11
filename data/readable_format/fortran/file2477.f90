MODULE HEX_NODES__genmod
  IMPLICIT NONE
  CONTAINS
  SUBROUTINE HEX_NODES(IADDX,IADDY,IADDZ)
    INTEGER(KIND=4) :: IADDX(27)
    INTEGER(KIND=4) :: IADDY(27)
    INTEGER(KIND=4) :: IADDZ(27)
    ! Your subroutine implementation here
    ! For demonstration, we'll just increment each element by 1
    INTEGER :: i
    DO i = 1, 27
      IADDX(i) = IADDX(i) + 1
      IADDY(i) = IADDY(i) + 1
      IADDZ(i) = IADDZ(i) + 1
    END DO
  END SUBROUTINE HEX_NODES
END MODULE HEX_NODES__genmod

PROGRAM test_hex_nodes
  USE HEX_NODES__genmod
  IMPLICIT NONE

  INTEGER(KIND=4) :: IADDX(27)
  INTEGER(KIND=4) :: IADDY(27)
  INTEGER(KIND=4) :: IADDZ(27)
  INTEGER :: i

  ! Initialize the arrays with some test values
  DO i = 1, 27
    IADDX(i) = i
    IADDY(i) = i * 2
    IADDZ(i) = i * 3
  END DO

  ! Call the subroutine
  CALL HEX_NODES(IADDX, IADDY, IADDZ)

  ! For testing purposes, print the result to verify correctness
  PRINT *, "IADDX: ", IADDX
  PRINT *, "IADDY: ", IADDY
  PRINT *, "IADDZ: ", IADDZ

END PROGRAM test_hex_nodes