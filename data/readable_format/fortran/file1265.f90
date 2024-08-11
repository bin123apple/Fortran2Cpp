module lgemmx_module
contains
    subroutine LGEMMX(m, n, k, alpha, a, inc1a, inc2a, b, inc1b, inc2b, beta, c, inc1c, inc2c)
        integer :: m, n, k, inc1a, inc2a, inc1b, inc2b, inc1c, inc2c
        logical*8 :: alpha, beta
        logical*8 :: a(*), b(*), c(*)
        integer :: i

        do i = 1, m
            c(i) = a(i) .AND. b(i)
        end do
    end subroutine LGEMMX
end module lgemmx_module

program test_lgemmx
    use lgemmx_module
    implicit none
    integer :: m, n, k, inc1a, inc2a, inc1b, inc2b, inc1c, inc2c
    logical*8 :: alpha, beta
    logical*8 :: a(3), b(3), c(3)
    integer :: i

    ! Initialize test data
    m = 3
    alpha = .true.
    beta = .false.
    a = [ .false., .true., .true. ]
    b = [ .false., .true., .true. ]
    ! Call LGEMMX subroutine
    call LGEMMX(m, n, k, alpha, a, inc1a, inc2a, b, inc1b, inc2b, beta, c, inc1c, inc2c)

    ! Output the results
    print *, "Fortran Stdout: Results in array c:"
    do i = 1, m
        print *, c(i)
    end do
end program test_lgemmx