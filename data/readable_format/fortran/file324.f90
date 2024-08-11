program pr42866_test
    implicit none
    integer, allocatable :: a(:)
    logical :: is_correct
    allocate (a(16))
    a = 0
    !$omp parallel
        !$omp sections reduction(+:a)
            a = a + 1
        !$omp section
            a = a + 2
        !$omp end sections
    !$omp end parallel

    is_correct = all(a == 3)
    if (.not. is_correct) then
        print *, "Test failed: Not all elements are 3."
        stop 1
    else
        print *, "Test passed: All elements are 3."
    endif

    deallocate (a)
end program pr42866_test