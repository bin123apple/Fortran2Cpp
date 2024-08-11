program main
    implicit none

    integer, parameter :: n = 20480
    real(8) :: a, m, tmp
    integer :: i
    real(8), dimension(:), allocatable :: x
    real(8), dimension(:), allocatable :: y
    real(8), dimension(:), allocatable :: yomp
    real(8), dimension(:), allocatable :: yacc

    ! Initialize the random number generator
    call random_seed()

    ! Generate a random number for 'a'
    call random_number(a)

    ! Allocate memory for the arrays
    allocate(x(n))
    allocate(y(n))
    allocate(yomp(n))
    allocate(yacc(n))

    ! Fill 'x' and 'y' with random numbers
    call random_number(x)
    call random_number(y)

    ! OpenMP section for parallel processing
    !$omp parallel do
    do i = 1, n
        yomp(i) = a*x(i) + y(i)
    end do
    !$omp end parallel do

    ! OpenACC section for parallel processing on GPU or other accelerators
    !$acc kernels copyin(x(1:n),y(1:n)), copyout(yacc(1:n))
    do i = 1, n
        yacc(i) = a*x(i) + y(i)
    end do
    !$acc end kernels

    ! Calculate the maximum difference
    m = -1.0
    !$omp parallel do private(tmp) reduction(max:m)
    do i = 1, n
        tmp = abs((yacc(i) - yomp(i)) / yomp(i))
        if (tmp > m) m = tmp
    end do

    ! Check if the operation was successful
    call testSuccess(m)

    ! Deallocate the arrays
    deallocate(x, y, yomp, yacc)
end program main

subroutine testSuccess(m)
    real(8), intent(in) :: m
    if (m < 1E-12) then
        print *, "Test Success: m meets the criterion."
    else
        print *, "Test Failure: m does not meet the criterion."
    endif
end subroutine testSuccess