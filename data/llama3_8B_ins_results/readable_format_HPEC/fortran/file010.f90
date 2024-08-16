program DRB156_missingordered_orig_gpu_yes
    use omp_lib
    implicit none

    integer :: var(100)
    integer :: i

    do i = 1, 100
        var(i) = 1
    end do

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute parallel do
    do i = 2, 100
        var(i) = var(i-1)+1
    end do
    !$omp end teams distribute parallel do
    !$omp end target

    print*,var(100)
end program
