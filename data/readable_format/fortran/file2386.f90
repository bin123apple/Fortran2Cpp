PROGRAM test_iau_PVUP
    IMPLICIT NONE

    DOUBLE PRECISION DT, PV(3,2), P(3)
    INTEGER I

    ! Initialize test values
    DT = 1.5
    PV(1,1) = 1.0
    PV(1,2) = 0.1
    PV(2,1) = 2.0
    PV(2,2) = 0.2
    PV(3,1) = 3.0
    PV(3,2) = 0.3

    ! Call the subroutine
    CALL iau_PVUP(DT, PV, P)

    ! Print the results
    PRINT *, 'P = ', P

END PROGRAM test_iau_PVUP

SUBROUTINE iau_PVUP ( DT, PV, P )
    IMPLICIT NONE
    DOUBLE PRECISION DT, PV(3,2), P(3)
    INTEGER I

    DO 1 I=1,3
        P(I) = PV(I,1) + PV(I,2)*DT
1   CONTINUE

END SUBROUTINE iau_PVUP