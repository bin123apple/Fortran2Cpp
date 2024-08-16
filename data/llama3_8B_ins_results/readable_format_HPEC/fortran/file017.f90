program DRB144_atomiccritical_orig_gpu_yes
    use omp_lib
    implicit none

    integer :: var, i
    var = 0

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute parallel do
        do i = 1, 200
            !$omp critical
            var = var+1
            !$omp end critical
        end do
    !$omp end teams distribute parallel do
    !$omp end target

    print*,var
end program
