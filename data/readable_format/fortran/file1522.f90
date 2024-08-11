! Define the subroutines foo and foovec
subroutine foo(a)
    integer :: a
    write(*,*) "Hello from Fortran!!"
    write(*,*) "input value a=",a
end subroutine foo

subroutine foovec(a)
    integer, dimension(10) :: a
    write(*,*) "Hello from Fortran!!"
    write(*,*) "input value avec=",a
end subroutine foovec

! Main program to test the subroutines
program test_foo_foovec
    implicit none
    integer :: test_scalar
    integer, dimension(10) :: test_vector

    ! Test for foo
    test_scalar = 5
    call foo(test_scalar)

    ! Test for foovec
    test_vector = (/1, 2, 3, 4, 5, 6, 7, 8, 9, 10/)
    call foovec(test_vector)
end program test_foo_foovec