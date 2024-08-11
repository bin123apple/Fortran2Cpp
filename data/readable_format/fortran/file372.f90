module elem_assign
    implicit none
    type mytype
        integer :: x
    end type mytype

    interface assignment(=)
        module procedure myassign
    end interface

contains

    elemental subroutine myassign(x, y)
        type(mytype), intent(out) :: x
        type(mytype), intent(in) :: y
        x%x = y%x * 2
    end subroutine myassign

end module elem_assign

module test_utils
    implicit none
contains

    subroutine assertEqualIntArrays(a, b, size)
        integer, dimension(:), intent(in) :: a, b
        integer, intent(in) :: size
        integer :: i
        do i = 1, size
            if (a(i) /= b(i)) then
                print *, "Assertion failed at index: ", i, "a(i)=", a(i), "b(i)=", b(i)
                stop 1
            end if
        end do
        print *, "Test passed."
    end subroutine assertEqualIntArrays

end module test_utils

program test
    use elem_assign
    use test_utils
    implicit none
    type(mytype) :: y(6), x(6) = [mytype(1), mytype(20), mytype(300), &
                                  mytype(4000), mytype(50000), &
                                  mytype(1000000)]
    type(mytype) :: z(2, 3)
    integer :: expected(6)

    x = [x(2), x(3), x(1), x(4), x(5), x(6)]
    expected = [40, 600, 2, 8000, 100000, 2000000]
    call assertEqualIntArrays([x%x], expected, 6)

    print *, "Fortran code: All tests passed."
end program test