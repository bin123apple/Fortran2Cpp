program DRB077_single_orig_no
    use omp_lib
    implicit none

    integer :: count
    count = 0

    !$omp parallel shared(count)
        !$omp single
        count = count + 1
        !$omp end single
    !$omp end parallel

    print 100, count
    100 format ('count =',i3)
end program
