module kinds
    implicit none
    integer, parameter :: dp = selected_real_kind(15, 307)
end module kinds

module dot_module
    use kinds, only: dp
    implicit none
contains
    real(kind=dp) function dot(x, y, n)
        integer, intent(in) :: n
        real(kind=dp), intent(in) :: x(n)
        real(kind=dp), intent(in) :: y(n)
        integer :: i
        dot = 0.0_dp
        do i = 1, n
            dot = dot + x(i) * y(i)
        end do
    end function dot
end module dot_module

program test_dot
    use kinds, only: dp
    use dot_module, only: dot
    implicit none
    real(kind=dp) :: result
    real(kind=dp), dimension(3) :: x = [1.0_dp, 2.0_dp, 3.0_dp]
    real(kind=dp), dimension(3) :: y = [4.0_dp, 5.0_dp, 6.0_dp]
    integer :: n = 3

    result = dot(x, y, n)
    print *, "Dot product is:", result
    ! Expected output: Dot product is: 32.0
end program test_dot