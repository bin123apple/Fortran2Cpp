module m
    implicit none
    contains
        function add(a, b) result(c)
            integer, intent(in) :: a, b
            integer :: c

            c = a + b
        end function add
end module m

program main
    use m
    implicit none
    integer :: result

    result = add(5, 3)
    print *, "The result of adding 5 and 3 is ", result
end program main