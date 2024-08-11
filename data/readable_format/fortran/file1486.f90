module fib_module
    implicit none
contains
    function calc_even_fib_sum(maximum) result(sumx)
        integer, intent(in) :: maximum
        integer :: sumx
        integer :: first, second, tmp

        sumx = 0
        first = 1
        second = 1

        do
            tmp = first + second

            if (tmp > maximum) exit

            if (mod(tmp, 2) == 0) then
                sumx = sumx + tmp
            end if

            first = second
            second = tmp
        end do
    end function calc_even_fib_sum
end module fib_module

program even_fib_test
    use fib_module
    implicit none
    integer :: expected_sum, actual_sum

    expected_sum = 4613732 ! Pre-calculated expected result
    actual_sum = calc_even_fib_sum(4000000)

    if (actual_sum == expected_sum) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    end if
end program even_fib_test