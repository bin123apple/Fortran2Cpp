program main
    implicit none
    character(len=1) :: c = ' '
    call checkString(c)
contains
    subroutine checkString(c)
        character(len=1), intent(in) :: c
        if (c == ' ') then
            print *, "Empty String"
        else
            print *, "Non-Empty String"
        end if
    end subroutine checkString
end program main