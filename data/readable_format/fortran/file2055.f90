program testTransfer
    implicit none
    integer :: intRepresentation
    character(1) :: charRepresentation
    ! Test 1: sqrt(100.0) transferred to integer
    print *, 'Test 1:'
    print *, transfer(sqrt([100.]), 0_1)
    ! Expected output is platform and implementation dependent

    ! Test 2: ASCII character represented by 100 transferred to integer
    print *, 'Test 2:'
    print *, transfer(achar([100]), 0_1)
    ! Expected output is 100

end program testTransfer