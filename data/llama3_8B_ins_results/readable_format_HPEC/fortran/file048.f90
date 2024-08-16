program DRB152_missinglock2_orig_gpu_no
    use omp_lib
    implicit none

    integer (kind=omp_lock_kind) :: lck
    integer :: var, i
    var = 0

    !$omp target map(tofrom:var) device(0)
    !$omp teams num_teams(1)
    !$omp distribute parallel do
    do i = 1, 100
        call omp_set_lock(lck)
        var = var+1
        call omp_unset_lock(lck)
    end do
    !$omp end distribute parallel do
    !$omp end teams
    !$omp end target
end program
