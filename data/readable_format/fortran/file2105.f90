program volatile_doctest
    implicit none
    integer :: n
    character(len=32) :: formatted_string

    n = 1
    call int_to_string(n, formatted_string)
    print *, "Formatted string:", formatted_string

contains

    subroutine int_to_string(num, str)
        integer, intent(in) :: num
        character(len=*), intent(out) :: str

        write(str, '(I0)') num
    end subroutine int_to_string

end program volatile_doctest