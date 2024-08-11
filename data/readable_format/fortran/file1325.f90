! Assuming you've added a function called 'compute' in a module.
module myModule
contains
    function compute(x) result(y)
        integer, intent(in) :: x
        integer :: y
        y = x * x
    end function compute
end module myModule

program testCompute
    use myModule
    implicit none
    integer :: result

    result = compute(2)
    if (result == 4) then
        print *, "Test passed."
    else
        print *, "Test failed."
    endif
end program testCompute