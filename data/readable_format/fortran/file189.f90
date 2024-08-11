program test_phys_constants
    implicit none
    real(kind=8), parameter :: h=6.626d-27
    real(kind=8), parameter :: k=1.38d-16
    real(kind=8), parameter :: c=2.99792458d10
    real(kind=8), parameter :: e=4.8032d-10
    real(kind=8), parameter :: G=6.67d-8
    real(kind=8), parameter :: m=9.10938188d-28
    real(kind=8), parameter :: mp=1.67262158d-24
    real(kind=8), parameter :: pi=acos(-1d0)
    real(kind=8), parameter :: c2=c*c
    real(kind=8), parameter :: sigb=5.6704d-5
    real(kind=8), parameter :: msun=1.998d33
    real(kind=8), parameter :: sigt=6.6523d-25

    ! Test a few constants
    call test_value("h", h, 6.626d-27)
    call test_value("k", k, 1.38d-16)
    call test_value("pi", pi, acos(-1d0))

contains

    subroutine test_value(name, value, expected)
        character(len=*), intent(in) :: name
        real(kind=8), intent(in) :: value, expected

        if (abs(value - expected) < 1d-30) then
            print *, "Test passed for ", name
        else
            print *, "Test failed for ", name, " Expected: ", expected, " Got: ", value
        endif
    end subroutine test_value

end program test_phys_constants