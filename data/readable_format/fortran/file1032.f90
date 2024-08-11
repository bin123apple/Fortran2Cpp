! test_m.f90
module m
    integer :: a
end module m

program test
    use m, local1 => a
    use m, local2 => a
    local1 = 5
    local2 = 3
    if (local1 == local2) then
        print *, "Test passed: local1 and local2 reference the same variable."
    else
        print *, "Test failed: local1 and local2 do not reference the same variable."
    end if
end program test