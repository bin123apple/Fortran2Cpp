module prime_number
    implicit none
contains
    subroutine sieve_of_eratosthenes(n, table)
        integer, intent(in) :: n
        logical, allocatable :: table(:)
        integer :: i, j

        allocate(table(n))
        table = .true.
        table(1) = .false.
        do i = 2, n
            if (table(i)) then
                do j = i * 2, n, i
                    table(j) = .false.
                end do
            end if
        end do
    end subroutine sieve_of_eratosthenes
end module prime_number

program test_prime_number
    use prime_number
    implicit none

    logical, allocatable :: table(:)
    integer :: n, i
    logical :: success

    ! Test cases for n
    do n = 2, 20, 6
        call sieve_of_eratosthenes(n, table)
        success = .true.
        do i = 2, n
            if (table(i) .neqv. is_prime(i)) then
                success = .false.
                exit
            end if
        end do
        if (success) then
            print *, "Test passed for n =", n
        else
            print *, "Test failed for n =", n
        end if
    end do

contains
    ! A simple function to check if a number is prime (for testing)
    function is_prime(x) result(is_p)
        integer, intent(in) :: x
        logical :: is_p
        integer :: i

        is_p = .true.
        if (x < 2) then
            is_p = .false.
            return
        end if
        do i = 2, sqrt(real(x))
            if (mod(x, i) == 0) then
                is_p = .false.
                return
            end if
        end do
    end function is_prime
end program test_prime_number