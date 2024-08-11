module mymod
    implicit none

    type :: t
        integer :: val
    contains
        procedure :: set_value
        procedure :: get_value
    end type t

contains

    subroutine set_value(this, value)
        class(t), intent(inout) :: this
        integer, intent(in) :: value

        this%val = value
    end subroutine set_value

    function get_value(this) result(value)
        class(t), intent(in) :: this
        integer :: value

        value = this%val
    end function get_value

end module mymod

program test_program
    use mymod
    type(t) :: x, y

    call x%set_value(42)
    print *, 'Value set in x: ', x%get_value()
    y = x
    print *, 'Value in y after assignment from x: ', y%get_value()
end program test_program