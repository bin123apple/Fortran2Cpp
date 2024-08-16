program DRB079_taskdep3_orig_no
    use omp_lib
    implicit none

    integer :: i, j, k
    i = 0

    !$omp parallel
        !$omp single
            !$omp task depend (out:i)
                call sleep(3)
                i = 1
            !$omp end task
            !$omp task depend (in:i)
                j = i
            !$omp end task
            !$omp task depend (in:i)
                k = i
            !$omp end task
        !$omp end single
    !$omp end parallel

    print 100, j, k
    100 format ('j =',i3,2x,'k =',i3)

    if (j /= 1 .and. k /= 1) then
        print*, 'Race Condition'
    end if

end program
