program DRB051_getthreadnum_orig_no
    use omp_lib
    implicit none

    integer :: numThreads

    !$omp parallel
    if (omp_get_thread_num() == 0) then
        numThreads = omp_get_num_threads()
    end if
    !$omp end parallel

    print 100, numThreads
    100 format ('numThreads =',i3)
end program
