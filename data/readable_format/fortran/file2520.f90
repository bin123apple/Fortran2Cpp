program testch
    implicit none
    if (ch() .eq. "hello") then
        print *, "Test passed!"
    else
        print *, "Test failed!"
    end if

contains
    function ch () result(res)
        character(len=10) :: res
        res = "hello"
    end function ch
end program testch