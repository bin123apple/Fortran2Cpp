module foo_module
contains
    subroutine foo(a)
        integer, dimension(4) :: a
        
        where (a(1:4) .ne. 0)
            a(1:4) = 1
        end where
    end subroutine foo
end module foo_module

program test_foo
    use foo_module
    implicit none
    integer :: a(4)
    integer :: i

    ! Test case 1: All elements are non-zero
    a = (/1, 2, 3, 4/)
    call foo(a)
    print *, "Test 1: ", (a(i), i=1, 4)

    ! Test case 2: Some elements are zero
    a = (/0, 2, 0, 4/)
    call foo(a)
    print *, "Test 2: ", (a(i), i=1, 4)

    ! Test case 3: All elements are zero
    a = (/0, 0, 0, 0/)
    call foo(a)
    print *, "Test 3: ", (a(i), i=1, 4)
end program test_foo