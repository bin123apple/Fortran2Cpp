MODULE nrtype
    INTEGER, PARAMETER :: SP = KIND(1.0)
    INTEGER, PARAMETER :: I4B = SELECTED_INT_KIND(9)
END MODULE nrtype

MODULE nrutil
    USE nrtype
    CONTAINS
    FUNCTION product(start, stop, step) RESULT(res)
        INTEGER(SP), INTENT(IN) :: start, stop, step
        REAL(SP) :: res
        INTEGER(SP) :: i
        res = 1.0_SP
        DO i = start, stop, step
            res = res * REAL(i, SP)
        END DO
    END FUNCTION product
END MODULE nrutil

PROGRAM LegendreTest
    USE nrtype
    USE nrutil
    IMPLICIT NONE
    REAL(SP) :: result
    REAL(SP), PARAMETER :: tolerance = 1.0E-6_SP

    PRINT *, "Running Fortran Tests"

    ! Test case 1
    result = plgndr_s(2, 1, 0.5_SP)
    CALL assert_approx_equal(result, -2.598076211_SP, tolerance, 'Test 1')

    ! Test case 2
    result = plgndr_s(1, 0, 0.0_SP)
    CALL assert_approx_equal(result, 0.0_SP, tolerance, 'Test 2')

CONTAINS

    FUNCTION plgndr_s(l, m, x) RESULT(plgndr_s_val)
        USE nrtype
        USE nrutil
        INTEGER(I4B), INTENT(IN) :: l, m
        REAL(SP), INTENT(IN) :: x
        REAL(SP) :: plgndr_s_val
        INTEGER(I4B) :: ll
        REAL(SP) :: pll, pmm, pmmp1, somx2
        
        pmm = 1.0_SP
        IF (m > 0) THEN
            somx2 = SQRT((1.0_SP - x) * (1.0_SP + x))
            pmm = 1.0_SP
            DO ll = 1, m
                pmm = pmm * 2.0_SP * ll * somx2
            END DO
            IF (MOD(m,2) == 1) pmm = -pmm
        END IF
        IF (l == m) THEN
            plgndr_s_val = pmm
        ELSE
            pmmp1 = x * (2 * m + 1) * pmm
            IF (l == m + 1) THEN
                plgndr_s_val = pmmp1
            ELSE
                DO ll = m + 2, l
                    pll = (x * (2 * ll - 1) * pmmp1 - (ll + m - 1) * pmm) / (ll - m)
                    pmm = pmmp1
                    pmmp1 = pll
                END DO
                plgndr_s_val = pll
            END IF
        END IF
    END FUNCTION plgndr_s

    SUBROUTINE assert_approx_equal(actual, expected, tolerance, message)
        REAL(SP), INTENT(IN) :: actual, expected, tolerance
        CHARACTER(*), INTENT(IN) :: message
        IF (ABS(actual - expected) > tolerance) THEN
            PRINT *, TRIM(message)//": FAIL. Expected:", expected, "Got:", actual
        ELSE
            PRINT *, TRIM(message)//": PASS."
        END IF
    END SUBROUTINE assert_approx_equal

END PROGRAM LegendreTest