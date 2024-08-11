module m11
contains
    function add_two_numbers(a, b)
        integer, intent(in) :: a, b
        integer :: add_two_numbers
        add_two_numbers = a + b
    end function add_two_numbers
end module m11

module m12
    ! Any functionalities for m12
end module m12

module m1
    use m11
    use m12
    ! Any functionalities for m1
end module m1

module m2
    ! Any functionalities for m2
end module m2

module m3
    ! Any functionalities for m3
end module m3

module t
    use m1
    use m2
    use m3
    ! Any functionalities for t
end module t

module t2
    use m1
    use m2
    use m3
    ! Any functionalities for t2
end module t2

module t3
    use t
    ! Any functionalities for t3
end module t3

! Main program to demonstrate usage and perform a simple test
program main
    use m11
    implicit none
    integer :: result

    result = add_two_numbers(2, 3)

    print *, "Testing add_two_numbers with inputs 2 and 3."
    if (result == 5) then
        print *, "Test passed. Result is:", result
    else
        print *, "Test failed. Result is:", result
    endif
end program main