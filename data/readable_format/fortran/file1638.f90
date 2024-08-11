program test_ppm_tree_cutpos
    implicit none

    ! Definitions
    integer, parameter :: sp = kind(1.0)
    integer, parameter :: dp = kind(1.0d0)
    real(sp) :: result_sp
    real(dp) :: result_dp

    ! Testing single precision
    call ppm_tree_cutpos_s(result_sp)
    print *, "Single Precision Result: ", result_sp

    ! Testing double precision
    call ppm_tree_cutpos_d(result_dp)
    print *, "Double Precision Result: ", result_dp

contains

    subroutine ppm_tree_cutpos_s(result)
        real(sp), intent(out) :: result
        ! Assuming some computation here
        result = 1.23_sp
    end subroutine ppm_tree_cutpos_s

    subroutine ppm_tree_cutpos_d(result)
        real(dp), intent(out) :: result
        ! Assuming some computation here
        result = 1.2345678901234567_dp
    end subroutine ppm_tree_cutpos_d

end program test_ppm_tree_cutpos