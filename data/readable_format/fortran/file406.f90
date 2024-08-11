module rrlw_kg02
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none
    integer, parameter :: kind_rb = real64
    real(kind=kind_rb) :: test_array(10)
contains
    subroutine fill_array()
        integer :: i
        do i = 1, 10
            test_array(i) = real(i, kind_rb)
        end do
    end subroutine fill_array
end module rrlw_kg02

program test_rrlw_kg02
    use rrlw_kg02
    implicit none

    call fill_array()
    call print_test_array()

contains
    subroutine print_test_array()
        integer :: i
        do i = 1, 10
            print *, 'test_array(', i, ') = ', test_array(i)
        end do
    end subroutine print_test_array
end program test_rrlw_kg02