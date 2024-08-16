program DRB082_declared_in_func_orig_yes
    use omp_lib
    use global_foo
    implicit none

    !$omp parallel
    call foo()
    !$omp end parallel
end program
