program main_program
    implicit none
    integer :: a
    a = getA()
    print *, a
contains
    function getA() result(res)
        integer :: res
        res = 1
    end function getA
end program main_program