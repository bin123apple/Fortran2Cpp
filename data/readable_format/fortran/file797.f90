! cvmgz_combined.f90
PROGRAM test_cvmgz
    IMPLICIT NONE
    REAL :: result

    ! Call the cvmgz function with test values and print the result
    result = cvmgz(1.0, 2.0, 0.0)
    PRINT *, "Test 1 (expect 1.0):", result

    result = cvmgz(1.0, 2.0, 1.0)
    PRINT *, "Test 2 (expect 2.0):", result

CONTAINS

    REAL FUNCTION cvmgz(trueVal, falseVal, test)
        REAL, INTENT(IN) :: trueVal, falseVal, test

        IF (test .EQ. 0.) THEN
            cvmgz = trueVal
        ELSE
            cvmgz = falseVal
        END IF
    END FUNCTION cvmgz

END PROGRAM test_cvmgz