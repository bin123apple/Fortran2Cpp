PROGRAM test_inbody
  IMPLICIT NONE
  INTEGER :: mr, n9, ifound, i
  LOGICAL :: addold, noroom
  INTEGER, ALLOCATABLE :: iin(:), irpb(:)

  ! Initialize test parameters
  mr = 10
  n9 = 0
  ifound = 5
  addold = .FALSE.
  ALLOCATE(iin(ifound), irpb(mr))
  iin = (/1, 2, 3, 4, 0/)
  irpb = 0

  CALL INBODY(mr, n9, iin, ifound, irpb, addold, noroom)

  ! Print results
  PRINT *, "n9:", n9
  PRINT *, "irpb:", (irpb(i), i=1, n9)
  PRINT *, "noroom:", .NOT. noroom

  DEALLOCATE(iin, irpb)

CONTAINS

  SUBROUTINE INBODY (MR, N9, IIN, IFOUND, IRPB, ADDOLD, NOROOM)
    INTEGER, INTENT(IN) :: MR, IFOUND
    INTEGER, INTENT(INOUT) :: N9
    INTEGER, INTENT(IN) :: IIN(IFOUND)
    INTEGER, INTENT(INOUT) :: IRPB(MR)
    LOGICAL, INTENT(IN) :: ADDOLD
    LOGICAL, INTENT(OUT) :: NOROOM

    INTEGER :: I, J, JJ

    NOROOM = .TRUE.
    IF (.NOT.ADDOLD) N9 = 0
    DO I = 1, IFOUND
       JJ = IIN(I)
       IF (JJ .EQ. 0) EXIT
       IF (N9 + 1 .GT. MR) RETURN
       DO J = 1, N9
          IF (IRPB(J) .EQ. JJ) EXIT
       END DO
       IF (J > N9) THEN
          N9 = N9 + 1
          IRPB(N9) = JJ
       END IF
    END DO
    NOROOM = .FALSE.
  END SUBROUTINE INBODY

END PROGRAM test_inbody