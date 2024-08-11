program testFortranCode
implicit none

integer :: result

! Running the test procedure
result = testLogic()
if (result /= 0) then
    print *, "Test failed with error code:", result
else
    print *, "All tests passed successfully."
end if

contains

    function testLogic() result(res)
    implicit none
    integer :: res

    logical :: trueVal, falseVal
    character(len=10) :: b
    trueVal = .TRUE.
    falseVal = .FALSE.

    b = ''
    write (b, '(L1)') trueVal
    if (b(1:1) .ne. 'T') then
        res = 1
        return
    end if

    b = ''
    write (b, '(L1)') falseVal
    if (b(1:1) .ne. 'F') then
        res = 2
        return
    end if

    b = ''
    write(b, '(L4)') trueVal
    if (b(1:4) .ne. '   T') then
        res = 3
        return
    end if

    b = ''
    write(b, '(L4)') falseVal
    if (b(1:4) .ne. '   F') then
        res = 4
        return
    end if

    res = 0

    end function testLogic

end program testFortranCode