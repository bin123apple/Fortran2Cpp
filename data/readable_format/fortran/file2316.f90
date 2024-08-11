MODULE mod_kind
    INTEGER, PARAMETER :: sp = KIND(1.0)
END MODULE mod_kind

SUBROUTINE boite(x, y, dx, dy, desx, desy)
    USE mod_kind

    IMPLICIT NONE

    REAL (KIND=sp), INTENT(IN) :: x, y, dx, dy
    REAL (KIND=sp), DIMENSION(5), INTENT(OUT) :: desx, desy

    desx(1) = x - dx
    desx(2) = x + dx    
    desx(3) = x + dx    
    desx(4) = x - dx    
    desx(5) = x - dx    
    desy(1) = y - dy    
    desy(2) = y - dy
    desy(3) = y + dy
    desy(4) = y + dy
    desy(5) = y - dy

    RETURN
END SUBROUTINE boite

PROGRAM test_boite
    USE mod_kind

    IMPLICIT NONE

    REAL (KIND=sp) :: x, y, dx, dy
    REAL (KIND=sp), DIMENSION(5) :: desx, desy
    INTEGER :: i

    x = 1.0_sp
    y = 2.0_sp
    dx = 0.5_sp
    dy = 0.5_sp

    CALL boite(x, y, dx, dy, desx, desy)

    PRINT *, 'desx = ', desx
    PRINT *, 'desy = ', desy

END PROGRAM test_boite