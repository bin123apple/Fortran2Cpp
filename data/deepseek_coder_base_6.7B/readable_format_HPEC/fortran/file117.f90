program DRB072_taskdep1_orig_no
    use omp_lib
    implicit none

    integer :: i
    i = 0

    !$omp parallel
        !$omp single
            !$omp task depend (out:i)
            i = 1
            !$omp end task
            !$omp task depend (in:i)
            i = 2
            !$omp end task
        !$omp end single
    !$omp end parallel

    if (i/=2) then
        print*,'i is not equal to 2'
    end if
end program
