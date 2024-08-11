program testMod
    ! Variables
    integer :: result, expected

    ! Perform the modulus operation
    result = mod(13, 5)
    expected = 3

    ! Unit test for mod(13, 5)
    if (result == expected) then
        print *, "Test passed: mod(13, 5) == ", expected
    else
        print *, "Test failed: mod(13, 5) != ", expected, ", got ", result
    end if

end program testMod