program digit_factorials
    implicit none
    integer :: max_digit

    ! Function and subroutine declarations are moved to a contains section below
    
    ! Call tests and solver here, outside any contains section
    call test_factorial()
    call test_digit_sequence()
    call solver

contains

    function digit_sequence(n) result(d)
        integer, intent(in) :: n
        integer, allocatable :: d(:)
        integer :: a, i

        allocate(d(10)) ! Assuming a maximum of 10 digits for simplicity
        d = 0
        a = n
        i = 0
        do while (a > 0)
            i = i + 1
            d(i) = mod(a, 10)
            a = a / 10
        end do
        d = d(1:i)
    end function digit_sequence

    function factorial(n) result(f)
        integer, intent(in) :: n
        integer :: f
        integer :: i

        f = 1
        if (n > 0) then
            do i = 2, n
                f = f * i
            end do
        end if
    end function factorial

    subroutine solver
        integer :: n, p, q, i, j, a, sum
        integer, allocatable :: seq(:)

        p = factorial(9)
        n = 1
        do while (p * n > 10 ** (n - 1))
            n = n + 1
        end do
        max_digit = n

        sum = 0
        do i = 3, p * max_digit
            seq = digit_sequence(i)
            a = 0
            do j = 1, size(seq)
                q = factorial(seq(j))
                a = a + q
            end do
            if (a == i) then
                sum  = sum + a
                print *, i
            end if
        end do

        print *, 'result =', sum

    end subroutine solver

    subroutine test_factorial()
        integer :: result
        result = factorial(5)
        if (result /= 120) then
            print *, 'Factorial test failed'
        else
            print *, 'Factorial test passed'
        end if
    end subroutine test_factorial

    subroutine test_digit_sequence()
        integer, allocatable :: seq(:)
        integer :: n
        n = 145
        seq = digit_sequence(n)
        if (size(seq) == 3 .and. seq(1) == 5 .and. seq(2) == 4 .and. seq(3) == 1) then
            print *, 'Digit sequence test passed'
        else
            print *, 'Digit sequence test failed'
        end if
    end subroutine test_digit_sequence

end program digit_factorials