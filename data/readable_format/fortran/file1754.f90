PROGRAM P
    IMPLICIT NONE
    INTRINSIC DCONJG, DIMAG
    COMPLEX(KIND=8) :: K, CExpected
    REAL(KIND=8) :: IExpected

    ! Test values
    K = (3.0D0, 4.0D0)
    CExpected = (3.0D0, -4.0D0) ! Expected conjugate
    IExpected = 4.0D0          ! Expected imaginary part

    ! Test the DCONJG function
    IF (DCONJG(K) == CExpected) THEN
        PRINT *, "DCONJG Test Passed"
    ELSE
        PRINT *, "DCONJG Test Failed"
    END IF

    ! Test the DIMAG function
    IF (DIMAG(K) == IExpected) THEN
        PRINT *, "DIMAG Test Passed"
    ELSE
        PRINT *, "DIMAG Test Failed"
    END IF
END PROGRAM P