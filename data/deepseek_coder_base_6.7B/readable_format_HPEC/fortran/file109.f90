program DRB153_missinglock2_orig_gpu_yes
    use omp_lib
    implicit none

    integer :: var, i
    var = 0

    !$omp target map(tofrom:var) device(0)
    !$omp teams num_teams(1)
        !$omp distribute parallel do
        do i = 1, 100
            var = var + 1
        end do
        !$omp end distribute parallel do
    !$omp end teams
    !$omp end target

    print*, var
end program
