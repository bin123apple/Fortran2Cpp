module propagate_module
    implicit none
    integer, parameter :: dp = selected_real_kind(15, 307) ! Double precision
contains
    subroutine calculatePotential(V, n)
        integer, intent(in) :: n
        complex(kind=dp), intent(out) :: V(n)
        integer :: i
        do i = 1, n
            V(i) = cmplx(i*0.01, -i*0.01, kind=dp)
        end do
    end subroutine calculatePotential
end module propagate_module

program test_propagate
    use propagate_module
    implicit none
    integer, parameter :: n = 100
    complex(kind=dp) :: V(n)
    call calculatePotential(V, n)
    print *, "Fortran Stdout: First element of V:", V(1)
end program test_propagate