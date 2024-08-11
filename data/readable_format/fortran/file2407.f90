program test_logical_operations
    implicit none
    logical :: la, lb

    ! Test case 1: la and lb are both true
    la = .true.
    lb = .true.
    print *, "Test case 1: la and lb are both TRUE"
    call perform_test(la, lb)

    ! Test case 2: la is true, lb is false
    la = .true.
    lb = .false.
    print *, "Test case 2: la is TRUE, lb is FALSE"
    call perform_test(la, lb)

contains

    subroutine perform_test(la, lb)
        logical, intent(in) :: la, lb

        if (la .eqv. lb) then
            print *, "la .eqv. lb is true"
        endif
        if (la .neqv. lb) then
            print *, "la .neqv. lb is true"
        endif
        if (la .and. lb) then
            print *, "la .and. lb is true"
        endif
        if (la .or. lb) then
            print *, "la .or. lb is true"
        endif
        if (.not. la) then
            print *, ".not. la is true"
        endif
    end subroutine perform_test

end program test_logical_operations