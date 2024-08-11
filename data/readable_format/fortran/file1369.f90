module mymodule
    implicit none

    type :: t
        private
        integer :: value
    contains
        procedure, public :: set_value
        procedure, public :: get_value
    end type t

contains

    subroutine set_value(this, val)
        class(t), intent(inout) :: this
        integer, intent(in) :: val
        this%value = val
    end subroutine set_value

    function get_value(this) result(val)
        class(t), intent(in) :: this
        integer :: val
        val = this%value
    end function get_value

end module mymodule

program test
    use mymodule
    implicit none

    type(t), allocatable :: var

    ! Test
    allocate(var)
    call var%set_value(10)
    print *, var%get_value()  ! Expected output: 10

end program test