program DRB075_getthreadnum_orig_yes
    use omp_lib
    implicit none

    integer :: numThreads
    numThreads = 0

    !$omp parallel
    if ( omp_get_thread_num()==0 ) then
        numThreads = omp_get_num_threads();
    else
        print*,'numThreads =',numThreads
    end if
    !$omp endparallel
end program
