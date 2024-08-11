PROGRAM eps
    IMPLICIT NONE
    
    INTEGER, PARAMETER :: dp = KIND(1.0D0) ! Double precision kind
    INTEGER :: i
    REAL(KIND=dp) :: d, x, x_p, calculated_epsilon
    
    x = 1.0_dp
    d = 2.0_dp
    
    DO i = 1, 2000
        x_p = x + d
        IF (x_p == x) EXIT
        d = d / 2.0_dp
    END DO
    
    calculated_epsilon = d * 2.0_dp
    
    PRINT *, "Iterations: ", i, "Calculated Epsilon: ", calculated_epsilon, "Built-in Epsilon: ", EPSILON(1.0_dp)
    
END PROGRAM eps