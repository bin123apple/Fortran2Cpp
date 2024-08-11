module test_helpers
contains
    function check_arrays() result(res)
       integer :: res
       integer :: i
       real, dimension(1:3) :: a, b, c
       a = 128
       b = 0
       do i = 1, 16
         c = (/ i, i - 5, i + 5 /)
         a = min (a, c)
         b = max (b, c)
       end do
       if (any (a /= (/ 1, -4, 6 /)) .or. any (b /= (/ 16, 11, 21 /))) then
           res = 1
       else
           res = 0
       endif
    end function check_arrays
end module test_helpers

program test
    use test_helpers
    integer :: result

    result = check_arrays()

    if (result == 0) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    endif
end program test