PROGRAM test_sum
    IMPLICIT NONE
    INTEGER, PARAMETER :: DP = SELECTED_REAL_KIND(p=15, r=307)
    REAL(KIND=DP) :: array(200001), result, expected
    INTEGER :: i

    ! Initialize array
    DO i = 1, 200001
        array(i) = REAL(i, KIND=DP)
    END DO

    ! Compute sum
    result = 0.0_DP
    DO i = 1, 200001
        result = result + array(i)
    END DO

    ! Expected result for validation
    expected = 0.5_DP * 200001 * (200001 + 1)

    ! Check results
    IF (ABS(result - expected) < 1.0E-10_DP) THEN
        PRINT *, "Test passed. Sum = ", result
    ELSE
        PRINT *, "Test failed. Expected: ", expected, " Got: ", result
    END IF
END PROGRAM test_sum