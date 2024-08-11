program test_nitems
    implicit none

    print *, 'Testing nitems function'
    call test_case('apple, orange, banana, peach', 4)
    call test_case('  ', 0)
    call test_case('apple orange banana', 3)
    call test_case('', 0)
    call test_case(' , , ,', 0)
    call test_case('apple,orange,banana,peach', 4)
    call test_case('    apple orange    banana   peach  ', 4)

contains

    function nitems(line) result(number)
        implicit none
        character(*), intent(in) :: line
        integer :: number
        integer :: icount, lineLen, icmax
        lineLen = len(trim(line))
        number = 0
        icount = 0
        icmax = len(trim(line))
        icloop: do
            icount = icount + 1
            if (icount > lineLen) exit icloop
            if (line(icount:icount) /= ' ' .and. line(icount:icount) /= ',') then
                number = number + 1
                ic2loop: do
                    icount = icount + 1
                    if (icount >= icmax) exit icloop
                    if (line(icount:icount) == ' ' .or. line(icount:icount) == ',') exit ic2loop
                end do ic2loop
            end if
        end do icloop
    end function nitems

    subroutine test_case(testString, expected)
        character(*), intent(in) :: testString
        integer, intent(in) :: expected
        integer :: result

        result = nitems(testString)
        print *, 'Test "', trim(testString), '": ', result, ' (Expected: ', expected, ')'
        if (result == expected) then
            print *, '    Test passed.'
        else
            print *, '    Test failed.'
        end if
    end subroutine test_case

end program test_nitems