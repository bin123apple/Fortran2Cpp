module test_implementation
    ! Make 'i' a protected and public variable.
    integer, public, protected :: i

contains
    ! Procedure to set 'i'.
    subroutine set_i(value)
        integer, intent(in) :: value
        i = value
    end subroutine set_i

    ! Function to get 'i'.
    function get_i() result(res)
        integer :: res
        res = i
    end function get_i
end module test_implementation

program test_program
    use test_implementation
    implicit none

    ! Use the module's procedures to modify and access 'i'.
    call set_i(10)
    print *, "The value of 'i' is: ", get_i()

end program test_program