module kinds
    implicit none

    integer, parameter :: dp = selected_real_kind(15, 307)
    integer, parameter :: sp = selected_real_kind(6, 37)

contains

    subroutine test_kinds()
        implicit none
        real(dp) :: var_dp
        real(sp) :: var_sp
        
        var_dp = 1.0_dp
        var_sp = 1.0_sp
        
        ! Test cases to check the precision
        if (abs(var_dp - 1.0_dp) > epsilon(var_dp)) then
            write(*, *) "Double Precision Test Failed"
            call exit(1)
        else
            write(*, *) "Double Precision Test Passed"
        end if
        
        if (abs(var_sp - 1.0_sp) > epsilon(var_sp)) then
            write(*, *) "Single Precision Test Failed"
            call exit(1)
        else
            write(*, *) "Single Precision Test Passed"
        end if
    end subroutine test_kinds
end module kinds

program main
    use kinds
    call test_kinds()
end program main