program test_set_null
    use iso_c_binding, only : c_ptr, c_associated, c_null_ptr
    implicit none

    type(c_ptr) :: myPtr

    ! Subroutine included directly in the program
    call set_null(myPtr)

    if (.not. c_associated(myPtr)) then
        print *, "Test passed: Pointer is null."
    else
        print *, "Test failed: Pointer is not null."
    end if

contains

    subroutine set_null(ptr)
        type(c_ptr), intent(out) :: ptr
        ptr = c_null_ptr
    end subroutine set_null

end program test_set_null