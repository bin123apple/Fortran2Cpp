program test_ampersands
    implicit none
    character(len=70) :: str
    logical :: test_passed

    ! Test case 1: Expected to pass
    str = 'Print rather a lot of ampersands &&&&&' // &
         '&&&&&' // &
         '&&&&&'
    call perform_test(str, .true.)

    ! Test case 2: Expected to fail (wrong content)
    str = 'This string is definitely not the right length.'
    call perform_test(str, .false.)

contains

    subroutine perform_test(str, expected)
        character(len=*), intent(in) :: str
        logical, intent(in) :: expected
        logical :: result
        
        result = (len(trim(str)) == 44 .and. str == 'Print rather a lot of ampersands &&&&&&&&&&&')
        if (result .eqv. expected) then
            print *, "Test passed: T"
        else
            print *, "Test passed: F"
        end if
    end subroutine perform_test

end program test_ampersands