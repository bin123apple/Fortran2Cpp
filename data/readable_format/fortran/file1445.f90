program reduction_test
    use openacc
    implicit none
    integer, parameter :: n = 10
    integer :: s1, s2, device_type

    print *, "Fortran Test Begins"

    s1 = 0
    s2 = 0

    !$acc parallel reduction(+:s1, s2) num_gangs(n)
    s1 = s1 + 1
    s2 = s2 + 1
    !$acc end parallel

    device_type = acc_get_device_type()

    ! After the parallel region
    if (device_type == acc_device_nvidia) then
        if (s1 /= n .or. s2 /= n) then
            print *, "Parallel Region Test (NVIDIA): Failed"
        else
            print *, "Parallel Region Test (NVIDIA): Passed"
        endif
    else
        if (s1 /= n .or. s2 /= n) then
            print *, "Parallel Region Test (Non-NVIDIA): Failed"
        else
            print *, "Parallel Region Test (Non-NVIDIA): Passed"
        endif
    endif

    ! Reset s1 and s2
    s1 = 0
    s2 = 0
    call redsub(s1, s2, n)

    ! After calling redsub
    if (device_type == acc_device_nvidia) then
        if (s1 /= n .or. s2 /= n) then
            print *, "Subroutine Test (NVIDIA): Failed"
        else
            print *, "Subroutine Test (NVIDIA): Passed"
        endif
    else
        if (s1 /= n .or. s2 /= n) then
            print *, "Subroutine Test (Non-NVIDIA): Failed"
        else
            print *, "Subroutine Test (Non-NVIDIA): Passed"
        endif
    endif

    print *, "Fortran Test Ends"
end program reduction_test

subroutine redsub(s1, s2, n)
    implicit none
    integer :: s1, s2, n

    !$acc parallel reduction(+:s1, s2) num_gangs(n)
    s1 = s1 + 1
    s2 = s2 + 1
    !$acc end parallel
end subroutine redsub