program DRB148_critical1_orig_gpu_yes
    use omp_lib
    implicit none

    integer :: var, i
    var = 0

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute parallel do
    do i = 1, 100
        !$omp critical(addlock)
        var = var+1
        !$omp end critical(addlock)
    end do
    !$omp end teams distribute parallel do
    !$omp end target

    print*,var
end program
