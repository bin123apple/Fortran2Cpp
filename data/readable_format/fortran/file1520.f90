module lock_test_module
    contains
    subroutine test_locks
        use omp_lib
        integer (kind = omp_nest_lock_kind) :: lock
        logical :: l

        l = .false.
        call omp_init_nest_lock(lock)
        if (omp_test_nest_lock(lock) .ne. 1) call abort
        if (omp_test_nest_lock(lock) .ne. 2) call abort
        !$omp parallel if (.false.) reduction (.or.:l)
        if (omp_test_nest_lock(lock) .ne. 0) l = .true.
        !$omp end parallel
        if (l) call abort
        if (omp_test_nest_lock(lock) .ne. 3) call abort
        call omp_unset_nest_lock(lock)
        call omp_unset_nest_lock(lock)
        call omp_unset_nest_lock(lock)
        call omp_destroy_nest_lock(lock)
    end subroutine test_locks
end module lock_test_module

program test
    use lock_test_module
    call test_locks
    print *, "Test passed."
end program test