PROGRAM XTest
    implicit none
    TYPE T
        INTEGER :: I
    END TYPE T
    TYPE(T), TARGET :: T1( 0:3 )
    
    CALL test_bounds_checks()

contains
    subroutine check (lbnd, ubnd, lower, upper, error_flag)
        integer :: lbnd, ubnd, lower, upper
        integer, intent(inout) :: error_flag
        if (lbnd .ne. lower) error_flag = 1
        if (ubnd .ne. upper) error_flag = 2
    end subroutine check

    subroutine test_bounds_checks()
        integer :: error_flag
        error_flag = 0

        associate( P => T1 % I )
            call check (lbound (P, 1), ubound (P, 1), 1, 4, error_flag)
            if (error_flag .ne. 0) then
                print *, "Error in P bounds check with error code:", error_flag
                return
            end if
        end associate

        associate( P2 => T1(:) % I )
            call check (lbound (P2, 1), ubound (P2, 1), 1, 4, error_flag)
            if (error_flag .ne. 0) then
                print *, "Error in P2 bounds check with error code:", error_flag
                return
            end if
        end associate

        associate( Q => T1 )
            call check (lbound (Q, 1), ubound (Q, 1), 0, 3, error_flag)
            if (error_flag .ne. 0) then
                print *, "Error in Q bounds check with error code:", error_flag
                return
            end if
        end associate

        associate( Q2 => T1(:) )
            call check (lbound (Q2, 1), ubound (Q2, 1), 1, 4, error_flag)
            if (error_flag .ne. 0) then
                print *, "Error in Q2 bounds check with error code:", error_flag
                return
            end if
        end associate

        print *, "All checks passed successfully."
    end subroutine test_bounds_checks

END PROGRAM XTest