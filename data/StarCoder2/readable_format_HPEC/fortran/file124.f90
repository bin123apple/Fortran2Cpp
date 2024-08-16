program DRB083_declared_in_func_orig_no
    use omp_lib
    use DRB083
    implicit none

    !$omp parallel
    call foo()
    !$omp end parallel
end program
