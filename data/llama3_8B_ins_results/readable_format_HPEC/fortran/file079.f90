program DRB161_nolocksimd_orig_gpu_yes
    use omp_lib
    implicit none

    integer :: var(8)
    integer :: i, j

    do i = 1, 8
        var(i) = 0
    end do

    !$omp target map(tofrom:var) device(0)
    !$omp teams num_teams(1) thread_limit(1048)
    !$omp distribute parallel do
    do i = 1, 20
        !$omp simd
        do j = 1, 8
            var(j) = var(j)+1
        end do
        !$omp end simd
    end do
    !$omp end distribute parallel do
    !$omp end teams
    !$omp end target

    print*,var(8)
end program
