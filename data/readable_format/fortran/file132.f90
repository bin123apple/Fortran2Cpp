! TestInquireTest.f90
program TestInquireTest
    implicit none
    integer(8) :: iUnit
    integer(8) :: iPos
    logical :: testPassed

    open(newunit=iunit, file='output.txt', access='stream', status='replace')
    write(iUnit) 'TEXT'
    inquire(iUnit, pos=iPos)
    close(iUnit, status='delete')

    testPassed = .TRUE.
    if (iPos /= 5) then
        print *, "Test FAILED: Expected position 5, but got ", iPos
        testPassed = .FALSE.
    end if

    if (testPassed) then
        print *, "Test PASSED"
    end if
end program TestInquireTest