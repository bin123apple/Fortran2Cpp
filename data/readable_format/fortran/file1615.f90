module types
    implicit none
    type :: x
        integer, pointer :: i => null()
    end type x
contains
    subroutine test_pointer_not_associated(y)
        type(x), intent(in) :: y
        if (.not. associated(y%i)) then
            print *, "Test 1 - Pointer not associated: Passed"
        else
            print *, "Test 1 - Pointer not associated: Failed"
        end if
    end subroutine test_pointer_not_associated

    subroutine test_pointer_associated(z)
        type(x), intent(in) :: z
        if (associated(z%i)) then
            print *, "Test 2 - Pointer associated: Passed"
        else
            print *, "Test 2 - Pointer associated: Failed"
        end if
    end subroutine test_pointer_associated
end module types

program test_program
    use types
    implicit none
    type(x) :: y
    type(x) :: z
    integer, target :: a
    a = 10
    z%i => a

    ! Test when the pointer is not associated
    call test_pointer_not_associated(y)

    ! Test when the pointer is associated
    call test_pointer_associated(z)
end program test_program