! Save this file as test_norm.f90
module m_normal
    use iso_c_binding, only: c_double
    implicit none

contains

    pure function normal(v) result(n)
        real(c_double), intent(in) :: v(2)
        real(c_double) :: n(2)
        n(1) = v(2)
        n(2) = -v(1)
        n(:) = n(:) / sqrt(sum(n(:)**2))
    end function normal

end module m_normal

program test_norm
    use m_normal, only: normal
    use iso_c_binding, only: c_double
    implicit none
    real(c_double), allocatable :: a(:), b(:)

    ! Test case 1: Vector in the first quadrant
    a = [1.d0, 1.d0]
    b = normal(a)
    print *, "Test 1: ", b

    ! Test case 2: Vector in the second quadrant
    a = [-1.d0, 1.d0]
    b = normal(a)
    print *, "Test 2: ", b

    ! Test case 3: Vector with different magnitude
    a = [3.d0, 4.d0]
    b = normal(a)
    print *, "Test 3: ", b

end program test_norm