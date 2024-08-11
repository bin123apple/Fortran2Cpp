module overwrite
    implicit none
    type :: parent
    contains
        procedure :: sum => sum_parent
        generic   :: operator(+) => sum
    end type parent

    type, extends(parent) :: child
    contains
        procedure :: sum => sum_child
    end type child

contains

    integer function sum_parent(this, other)
        class(parent), intent(in) :: this
        class(parent), intent(in) :: other
        sum_parent = 0
    end function sum_parent

    integer function sum_child(this, other)
        class(child), intent(in) :: this
        class(parent), intent(in) :: other
        sum_child = 1
    end function sum_child

end module overwrite

program test_program
    use overwrite
    implicit none

    type(parent) :: m1, m2
    type(child) :: h1, h2

    call test_parent_addition(m1, m2)
    call test_child_parent_addition(h1, m2)
    call test_child_sum_method(h1, h2)

contains

    subroutine test_parent_addition(m1, m2)
        type(parent), intent(in) :: m1, m2

        if (m1 + m2 /= 0) then
            print *, "Test parent addition failed."
        else
            print *, "Test parent addition passed."
        end if
    end subroutine test_parent_addition

    subroutine test_child_parent_addition(h1, m2)
        type(child), intent(in) :: h1
        type(parent), intent(in) :: m2

        if (h1 + m2 /= 1) then
            print *, "Test child-parent addition failed."
        else
            print *, "Test child-parent addition passed."
        end if
    end subroutine test_child_parent_addition

    subroutine test_child_sum_method(h1, h2)
        type(child), intent(in) :: h1, h2

        if (h1%sum(h2) /= 1) then
            print *, "Test child sum method failed."
        else
            print *, "Test child sum method passed."
        end if
    end subroutine test_child_sum_method

end program test_program