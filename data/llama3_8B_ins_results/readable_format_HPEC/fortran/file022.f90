program DRB157_missingorderedsimd_orig_gpu_yes
    use omp_lib
    implicit none

    integer :: var(100)
    integer :: i

    do i = 1, 100
        var(i) = 1
    end do

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute parallel do simd safelen(16)
    do i = 17, 100
        var(i) = var(i-16)+1
    end do
    !$omp end teams distribute parallel do simd
    !$omp end target

    print*,var(98)
end program
