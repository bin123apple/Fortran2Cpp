module palindrome_utils
    implicit none
contains
    function number_to_string(num, base) result(str)
        integer, intent(in) :: num
        integer, optional, intent(in) :: base
        character(:), allocatable :: str
        character(:), allocatable :: fmt
        character(256) :: template
        integer :: b

        b = 10
        if (present(base)) b = base
        allocate(fmt, source='')
        str = template
        select case (b)
        case (2)
            fmt = '(b0)'
        case (10)
            fmt = '(i0)'
        case default
            error stop
        end select
        write(str, fmt) num
        str = trim(adjustl(str))
    end function number_to_string

    function test_palindromic(str) result(result)
        character(*), intent(in) :: str
        logical :: result
        integer :: n, i

        n = len(str)
        result = .false.
        do i = 1, n / 2
            if (str(i:i) /= str(n-i+1:n-i+1)) return
        end do
        result = .true.
    end function test_palindromic
end module palindrome_utils

program double_base_palindromes
    use palindrome_utils
    implicit none
    integer, parameter :: max_number = 1000000

    call test_cases
    call solver

contains

    subroutine test_cases()
        implicit none
        character(:), allocatable :: test_str
        logical :: result

        ! Test number_to_string with base 10
        test_str = number_to_string(123, 10)
        if (test_str /= '123') then
            print *, "Test failed: number_to_string(123, 10)"
        else
            print *, "Test passed: number_to_string(123, 10)"
        end if

        ! Test number_to_string with base 2
        test_str = number_to_string(5, 2)
        if (test_str /= '101') then
            print *, "Test failed: number_to_string(5, 2)"
        else
            print *, "Test passed: number_to_string(5, 2)"
        end if

        ! Test test_palindromic
        result = test_palindromic('12321')
        if (.not. result) then
            print *, "Test failed: test_palindromic('12321')"
        else
            print *, "Test passed: test_palindromic('12321')"
        end if
    end subroutine test_cases

    subroutine solver
        use palindrome_utils
        integer :: i, sum
        character(:), allocatable :: n_10, n_2

        sum = 0
        do i = 1, max_number
            n_10 = number_to_string(i, 10)
            n_2 = number_to_string(i, 2)
            if (.not. test_palindromic(n_10)) cycle
            if (.not. test_palindromic(n_2)) cycle
            sum = sum + i
            print *, n_10, ', ', n_2
        end do
        print *, 'result =', sum
    end subroutine solver

end program double_base_palindromes