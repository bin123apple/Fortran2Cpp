program vla_tests
    implicit none
    real, allocatable :: vla1 (:)
    real, target, allocatable :: vla2(:, :)
    real, pointer :: pvla2 (:, :)
    logical :: l

    ! Test 1: Allocation and deallocation of vla1
    allocate (vla1 (5))
    if (.not. allocated(vla1)) then
        print *, "Test 1a Failed: vla1 not allocated"
    else
        print *, "Test 1a Passed"
    end if

    deallocate (vla1)
    if (allocated(vla1)) then
        print *, "Test 1b Failed: vla1 not deallocated"
    else
        print *, "Test 1b Passed"
    end if

    ! Test 2: Pointer association and disassociation
    allocate (vla2 (5, 2))
    pvla2 => vla2
    
    if (.not. associated(pvla2)) then
        print *, "Test 2a Failed: pvla2 not associated with vla2"
    else
        print *, "Test 2a Passed"
    end if

    pvla2 => null()
    if (associated(pvla2)) then
        print *, "Test 2b Failed: pvla2 still associated after nullify"
    else
        print *, "Test 2b Passed"
    end if

end program vla_tests