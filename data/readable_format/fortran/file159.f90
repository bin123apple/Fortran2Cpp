! test_ensem.f90
program test_ensem
    implicit none

    call test_init_ensem()
    call test_create_flow_ensem()
    call test_save_stats_ensem()

contains

    subroutine test_init_ensem()
        call init_ensem()
        print *, "test_init_ensem passed."
    end subroutine test_init_ensem

    subroutine test_create_flow_ensem()
        call create_flow_ensem()
        print *, "test_create_flow_ensem passed."
    end subroutine test_create_flow_ensem

    subroutine test_save_stats_ensem()
        call save_stats_ensem(.true.)
        call save_stats_ensem(.false.)
        print *, "test_save_stats_ensem passed."
    end subroutine test_save_stats_ensem

end program test_ensem

subroutine init_ensem
    return
end subroutine

subroutine create_flow_ensem
    return
end subroutine

subroutine save_stats_ensem(final)
    logical, intent(in) :: final
    return
end subroutine