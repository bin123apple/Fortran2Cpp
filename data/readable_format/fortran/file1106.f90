! Define the subroutine drotat within the same file
SUBROUTINE drotat(NI, XI, XJ, E1B, ENUC, RIJ)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: NI
    REAL(KIND=8), DIMENSION(3), INTENT(IN) :: XI, XJ
    REAL(KIND=8), DIMENSION(10), INTENT(OUT) :: E1B
    REAL(KIND=8), INTENT(OUT) :: ENUC
    REAL(KIND=8), INTENT(IN) :: RIJ
    
    ! Hypothetical implementation of drotat
    ENUC = SUM(XI) + SUM(XJ)
    E1B = 10.0 * RIJ
END SUBROUTINE drotat

! Main program to test the drotat subroutine
PROGRAM main
    IMPLICIT NONE
    REAL(KIND=8), DIMENSION(3) :: XI = [1.0, 2.0, 3.0]
    REAL(KIND=8), DIMENSION(3) :: XJ = [4.0, 5.0, 6.0]
    REAL(KIND=8), DIMENSION(10) :: E1B
    REAL(KIND=8) :: ENUC
    REAL(KIND=8) :: RIJ = 2.0
    INTEGER :: i
    
    CALL drotat(3, XI, XJ, E1B, ENUC, RIJ)
    
    PRINT *, 'ENUC:', ENUC
    PRINT *, 'E1B:'
    DO i = 1, 10
        PRINT *, E1B(i)
    END DO
END PROGRAM main