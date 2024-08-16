program DRB142_acquirerelease_orig_yes
    use omp_lib
    implicit none

    integer :: x, y, thrd
    integer :: tmp
    x = 0

    !$omp parallel num_threads(2) private(thrd) private(tmp)
        thrd = omp_get_thread_num()
        if (thrd == 0) then
            !$omp critical
            x = 10
            !$omp end critical
            !$omp atomic write
            y = 1
            !$omp end atomic
        else
            tmp = 0
            do while(tmp == 0)
            !$omp atomic read acquire ! or seq_cst
            tmp = x
            !$omp end atomic
            end do
            !$omp critical
            print *, "x = ", x
            !$omp end critical
        end if
    !$omp end parallel
end program
