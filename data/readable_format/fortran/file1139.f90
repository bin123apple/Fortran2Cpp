module iso_varying_string
    implicit none
    integer, parameter :: GET_BUFFER_LEN = 256
    type varying_string
        character(LEN=1), dimension(:), allocatable :: chars
    end type varying_string
    interface assignment(=)
        module procedure op_assign_VS_CH
    end interface assignment(=)
contains
    elemental subroutine op_assign_VS_CH (var, expr)
        type(varying_string), intent(out) :: var
        character(LEN=*), intent(in) :: expr
        var = var_str(expr)
    end subroutine op_assign_VS_CH
    elemental function var_str (chr) result (string)
        character(LEN=*), intent(in) :: chr
        type(varying_string) :: string
        integer :: length
        integer :: i_char
        length = LEN(chr)
        ALLOCATE(string%chars(length))
        forall(i_char = 1:length)
            string%chars(i_char) = chr(i_char:i_char)
        end forall
    end function var_str
end module iso_varying_string

program VST_2
    use iso_varying_string
    implicit none
    CHARACTER(LEN=5) :: char_arb(2)
    CHARACTER(LEN=1) :: char_elm(10)
    equivalence (char_arb, char_elm)
    type(varying_string) :: str_ara(2)

    char_arb(1) = "Hello"
    char_arb(2) = "World"
    str_ara = char_arb
    
    if (any(str_ara(1)%chars(1:5) /= char_elm(1:5))) stop 1
    if (any(str_ara(2)%chars(1:5) /= char_elm(6:10))) stop 2

    print *, "All tests passed successfully."
end program VST_2