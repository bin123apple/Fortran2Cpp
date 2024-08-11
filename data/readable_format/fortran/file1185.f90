module math_operations
    implicit none
contains
    function add(a, b) result(res)
        integer, intent(in) :: a, b
        integer :: res
        res = a + b
    end function add
end module math_operations

program main
    use math_operations
    implicit none
    integer :: result

    result = add(2, 3)
    print *, "Result of adding 2 and 3 is ", result
end program main