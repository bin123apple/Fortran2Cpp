subroutine dummy()
    integer i
end subroutine dummy

program testDummy
    call dummy()
    print *, 'dummy called successfully.'
end program testDummy