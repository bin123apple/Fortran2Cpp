MODULE seto2_module
    IMPLICIT NONE
CONTAINS
    SUBROUTINE seto2(nz, z, nw, wl, cz, o2xs1, dto2)
        INTEGER, INTENT(IN) :: nz, nw
        REAL, INTENT(IN) :: z(nz), wl(nw), cz(nz), o2xs1(nw)
        REAL, INTENT(OUT) :: dto2(nz, nw)
        INTEGER :: iz, iw

        DO iz = 1, nz
            DO iw = 1, nw - 1
                dto2(iz, iw) = 0.2095 * cz(iz) * o2xs1(iw)
            END DO
            dto2(iz, nw) = 0.0
        END DO
    END SUBROUTINE seto2
END MODULE seto2_module

PROGRAM test
    USE seto2_module
    IMPLICIT NONE
    INTEGER, PARAMETER :: nz=3, nw=4
    REAL :: z(nz) = (/1.0, 2.0, 3.0/)
    REAL :: wl(nw) = (/0.4, 0.5, 0.6, 0.7/)
    REAL :: cz(nz) = (/0.1, 0.2, 0.3/)
    REAL :: o2xs1(nw) = (/0.01, 0.02, 0.03, 0.04/)
    REAL :: dto2(nz, nw)
    INTEGER :: iz, iw

    CALL seto2(nz, z, nw, wl, cz, o2xs1, dto2)

    PRINT *, 'dto2:'
    DO iz = 1, nz
        PRINT '(4F10.6)', dto2(iz, :)
    END DO
END PROGRAM test