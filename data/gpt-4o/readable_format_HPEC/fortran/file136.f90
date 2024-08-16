program DRB118_nestlock_orig_no
    use omp_lib
    use DRB118
    implicit none

    integer :: a, b

    type(pair) :: p
    p%a = 0
    p%b = 0
    call omp_init_nest_lock(p%lck);

    !$omp parallel sections
    !$omp section
        call omp_set_nest_lock(p%lck)
        call incr_b(p, a)
        call incr_a(p, b)
        call omp_unset_nest_lock(p%lck)

    !$omp section
        call incr_b(p, b);

    !$omp end parallel sections

    call omp_destroy_nest_lock(p%lck)

    print*,p%b

end program
