program DRB027_taskdependmissing_orig_yes
    use omp_lib
    implicit none

    integer :: i
    i=0

    !$omp parallel
    !$omp single
    !$omp task
    i = 1
    !$omp end task
    !$omp task
    i = 2
    !$omp end task
    !$omp end single
    !$omp end parallel

    print 100, i
    100 format ("i=",i3)

end program
