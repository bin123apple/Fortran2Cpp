! test_functions.f90
module functions
    implicit none
contains
    function f() result(g)
        integer :: g
        g = 1
    end function f

    recursive function rf() result(g)
        integer :: g
        g = 1
    end function rf
end module functions

program test
    use functions
    implicit none
    
    print *, "Testing f() function"
    if (f() == 1) then
        print *, "PASS: f() returned 1"
    else
        print *, "FAIL: f() did not return 1"
    end if

    print *, "Testing rf() function"
    if (rf() == 1) then
        print *, "PASS: rf() returned 1"
    else
        print *, "FAIL: rf() did not return 1"
    end if
end program test