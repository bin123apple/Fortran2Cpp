program DRB154_missinglock3_orig_gpu_no
    use omp_lib
    implicit none

    integer (kind=omp_lock_kind) :: lck
    integer :: var, i
    var = 0

    call omp_init_lock (lck)

    !$omp target map(tofrom:var) device(0)
    !$omp teams distribute reduction(+:var)
    do i = 1, 100
        call omp_set_lock(lck)
        var = var+1
        call omp_unset_lock(lck)
    end do
    !$omp end teams distribute
    !$omp end target

    call omp_destroy_lock(lck)

    print*, var
end program
