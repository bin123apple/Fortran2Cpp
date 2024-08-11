! Main subroutine
subroutine foo(n1,n2,n3,n4)
    integer :: n1, n3
    integer(kind=8) :: n2(3), n4
    n4 = (n1 + n2(3))/2 + n3
end subroutine foo

! Unit test for the subroutine
program test_foo
    implicit none
    integer :: n1, n3
    integer(kind=8) :: n2(3), n4

    ! Test 1
    n1 = 2
    n2 = (/1_8, 2_8, 3_8/)
    n3 = 1
    call foo(n1, n2, n3, n4)
    if (n4 /= 3) then
        print *, "Test failed: Expected 3, got", n4
    else
        print *, "Test 1 passed: n4 = ", n4
    endif

end program test_foo