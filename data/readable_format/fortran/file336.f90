PROGRAM test_compute_eref_band
    IMPLICIT NONE
    INTEGER, PARAMETER :: DP = SELECTED_REAL_KIND(15, 307)
    REAL(DP), ALLOCATABLE :: e(:)
    REAL(DP) :: eref
    LOGICAL :: print_eref
    INTEGER :: nbnd

    ! Mock values for global variables
    REAL(DP), PARAMETER :: rytoev = 13.605693009_DP
    REAL(DP) :: ef = 10.0_DP
    REAL(DP) :: degauss = 0.0_DP
    INTEGER :: nelec = 10
    LOGICAL :: noncolin = .FALSE.

    nbnd = 5
    ALLOCATE(e(nbnd))
    e = [5.0_DP, 10.0_DP, 15.0_DP, 20.0_DP, 25.0_DP]

    CALL compute_eref_band(e, nbnd, eref, print_eref)

    PRINT *, "Computed eref:", eref
    PRINT *, "Should print eref:", print_eref

CONTAINS

    SUBROUTINE compute_eref_band(e, nbnd, eref, print_eref)
        REAL(DP), INTENT(IN) :: e(nbnd)
        INTEGER, INTENT(IN) :: nbnd
        REAL(DP), INTENT(OUT) :: eref
        LOGICAL, INTENT(OUT) :: print_eref
        INTEGER :: nband_occ, ibnd

        print_eref = .FALSE.
        eref = -1d20
        IF (degauss > 0.0_DP) THEN
            eref = ef * rytoev
            print_eref = .TRUE.
        ELSE
            nband_occ = NINT(nelec / 2.0_DP)
            IF (noncolin) nband_occ = nband_occ * 2
            DO ibnd = 1, nband_occ
                IF (e(ibnd) > eref) eref = e(ibnd)
            END DO
        END IF
    END SUBROUTINE compute_eref_band

END PROGRAM test_compute_eref_band