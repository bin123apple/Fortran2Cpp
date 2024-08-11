module probability_distributions
    implicit none
contains
    subroutine initialize_random_seed()
        integer :: i, n, clock
        integer, dimension(:), allocatable :: seed

        call random_seed(size = n)
        allocate(seed(n))

        call system_clock(count=clock)
        seed = clock + 37 * (/ (i - 1, i = 1, n) /)
        call random_seed(put = seed)

        deallocate(seed)
    end subroutine initialize_random_seed

    ! Box-Muller transform for generating normal distributed numbers
    function generate_normal_box_muller() result(z)
        real :: u1, u2
        real :: z

        call random_number(u1)
        call random_number(u2)

        z = sqrt(-2.0 * log(u1)) * cos(2.0 * 3.14159265 * u2)
    end function generate_normal_box_muller

end module probability_distributions

program test_probability_distributions
    use probability_distributions
    implicit none
    real :: num

    call initialize_random_seed()
    num = generate_normal_box_muller()

    print *, "Generated normally distributed number (Box-Muller): ", num
end program test_probability_distributions