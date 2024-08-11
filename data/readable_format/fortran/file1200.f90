! test_program.f90
program test
    implicit none
    real*8, dimension(1000000000) :: X
    real*8, dimension(1000000000) :: Y
    real*8, dimension(10) :: runtimes
    double precision t1, t2, meanruntimes
    integer i

    X(:) = 1.0
    Y(:) = 1.0
    call cpu_time(t1)
    X = X + Y + Y
    call cpu_time(t2)
    runtimes(1) = t2 - t1

    ! Simple assertion to check if runtime is recorded
    if (runtimes(1) <= 0.0) then
        print *, 'Test failed: Runtime should be positive.'
        stop
    else
        print *, 'Test passed: Runtime is positive.'
    endif
end program test