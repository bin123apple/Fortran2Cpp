PROGRAM TestFortranError
    CHARACTER*9 A  ! Incorrect length
    CHARACTER*7 B  ! Incorrect length
    A = 'gfortran'
    B = 'rocks'
    CALL T(A,B)

CONTAINS

    SUBROUTINE T(A,B)
        CHARACTER*(*) A,B
        IF(LEN(A)/=10) CALL abort()
        IF(LEN(B)/=8) CALL abort()
    END SUBROUTINE T

END PROGRAM TestFortranError