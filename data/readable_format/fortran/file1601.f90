program main
    implicit none
    ! Main program variable
    integer :: i

    ! Run the unit tests before the main functionality
    call test_evenly_divis()

    i = 1
    do
        if (evenly_divis(i)) then
            exit
        end if
        i = i + 1
    end do
    print *, "The smallest number evenly divisible by all numbers from 1 to 20 is: ", i

contains
    function evenly_divis(a) result(out)
        integer, intent(in) :: a
        logical :: out
        integer :: i
        out = .true.
        do i = 1, 20
            if (mod(a, i) /= 0) then
                out = .false.
                exit
            end if
        end do
    end function evenly_divis

    subroutine test_evenly_divis()
        implicit none
        integer :: test_cases(2), i
        logical :: expected_results(2), result

        ! Define test cases and their expected results
        test_cases = (/10, 2520/)
        expected_results = (/.false., .true./)

        print *, "Running unit tests..."
        do i = 1, size(test_cases)
            result = evenly_divis(test_cases(i))
            if (result .eqv. expected_results(i)) then
                print *, "Test ", i, " with input ", test_cases(i), " passed."
            else
                print *, "Test ", i, " with input ", test_cases(i), " failed!"
            end if
        end do
    end subroutine test_evenly_divis
end program main