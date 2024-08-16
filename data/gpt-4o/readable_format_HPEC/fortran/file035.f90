program DRB151_missinglock3_orig_gpu_yes
    use omp_lib
    implicit none

    integer :: var, i

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute parallel do
    do i = 1, 100
        var = var+1
    end do
    !$omp end teams distribute parallel do
    !$omp end target

    print*, var
end program
